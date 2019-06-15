#include "BinaryTree.h"

//recursively, 20ms, 94.01%

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
	vector<vector<int>> res = {};
	vector<int> pre = {};
	void recu_pathSum(TreeNode* root, int sum)
	{
		if (root == nullptr) return;
		else if ((root->left == nullptr) && (root->right == nullptr))
		{
			if (sum == root->val)
			{
				pre.push_back(root->val);
				res.push_back(pre);
				pre.pop_back();
			}
		}
		else
		{
			pre.push_back(root->val);
			recu_pathSum(root->left, sum - root->val);
			recu_pathSum(root->right, sum - root->val);
			pre.pop_back();
		}
	}

public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		recu_pathSum(root, sum);
		return res;
	}
};