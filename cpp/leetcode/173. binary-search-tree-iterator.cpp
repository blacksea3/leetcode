#include "BinaryTree.h"

//64ms, 92.05%
//��Ŀ˵����nextʱ��֤һ���ܹ�����Ԫ��
//������hasNextʱ����û��Ԫ����

//�������:��-��-��
//ʵ�������γ�һ��ջ

class BSTIterator {
private:
	stack<TreeNode*> dfs;
public:
	BSTIterator(TreeNode* root) {

		pushleft(root);
	}

	int next() {
		TreeNode* cur = dfs.top();
		dfs.pop();
		if (cur->right) {
			pushleft(cur->right);
		}
		return cur->val;
	}

	void pushleft(TreeNode* node) {
		TreeNode* p = node;
		while (p) {
			dfs.push(p);
			p = p->left;
		}
	}

	bool hasNext() {
		return !dfs.empty();
	}
};
