#include <stdio.h>
#include <limits.h>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode* newNode(int val)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int maxPathSumHelper(struct TreeNode* root, int* maxSum)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = max(0, maxPathSumHelper(root->left, maxSum));
	int right = max(0, maxPathSumHelper(root->right, maxSum));
	*maxSum = max(*maxSum, left + right + root->val);
	return max(left, right) + root->val;
}
int maxPathSum(struct TreeNode* root)
{
	int maxSum = INT_MIN;
	maxPathSumHelper(root, &maxSum);
	return maxSum;
}
int main()
{
	struct TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	printf("Maximum Path Sum: %d\n", maxPathSum(root));
	return 0;
}
