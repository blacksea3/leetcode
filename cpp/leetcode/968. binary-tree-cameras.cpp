#include "BinaryTree.h"

//12ms, 91.57%
//后序遍历, 贪心: 设置三种状态: 有相机/受监控/无监控
//所有的叶子都不需要监控, 然后对于某个非叶子节点, 其左右节点若存在无监控则自己必须监控, 返回有相机, 若都受监控那么自己可以不监控, 自己返回无监控, 否则返回受监控。 空节点视作受监控
//一直传到根节点

//特殊情况: 就一个根节点, 那么应当放一个监控:)

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
	int res = 0;
	//返回状态: 0:有相机, 1:无监控, 2:受监控
	int postorder(TreeNode* root)
	{
		if (!root->left && !root->right)
			return 1;
		else
		{
			int left = (!root->left) ? 2 : postorder(root->left);
			int right = (!root->right) ? 2 : postorder(root->right);
			if ((left == 1 || right == 1))
			{
				res++;
				return 0;
			}
			else if (left == 2 && right == 2)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}

public:
	int minCameraCover(TreeNode* root) {
		int s = postorder(root);
		if (s == 1) res++;
		return res;
	}
};
