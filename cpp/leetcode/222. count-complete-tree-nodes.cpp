#include "BinaryTree.h"

//36ms, 96.39%
//ÏÈÐò±éÀú, ÖÐ×óÓÒ

class Solution {
private:
	int res = 0;
	void preOrder(TreeNode* root)
	{
		if (!root) return;
		else
		{
			res++;
			preOrder(root->left);
			preOrder(root->right);
		}
	}

public:
	int countNodes(TreeNode* root) {
		preOrder(root);
		return res;
	}
};
