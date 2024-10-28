#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int key;
	struct Node *left, *right;
};
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}
struct Node* insert(struct Node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}
struct Node* minValueNode(struct Node* node)
{
	struct Node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct Node* deleteNode(struct Node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}

	return root;
}
void preOrder(struct Node* root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(struct Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}
void postOrder(struct Node* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}

int main()
{
	struct Node* root = NULL;

	int choice, value;

	while (1)
	{
		printf("\n1. Insert\n2. Delete\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter value to insert: ");
			scanf("%d", &value);
			root = insert(root, value);
			break;

		case 2:
			printf("Enter value to delete: ");
			scanf("%d", &value);
			root = deleteNode(root, value);
			break;

		case 3:
			printf("Preorder traversal: ");
			preOrder(root);
			printf("\n");
			break;

		case 4:
			printf("Inorder traversal: ");
			inOrder(root);
			printf("\n");
			break;

		case 5:
			printf("Postorder traversal: ");
			postOrder(root);
			printf("\n");
			break;

		case 6:
			exit(0);
		default:
			printf("Invalid choice!\n");
		}
	}

	return 0;
}
