#include "BinaryTree.h"

//44ms, 58.33%
//递归

class Solution {
private:
	int res = INT_MIN;   //方法共享变量,最小值
private:
	//返回包含当前节点的最大值
	int iter_maxPathSum(TreeNode* root)
	{
		//注意到:对任意一个节点,如果最大和路径包含它,那么可能:它加上左右子树 或者 它加上左/右子树 加上父亲们
		if (root == nullptr) return 0;
		int left = max(0, iter_maxPathSum(root->left));  //如果左子树是负的,那么就别包含它了
		int right = max(0, iter_maxPathSum(root->right));  //如果右子树是负的,那么就别包含它了
		res = max(res, left + right + root->val);   //核心,这里必须判断一次当前root加上左右子树是不是最大的,并且记录至类变量
		return max(left, right) + root->val;
	}

public:
	int maxPathSum(TreeNode* root) {
		//递归
		iter_maxPathSum(root);
		return res;
	}
};
