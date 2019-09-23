#include "BinaryTree.h"

//0ms, 100%
//倒过来，生成反-后序遍历，即中右左遍历
//迭代

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res = {};
		TreeNode* pre = root;
		stack<TreeNode*> dfs;

		while (!dfs.empty() || pre)
		{
			if (pre)
			{
				res.emplace_back(pre->val);
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
		reverse(res.begin(), res.end());
		return res;
	}
};
