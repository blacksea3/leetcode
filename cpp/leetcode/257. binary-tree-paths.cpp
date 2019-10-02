#include "BinaryTree.h"

//4ms, 92.87%
//DFS

class Solution {
private:
	vector<string> res = {};
	void recu_bip(TreeNode* t, string pp)
	{
		pp += to_string(t->val);
		if (t->left) recu_bip(t->left, pp + "->");
		if (t->right) recu_bip(t->right, pp + "->");
		if (!t->left && !t->right) res.push_back(pp);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return res;
		recu_bip(root, "");
		return res;
	}
};
