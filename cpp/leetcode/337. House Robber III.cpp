#include "BinaryTree.h"

//24ms, 95.57%

//use DFS
//in one recursive fun : we will have left[0],[1] means left son tree: contain/or not left root, right is similar
// then if contain pre root, the max value should be root->val + left[1] + right[1]
// if not contain pre root, the max valuee should be max(left[0], left[1]) + max(right[0], right[1])

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
	pair<int, int> recu_rob(TreeNode* root)
	{
		pair<int, int> returnval = { 0,0 };
		if (!root) return returnval;
		else
		{
			pair<int, int> left = recu_rob(root->left);
			pair<int, int> right = recu_rob(root->right);
			returnval.first = root->val + left.second + right.second;
			returnval.second = max(left.first, left.second) + max(right.first, right.second);
			return returnval;
		}
	}


public:
	int rob(TreeNode* root) {
		pair<int, int> res = recu_rob(root);
		return max(res.first, res.second);
	}
};
