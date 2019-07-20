#include "BinaryTree.h"

//36ms, 5.48%
//DFS+大整数取模

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
	int res = 0;
	//n%m , https://www.cnblogs.com/lfri/p/9614074.html
	int biginteger_mod(vector<int> n, int m)
	{
		int ans = 0;
		for (int i = 0; i < n.size(); ++i)
			ans = (int)(((long long)ans * 2 + n[i]) % m);
		return ans;
	}
	void DFS(TreeNode* root, vector<int> nums)
	{
		nums.push_back(root->val);
		if (root->left)
		{
			DFS(root->left, nums);
			if (root->right)
			{
				DFS(root->right, nums);
			}
		}
		else if (root->right)
		{
			DFS(root->right, nums);
		}
		else
		{
			res += biginteger_mod(nums, 1000000007);
		}
	}

public:
	int sumRootToLeaf(TreeNode* root) {
		DFS(root, {});
		return res;
	}
};
