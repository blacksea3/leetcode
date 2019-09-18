#include "BinaryTree.h"

//4ms, 89.86%
//Ä£Äâ, ±éÀúÊ÷

class Solution {
private:
	int sum = 0;
	void iter_sumNumbres(TreeNode* root, const int& pre)
	{
		if (root)
		{
			int now = 10 * pre + root->val;
			if ((root->left == nullptr) && (root->right == nullptr))
			{
				sum += now;
			}
			else
			{
				iter_sumNumbres(root->left, now);
				iter_sumNumbres(root->right, now);
			}
		}
	}

public:
	int sumNumbers(TreeNode* root) {
		//µÝ¹é
		iter_sumNumbres(root, 0);
		return sum;
	}
};
