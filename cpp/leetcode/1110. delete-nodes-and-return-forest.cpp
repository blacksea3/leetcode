#include "BinaryTree.h"

//44ms, 54.63%
//DFSµÝ¹é

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
	vector<TreeNode*> res;
	unordered_set<int> us_delete;
	TreeNode* recursive(TreeNode* root)
	{
		if (!root) return root;

		TreeNode* left = recursive(root->left);
		TreeNode* right = recursive(root->right);

		root->left = left;
		root->right = right;

		if (us_delete.find(root->val) != us_delete.end())
		{
			us_delete.erase(root->val);
			if (left) res.push_back(left);
			if (right) res.push_back(right);
			return nullptr;
		}
		else
		{
			return root;
		}
	}

public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> temp(to_delete.begin(), to_delete.end());
		us_delete = temp;
		TreeNode* rootres = recursive(root);
		if (rootres) res.push_back(rootres);
		return res;
	}
};
