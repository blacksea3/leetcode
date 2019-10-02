#include "BinaryTree.h"

//64ms, 92.05%
//题目说调用next时保证一定能够返回元素
//而调用hasNext时可能没有元素了

//中序遍历:左-根-右
//实际上是形成一个栈

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
