#include "BinaryTree.h"

//中序遍历二叉搜索树, 52ms, 100%
//题目说调用next时保证一定能够返回元素
//而调用hasNext时可能没有元素了

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
		//中序遍历:左-根-右
		//实际上是形成一个栈
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