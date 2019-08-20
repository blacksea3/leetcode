#include "BinaryTree.h"

//32ms, 46.95%
//ÖÐ×óÓÒËÑË÷
//µÝ¹é, ·µ»ØTreeNode*

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
	TreeNode* DFS(TreeNode* root, int L, int R)
	{
		if (!root) return nullptr;
		else if (root->val > R)
			return DFS(root->left, L, R);
		else if (root->val < L)
			return DFS(root->right, L, R);
		else
		{
			root->left = DFS(root->left, L, R);
			root->right = DFS(root->right, L, R);
			return root;
		}
	}

public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		return DFS(root, L, R);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->trimBST(stringToTreeNode("[3,1,4,null,2]"), 3, 4);
	return 0;
}
*/
