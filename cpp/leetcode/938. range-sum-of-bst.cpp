#include "BinaryTree.h"

//172ms, 94.65%
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
	int gblL;
	int gblR;
	int res = 0;

	void DFS(TreeNode* root)
	{
		if (!root) return;
		if (root->val >= gblL && root->val <= gblR)
		{
			res += root->val;
		}
		DFS(root->left);
		DFS(root-> right);
	}


public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		gblL = L;
		gblR = R;
		DFS(root);
		return res;
	}
};
