#include "BinaryTree.h"

//4ms, 94.05%

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
	vector<int> postorderTraversal(TreeNode* root) {
		//������,���ɷ�-�������:����-��-�����˳��

		vector<int> res = {};

		if (root == nullptr) return res;

		TreeNode* pre = root;
		stack<TreeNode*> dfs;

		while (!dfs.empty() || pre)
		{
			if (pre)
			{
				res.insert(res.begin(), pre->val);
				dfs.push(pre);
				pre = pre->right;
			}
			else
			{
				pre = dfs.top();
				dfs.pop();
				pre = pre->left;
			}
		}
		return res;
	}
};