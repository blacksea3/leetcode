#include "BinaryTree.h"

//4ms, 84.43%
//前序遍历：中左右，迭代

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res = {};
		stack<TreeNode*> dfs;
		TreeNode* pre = root;

		while (!dfs.empty() || pre)
		{
			if (pre)
			{
				res.emplace_back(pre->val);
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
