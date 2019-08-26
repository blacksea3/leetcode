#include "BinaryTree.h"

//24ms, 14.95%
//DFS
//拉一个大的vector<vector<pair<int, int>>> 外层大小为1999 表示可能的所有节点, 其中下标=真实横坐标+999, 内vector放置{深度, 实际节点值}
//然后内部排序, 外部去空

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
	void DFS(TreeNode* root, int depth, int x, vector<vector<pair<int, int>>>& v)
	{
		if (!root) return;
		v[x + 999].push_back({ depth, root->val });
		DFS(root->left, depth + 1, x - 1, v);
		DFS(root->right, depth + 1, x + 1, v);
	}

public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<pair<int, int>>> v(1999, vector<pair<int, int >>{});
		DFS(root, 0, 0, v);

		vector<vector<int>> res;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].empty()) continue;
			else
			{
				sort(v[i].begin(), v[i].end());
				vector<int> temp;
				for (int j = 0; j < v[i].size(); ++j)
				{
					temp.push_back(v[i][j].second);
				}
				res.push_back(temp);
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	auto res = s->verticalTraversal(stringToTreeNode("[3,9,20,null,null,15,7]"));
	return 0;
}
