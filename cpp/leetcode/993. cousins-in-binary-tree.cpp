#include "BinaryTree.h"

//8ms, 74.79%
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
	int d1, d2; //深度
	int p1, p2; //父节点值
	void DFS(TreeNode* root, int x, int y, int pval, int depth)
	{
		if (!root) return;

		if (root->val == x)
		{
			d1 = depth;
			p1 = pval;
		}
		else if (root->val == y)
		{
			d2 = depth;
			p2 = pval;
		}
		DFS(root->left, x, y, root->val, depth + 1);
		DFS(root->right, x, y, root->val, depth + 1);
	}



public:
	bool isCousins(TreeNode* root, int x, int y) {
		d1 = -1;
		d2 = -1;
		p1 = -999;
		p2 = -999;

		DFS(root, x, y, -1, 0);
		return ((d1 == d2) && (p1 != p2)) ? true : false;
	}
};
