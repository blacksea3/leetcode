#include "BinaryTree.h"

//0ms, 100.00%
//注意题目意思: 最终一定会每个节点一个硬币
//大概是需要求最少次数
//自底而上获取硬币, 缺就拿, 多就送

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

	int DFS(TreeNode* root)
	{
		if (!root->left && !root->right)
		{
			res += abs(root->val - 1);
			return root->val - 1; //多余的硬币数
		}
		else if (!root->right)
		{
			int left = DFS(root->left);
			res += abs(left + root->val - 1);
			return left + root->val - 1; //多余的硬币数
		}
		else if (!root->left)
		{
			int right = DFS(root->right);
			res += abs(right + root->val - 1);
			return right + root->val - 1; //多余的硬币数
		}
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			res += abs(left + right + root->val - 1);
			return left + right + root->val - 1; //多余的硬币数
		}
	}

public:
	int distributeCoins(TreeNode* root) {
		DFS(root);
		return res;
	}
};
