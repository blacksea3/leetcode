#include "BinaryTree.h"

//12ms, 95.65%
//recursively

class Solution {
private:
	//ensure that root!=nullptr
	int recu_mindepth(TreeNode* root)
	{
		if (!root) return 0;
        else if (!root->left)
			return recu_mindepth(root->right) + 1;
		else if (!root->right)
			return recu_mindepth(root->left) + 1;
		else
			return min(recu_mindepth(root->left), recu_mindepth(root->right)) + 1;
	}

public:
	int minDepth(TreeNode* root) {
		return recu_mindepth(root);
	}
};
