#include "BinaryTree.h"

//92ms, 25.45%
//ÀàËÆ¶þ·ÖËÑË÷

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
	TreeNode* recu(TreeNode* root, int val)
	{
		if (!root) return nullptr;
		else if (root->val == val) return root;
		else if (root->val < val) return recu(root->right, val);
		else return recu(root->left, val);
	}


public:
	TreeNode* searchBST(TreeNode* root, int val) {
		return recu(root, val);
	}
};
