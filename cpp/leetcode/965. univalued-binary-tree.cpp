#include "BinaryTree.h"

//4ms, 89.11%
//simple solution

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
	bool res = true;
	int val;
	void DFS(TreeNode* root)
	{
		if (!res || !root) return;
		if (root->val != val) res = false;
		DFS(root->left);
		DFS(root->right);
	}

public:
	bool isUnivalTree(TreeNode* root) {
		val = root->val;
		DFS(root->left);
		DFS(root->right);
		return res;
	}
};
