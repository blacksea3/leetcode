#include "BinaryTree.h"

//12ms, 89.81%
//�����б���, ��ǰ���ڵ�õ����ҵ�������, Ȼ��ó�һ��������ǰ���ڵ��ֱ������
//���ڵ���Ӧ����������

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
	int res = 1;
	//�����Ե�ǰ�ڵ�Ϊ������������
	int DFS(TreeNode* root)
	{
		if (!root) return 0;
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			res = max(res, left + right + 1);
			return max(left, right) + 1;
		}
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		DFS(root);
		return res - 1;
	}
};
