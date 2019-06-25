#include "BinaryTree.h"

//这就复用上一题 28ms, 83.75%
//特殊算法:
//如果root空则返回空,如果root是pval则返回root,是qval则返回root,
//否则看左右手,如果都非空则返回root,如果left非空返回left,right非空返回right,否则返回空
//类似于从下往上扫

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
