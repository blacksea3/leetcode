#include "BinaryTree.h"

//16ms, 98.42%
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
