#include "BinaryTree.h"

//level traverse, level traverse, use queue, 16ms, 86.30%

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr) return vector<vector<int>> {};

		queue<TreeNode*> pre;
		queue<TreeNode*> next;

		vector<vector<int>> total_res;
		vector<int> pre_res;

		bool ist1valid = true;

		pre.push(root);

		while (!pre.empty())
		{
			pre_res.clear();
			while (!pre.empty())
			{
				TreeNode* temp = pre.front();
				pre.pop();
				pre_res.push_back(temp->val);
				if (temp->left) next.push(temp->left);
				if (temp->right) next.push(temp->right);
			}
			total_res.insert(total_res.begin(), pre_res);
			swap(pre, next);
		}
		return total_res;
	}
};
