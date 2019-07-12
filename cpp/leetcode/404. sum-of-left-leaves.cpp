#include "BinaryTree.h"

//4ms, 93.05%
//easy but code is a little bit different
//DFS

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
	int res = 0;
	void recu_tree(TreeNode* root, bool isleft)
	{
		bool hasnode = false;
		if (root->left)
		{
			recu_tree(root->left, true);
			hasnode = true;
		}
		if (root->right)
		{
			recu_tree(root->right, false);
			hasnode = true;
		}
		if ((!hasnode) && isleft) res += root->val;
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root) recu_tree(root, false);
		return res;
	}
};
