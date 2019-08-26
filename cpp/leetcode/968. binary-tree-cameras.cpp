#include "BinaryTree.h"

//12ms, 91.57%
//�������, ̰��: ��������״̬: �����/�ܼ��/�޼��
//���е�Ҷ�Ӷ�����Ҫ���, Ȼ�����ĳ����Ҷ�ӽڵ�, �����ҽڵ��������޼�����Լ�������, ���������, �����ܼ����ô�Լ����Բ����, �Լ������޼��, ���򷵻��ܼ�ء� �սڵ������ܼ��
//һֱ�������ڵ�

//�������: ��һ�����ڵ�, ��ôӦ����һ�����:)

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
	//����״̬: 0:�����, 1:�޼��, 2:�ܼ��
	int postorder(TreeNode* root)
	{
		if (!root->left && !root->right)
			return 1;
		else
		{
			int left = (!root->left) ? 2 : postorder(root->left);
			int right = (!root->right) ? 2 : postorder(root->right);
			if ((left == 1 || right == 1))
			{
				res++;
				return 0;
			}
			else if (left == 2 && right == 2)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}

public:
	int minCameraCover(TreeNode* root) {
		int s = postorder(root);
		if (s == 1) res++;
		return res;
	}
};
