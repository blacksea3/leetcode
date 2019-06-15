#include "BinaryTree.h"

//4ms£¬ 97.74%
//level order traverse, half reverse, use one stack to store pretreenodes

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr) return vector<vector<int>> {};

		stack<TreeNode*> pre;
		stack<TreeNode*> next;

		vector<vector<int>> total_res;
		vector<int> pre_res;
		bool isreverse = false;

		pre.push(root);

		while (!pre.empty())
		{
			pre_res.clear();
			if (!isreverse)
			{
				while (!pre.empty())
				{
					TreeNode* temp = pre.top();
					pre.pop();
					pre_res.push_back(temp->val);
					if (temp->left) next.push(temp->left);
					if (temp->right) next.push(temp->right);
				}
			}
			else
			{
				while (!pre.empty())
				{
					TreeNode* temp = pre.top();
					pre.pop();
					pre_res.push_back(temp->val);
					if (temp->right) next.push(temp->right);
					if (temp->left) next.push(temp->left);
				}
			}
			swap(next, pre);
			total_res.push_back(pre_res);
			isreverse = !isreverse;
		}
		return total_res;
	}
};
