#include "BinaryTree.h"

//DFS is just ok, 40ms, 98.76%

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
	void DFS(TreeNode* root)
	{
		if (!root) return;
		else
		{
			res++;
			DFS(root->left);
			DFS(root->right);
		}
	}

public:
	int countNodes(TreeNode* root) {
		DFS(root);
		return res;
	}
};
