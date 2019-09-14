#include "BinaryTree.h"

//recursively solve it, 16ms, 96.25%
// a trick: we can use a (global) flag to store the res, if one small tree is inbalanced,
//  then the total tree is inbalanced, we don't need to recursively all the total tree!

class Solution {
private:
	bool flag = true;
	int treeDepth(TreeNode * root)
	{
		if (root == nullptr) return 0;
		int left = treeDepth(root->left);
		int right = treeDepth(root->right);
		if (!flag) return 0;
		if (abs(left - right) > 1)
		{
			flag = false;
			return 0;
		}
		else return max(left, right) + 1;
	}

public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		int dump = treeDepth(root);
		return flag;
	}
};
