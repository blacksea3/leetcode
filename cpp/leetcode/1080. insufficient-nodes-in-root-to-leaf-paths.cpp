#include "BinaryTree.h"

//64ms, 68.66%
//DFS, �ݹ�
//������ҽڵ����, ����߻����ұ߱�����������, ����(��Ϊ���ҽڵ����)���Ա�ʾɾ����, �򷵻�NULL
//�����߻����ұ߱�������������(������Ϊleft_may_manual_del��right_may_manual_del��ȻΪfalse), ���жϵ�ǰʣ��limit��root->val��С, ���root->val��С�򷵻�NULL(��ʱroot��һ��Ҷ�ӽڵ�)

class Solution {
public:
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		if (!root) return root;
		bool left_may_manual_del = false, right_may_manual_del = false;

		if (root->left) {
			root->left = sufficientSubset(root->left, limit - root->val);
			left_may_manual_del = true;
		}
		if (root->right) {
			root->right = sufficientSubset(root->right, limit - root->val);
			right_may_manual_del = true;
		}
		if (!root->left && !root->right && (right_may_manual_del || left_may_manual_del)) return NULL;
		if (!root->left && !root->right && root->val < limit) return NULL;

		return root;
	}
};
