#include "BinaryTree.h"

//40ms, 94.12%
//二叉搜索树: 左儿子<中<右儿子
//考虑题意: p, q有效, 那么树不会为空

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
//特殊算法:
//如果root空则返回空,如果root是pval则返回root,是qval则返回root,
//否则看左右手,如果都非空则返回root,如果left非空返回left,right非空返回right,否则返回空
//类似于从下往上扫

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
