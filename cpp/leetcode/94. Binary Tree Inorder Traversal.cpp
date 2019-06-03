#include "BinaryTree.h"

//4ms, 96.87%
//Simple algorithm, use stack

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res = {};
		stack<TreeNode*> ts;
		TreeNode* pre = root;
		while ((pre != nullptr) || !ts.empty())
		{
			if (pre != nullptr)
			{
				ts.push(pre);
				pre = pre->left;
			}
			else
			{
				//backtracking
				pre = ts.top();
				ts.pop();
				res.push_back(pre->val);
				pre = pre->right;
			}
		}
		return res;
	}
};