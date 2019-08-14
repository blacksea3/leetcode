#include "BinaryTree.h"

//12ms, 89.81%
//左右中遍历, 当前根节点得到左右的最大深度, 然后得出一个包含当前根节点的直径长度
//根节点是应当被遍历的

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
	int res = 1;
	//返回以当前节点为根的树最大深度
	int DFS(TreeNode* root)
	{
		if (!root) return 0;
		else
		{
			int left = DFS(root->left);
			int right = DFS(root->right);
			res = max(res, left + right + 1);
			return max(left, right) + 1;
		}
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		DFS(root);
		return res - 1;
	}
};
