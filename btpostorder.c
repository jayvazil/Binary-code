#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void postorderTraversal(struct Node* node)
{
	if (node == NULL)
		return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	printf("%d ", node->data);
}

int main()
{
	struct Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	printf("Postorder Traversal: ");
	postorderTraversal(root);

	return 0;
}
