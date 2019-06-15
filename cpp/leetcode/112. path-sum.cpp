#include "BinaryTree.h"

//recursively, 16ms, 94.37%
//use flag to cut off the remaining routes!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	bool flag = false;
	void recu_hasPathSum(TreeNode* root, int sum)
	{
		if ((flag) || (root == nullptr)) return;
		else if ((root->left == nullptr) && (root->right == nullptr))
		{
			if (sum == root->val) flag = true;
		}
		else
		{
			recu_hasPathSum(root->left, sum - root->val);
			recu_hasPathSum(root->right, sum - root->val);
		}
	}

public:
	bool hasPathSum(TreeNode* root, int sum) {
		recu_hasPathSum(root, sum);
		return flag;
	}
};