#include "BinaryTree.h"

//16ms, 93.08%
//recursively

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
				pre.emplace_back(root->val);
				res.emplace_back(pre);
				pre.pop_back();
			}
		}
		else
		{
			pre.emplace_back(root->val);
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
