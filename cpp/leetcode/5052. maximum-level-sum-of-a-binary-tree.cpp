#include "BinaryTree.h"

//
//统计

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
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> res;

		q.push(root);

		while (!q.empty())
		{
			int thissum = 0;
			queue<TreeNode*> next;
			while (!q.empty())
			{
				TreeNode* pre = q.front();
				q.pop();
				thissum += pre->val;
				if (pre->left) next.push(pre->left);
				if (pre->right) next.push(pre->right);
			}
			res.push_back(thissum);
			q = next;
		}

		//找出最大的
		int maxsum = INT_MIN;
		int maxline = -1;

		for (int i = 0; i < res.size(); ++i)
		{
			if (res[i] > maxsum)
			{
				maxsum = res[i];
				maxline = i + 1;
			}
		}
		return maxline;
	}
};
