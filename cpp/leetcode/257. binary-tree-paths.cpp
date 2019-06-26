#include "BinaryTree.h"

//8ms, 85.37%
//simple problem, DFS

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
	vector<string> res = {};
	void recu_bip(TreeNode* t, string pp)
	{
		pp += to_string(t->val);
		if (t->left)
		{
			if (t->right)
			{
				recu_bip(t->right, pp + "->");
			}
			recu_bip(t->left, pp + "->");
		}
		else if (t->right) recu_bip(t->right, pp + "->");
		else res.push_back(pp);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return res;
		recu_bip(root, "");
		return res;
	}
};
