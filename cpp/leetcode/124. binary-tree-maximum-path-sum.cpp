#include "BinaryTree.h"

//40ms, 89.74%

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
	int res = INT_MIN;   //�����������,��Сֵ
private:
	//���ذ�����ǰ�ڵ�����ֵ
	int iter_maxPathSum(TreeNode* root)
	{
		//ע�⵽:������һ���ڵ�,�������·��������,��ô����:�������������� ���� ��������/������ ���ϸ�����
		if (root == nullptr) return 0;
		int left = max(0, iter_maxPathSum(root->left));  //����������Ǹ���,��ô�ͱ��������
		int right = max(0, iter_maxPathSum(root->right));  //����������Ǹ���,��ô�ͱ��������
		res = max(res, left + right + root->val);   //����,��������ж�һ�ε�ǰroot�������������ǲ�������,���Ҽ�¼�������
		return max(left, right) + root->val;
	}

public:
	int maxPathSum(TreeNode* root) {
		//�ݹ�
		iter_maxPathSum(root);
		return res;
	}
};