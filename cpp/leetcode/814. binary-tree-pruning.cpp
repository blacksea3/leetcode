#include "BinaryTree.h"

//8ms, 55.77%
//一遍DFS, 如果自己是0而且左右都是空/全0(通过删除标记判断), 那么返回删除标记
//左右中遍历

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
private:
	//若全0或为空则返回true, 否则false
	bool DFS(TreeNode* root)
	{
		if (!root) return true;
		bool left = DFS(root->left);
		bool right = DFS(root->right);
		if (left) root->left = nullptr;
		if (right) root->right = nullptr;
		if (left && right && root->val == 0) return true;
		else return false;
	}


public:
	TreeNode* pruneTree(TreeNode* root) {
		if (DFS(root)) return nullptr;
		else return root;
	}
};
