#include "BinaryTree.h"

//52ms, 23.00%
//无序map记录频次
//左右中遍历, DFS

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
	unordered_map<int, int> count;

	//返回子树和
	int DFS(TreeNode* root)
	{
		if (!root) return 0;
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			int preSonSum = left + right + root->val;
			count[preSonSum]++;
			return preSonSum;
		}
	}

public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		DFS(root);

		vector<int> res;
		int maxCount = INT_MIN;
		for (auto& c : count)
		{
			if (c.second > maxCount)
			{
				res.clear();
				res.push_back(c.first);
				maxCount = c.second;
			}
			else if (c.second == maxCount)
			{
				res.push_back(c.first);
			}
		}
		return res;
	}
};
