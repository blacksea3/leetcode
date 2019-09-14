#include "BinaryTree.h"

//24ms, 93.08%
//分治, 递归写法
//左子树是比当前值小的, 右子树是比当前值大的

class Solution {
private:
	vector<TreeNode*> DCgenTrees(int n, int m)
	{
		if (n > m) return { nullptr };
		if (n == m)
		{
			return vector<TreeNode*> {new TreeNode(n)};
		}
		else
		{
			vector<TreeNode*> res;
			for (int i = n; i <= m; i++)
			{
				vector<TreeNode*> leftsons = DCgenTrees(n, i - 1);
				vector<TreeNode*> rightsons = DCgenTrees(i + 1, m);
				for (auto left : leftsons)
					for (auto right : rightsons)
					{
						TreeNode* bothside = new TreeNode(i);
						bothside->left = left;
						bothside->right = right;
						res.emplace_back(bothside);
					}
			}
			return res;
		}
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0) return vector<TreeNode*> {};

		return DCgenTrees(1, n);
	}
};


