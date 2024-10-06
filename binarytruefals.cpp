#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int checkHeight(TreeNode* root)
{
	if (root == nullptr) return 0;

	int leftHeight = checkHeight(root->left);
	if (leftHeight == -1) return -1;

	int rightHeight = checkHeight(root->right);
	if (rightHeight == -1) return -1;
	if (abs(leftHeight - rightHeight) > 1) return -1;
	return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode* root)
{
	return checkHeight(root) != -1;
}

int main()
{
	TreeNode* root1 = new TreeNode(3);
	root1->left = new TreeNode(9);
	root1->right = new TreeNode(20);
	root1->right->left = new TreeNode(15);
	root1->right->right = new TreeNode(7);
	cout << (isBalanced(root1) ? "true" : "false") << endl;
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(2);
	root2->left->left = new TreeNode(3);
	root2->left->right = new TreeNode(3);
	root2->left->left->left = new TreeNode(4);
	root2->left->left->right = new TreeNode(4);
	cout << (isBalanced(root2) ? "true" : "false") << endl;
	TreeNode* root3 = nullptr;
	cout << (isBalanced(root3) ? "true" : "false") << endl;

	return 0;
}
