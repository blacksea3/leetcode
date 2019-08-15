#include "BinaryTree.h"

//28ms, 75.49%
//������, DFS���غ���ǰ�ڵ�����ڵ��ܺ�

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
		if (!root) return 0;
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			res += abs(left - right);
			return left + right + root->val;
		}
	}

public:
	int findTilt(TreeNode* root) {
		DFS(root);
		return res;
	}
};
