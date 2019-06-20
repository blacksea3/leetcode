#include "BinaryTree.h"

//4ms, 95.29%

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
	int sum = 0;
	void iter_sumNumbres(TreeNode* root, const int& pre)
	{
		if (!root) return;
		else
		{
			int now = 10 * pre + root->val;
			if ((root->left == nullptr) && (root->right == nullptr))
			{
				sum += now;
				return;
			}
			else
			{
				iter_sumNumbres(root->left, now);
				iter_sumNumbres(root->right, now);
			}
		}
	}

public:
	int sumNumbers(TreeNode* root) {
		//ตÝน้
		iter_sumNumbres(root, 0);
		return sum;
	}
};