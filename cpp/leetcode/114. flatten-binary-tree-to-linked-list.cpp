#include "BinaryTree.h"

//recursively, 4ms, 98.92%

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr) return;

		flatten(root->left);
		flatten(root->right);
		//copy right, move left tree to right, set left = null, merge originright(copied) after preright
		TreeNode* r = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right) {
			root = root->right;
		}
		root->right = r;
	}
};
