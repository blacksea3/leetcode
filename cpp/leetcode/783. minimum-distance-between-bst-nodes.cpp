#include "BinaryTree.h"

//8ms, 57.77%
//DFS全部访问一遍

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
	vector<int> v;
	void DFS(TreeNode* root)
	{
		if (!root) return;
		else
		{
			v.push_back(root->val);
			DFS(root->left);
			DFS(root->right);
		}
	}


public:
	int minDiffInBST(TreeNode* root) {
		DFS(root);
		sort(v.begin(), v.end());
		int res = INT_MAX;
		for (int i = 0; i < v.size() - 1; ++i)
		{
			res = min(res, v[i + 1] - v[i]);
		}
		return res;
	}
};
