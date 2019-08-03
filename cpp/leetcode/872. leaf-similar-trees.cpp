#include "BinaryTree.h"

//4ms, 92.77%
//用vector保存叶子们
//左右中遍历

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
	vector<int> v1;
	vector<int> v2;
	void DFS1(TreeNode* root)
	{
		if (!root->left && !root->right)
		{
			v1.push_back(root->val);
		}
		else if (!root->left)
		{
			DFS1(root->right);
		}
		else if (!root->right)
		{
			DFS1(root->left);
		}
		else
		{
			DFS1(root->right);
			DFS1(root->left);
		}
	}

	void DFS2(TreeNode* root)
	{
		if (!root->left && !root->right)
		{
			v2.push_back(root->val);
		}
		else if (!root->left)
		{
			DFS2(root->right);
		}
		else if (!root->right)
		{
			DFS2(root->left);
		}
		else
		{
			DFS2(root->right);
			DFS2(root->left);
		}
	}

public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		DFS1(root1);
		DFS2(root2);

		return (v1 == v2);
	}
};

