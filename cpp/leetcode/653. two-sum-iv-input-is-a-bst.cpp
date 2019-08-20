#include "BinaryTree.h"

//96ms, 11.42%
//一边访问一边记录至unordered_set

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
	unordered_set<int> us;
	int gbl_k;
	bool Find(TreeNode* root)
	{
		if (!root) return false;
		else if (us.find(gbl_k - root->val) != us.end()) return true;
		else
		{
			us.insert(root->val);
			return Find(root->left) || Find(root->right);
		}
	}

public:
	bool findTarget(TreeNode* root, int k) {
		gbl_k = k;
		return Find(root);
	}
};

