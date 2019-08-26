#include "BinaryTree.h"

//64ms, 68.66%
//DFS, 递归
//如果左右节点均空, 且左边或者右边本来存在子树, 但是(因为左右节点均空)所以表示删掉了, 则返回NULL
//如果左边或者右边本来不存在子树(这是因为left_may_manual_del与right_may_manual_del仍然为false), 则判断当前剩余limit与root->val大小, 如果root->val更小则返回NULL(此时root是一个叶子节点)

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
