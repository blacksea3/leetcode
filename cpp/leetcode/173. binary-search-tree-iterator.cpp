#include "BinaryTree.h"

//�����������������, 52ms, 100%
//��Ŀ˵����nextʱ��֤һ���ܹ�����Ԫ��
//������hasNextʱ����û��Ԫ����

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
	stack<TreeNode*> dfs;
public:
	BSTIterator(TreeNode* root) {
		//�������:��-��-��
		//ʵ�������γ�һ��ջ
		pushleft(root);
	}

	/** @return the next smallest number */
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

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !dfs.empty();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */