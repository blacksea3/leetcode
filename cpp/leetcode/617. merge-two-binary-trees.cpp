#include "BinaryTree.h"

//48ms, 92.10%
//同时DFS

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
	//将t2加到t1上
	TreeNode* MergeAdd(TreeNode* t1, TreeNode* t2)
	{
		if (t1 && t2)
		{
			TreeNode* left = MergeAdd(t1->left, t2->left);
			TreeNode* right = MergeAdd(t1->right, t2->right);
			t1->left = left;
			t1->right = right;
			t1->val += t2->val;
			return t1;
		}
		else if (t1)
		{
			return t1;
		}
		else if (t2)
		{
			return t2;
		}
		else
			return nullptr;
	}

public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return MergeAdd(t1, t2);
	}
};
