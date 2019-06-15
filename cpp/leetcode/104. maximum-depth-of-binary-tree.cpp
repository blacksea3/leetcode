#include "BinaryTree.h"

//recursively, 16ms, 89.34%

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
	int recu_depth(TreeNode* root)
	{
		if (!root) return 0;
		else return 1 + max(recu_depth(root->left), recu_depth(root->right));
	}

public:
	int maxDepth(TreeNode* root) {
		return recu_depth(root);
	}
};