#include "BinaryTree.h"

//0ms, 100.00%
//ע����Ŀ��˼: ����һ����ÿ���ڵ�һ��Ӳ��
//�������Ҫ�����ٴ���
//�Ե׶��ϻ�ȡӲ��, ȱ����, �����

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
			return root->val - 1; //�����Ӳ����
		}
		else if (!root->right)
		{
			int left = DFS(root->left);
			res += abs(left + root->val - 1);
			return left + root->val - 1; //�����Ӳ����
		}
		else if (!root->left)
		{
			int right = DFS(root->right);
			res += abs(right + root->val - 1);
			return right + root->val - 1; //�����Ӳ����
		}
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			res += abs(left + right + root->val - 1);
			return left + right + root->val - 1; //�����Ӳ����
		}
	}

public:
	int distributeCoins(TreeNode* root) {
		DFS(root);
		return res;
	}
};
