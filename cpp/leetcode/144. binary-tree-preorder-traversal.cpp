#include "BinaryTree.h"

//4ms, 94.12%

//µü´ú

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
public:
	vector<int> preorderTraversal(TreeNode* root) {
		//µü´ú
		vector<int> res = {};
		if (root == nullptr) return res;
		stack<TreeNode*> dfs;
		TreeNode* pre = root;

		while (!dfs.empty() || pre)
		{
			if (pre)
			{
				res.push_back(pre->val);
				dfs.push(pre);
				pre = pre->left;
			}
			else
			{
				pre = dfs.top();
				pre = pre->right;
				dfs.pop();
			}
		}
		return res;
	}
};