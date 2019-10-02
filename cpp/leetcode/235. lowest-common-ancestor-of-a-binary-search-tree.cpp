#include "BinaryTree.h"

//40ms, 94.12%
//����������: �����<��<�Ҷ���
//��������: p, q��Ч, ��ô������Ϊ��

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int rVal = root->val;
		int pVal = p->val;
		int qVal = q->val;

		if (rVal < pVal && rVal < qVal) return lowestCommonAncestor(root->right, p, q);
		else if (rVal > pVal && rVal > qVal) return lowestCommonAncestor(root->left, p, q);
		else return root;
	}
};

/*
//40ms, 94.12%
//�����㷨:
//���root���򷵻ؿ�,���root��pval�򷵻�root,��qval�򷵻�root,
//����������,������ǿ��򷵻�root,���left�ǿշ���left,right�ǿշ���right,���򷵻ؿ�
//�����ڴ�������ɨ

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root->val == p->val) return root;
		if (root->val == q->val) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left&&right) return root;
		else if (left) return left;
		else return right;
	}
};
*/
