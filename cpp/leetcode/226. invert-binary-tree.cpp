#include "BinaryTree.h"

//0ms, 100%
//�ݹ�

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		TreeNode*temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

