#include "BinaryTree.h"

//0ms, 100%
//����������, ����DFS

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
	int minFirst = INT_MAX;
	bool resValid = false;
	int minSecond = INT_MAX;

	void DFS(TreeNode* root)
	{
		if (!root) return;
		if (root->val > minFirst)
		{
			resValid = true;
			minSecond = min(minSecond, root->val);
		}
		DFS(root->left);
		DFS(root->right);
	}

public:
	int findSecondMinimumValue(TreeNode* root) {
		//ע���Ƿǿ���, ��Сֵ���Ǹ��ڵ�
		minFirst = root->val;
		DFS(root);
		return (resValid) ? minSecond : -1;
	}
};
