#include "BinaryTree.h"

//12ms, 95.41%

class Solution {
private:
	bool recu_hasPathSum(TreeNode* root, int sum)
	{
		if ((root == nullptr)) return false;
		else if ((root->left == nullptr) && (root->right == nullptr))
		{
			return (sum == root->val);
		}
		else
		{
			return recu_hasPathSum(root->left, sum - root->val) ||
				recu_hasPathSum(root->right, sum - root->val);
		}
	}

public:
	bool hasPathSum(TreeNode* root, int sum) {
		return recu_hasPathSum(root, sum);
	}
};
