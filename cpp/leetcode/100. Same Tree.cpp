#include "BinaryTree.h"

//4ms, 82.11%
//一起遍历
//中序遍历

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (!p || !q) return false;
		else
		{
			return (p->val == q->val) && isSameTree(p->left, q->left) &&
				isSameTree(p->right, q->right);
		}
	}
};
