#include "BinaryTree.h"

//56ms, 69,57%
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
	TreeNode* pre;

	void DFS(TreeNode* root)
	{
		if (!root) return;
		DFS(root->left);
		TreeNode* ne = new TreeNode(root->val);
		pre->right = ne;
		pre = ne;
		DFS(root->right);
	}

public:
	TreeNode* increasingBST(TreeNode* root) {
		TreeNode* dump = new TreeNode(-1);
		pre = dump;
		DFS(root);
		return dump->right;
	}
};
