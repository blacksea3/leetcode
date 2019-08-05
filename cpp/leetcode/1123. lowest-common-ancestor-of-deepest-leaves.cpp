#include "BinaryTree.h"

//20ms, 82.76%
//DFS
//ֻ�е���������������һ��ʱ, ��ǰ�ڵ�ſ��ܳ�Ϊ����Ҷ�ڵ�Ĺ�������

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
	TreeNode* res;
	int maxdepth = INT_MIN;
	//ֻ�е���������������һ��ʱ, ��ǰ�ڵ�ſ��ܳ�Ϊ����Ҷ�ڵ�Ĺ�������
	int DFS(TreeNode* root, int parentlen)
	{
		if (!root->left && !root->right)
		{
			if ((parentlen + 1) >= maxdepth)
			{
				maxdepth = parentlen + 1;
				res = root;
			}
			return 1;
		}
		else if (root->left && !root->right)
		{
			int leftlen = DFS(root->left, parentlen + 1);
			return leftlen + 1;
		}
		else if (root->right && !root->left)
		{
			int rightlen = DFS(root->right, parentlen + 1);
			return rightlen + 1;
		}
		else
		{
			int leftlen = DFS(root->left, parentlen + 1);
			int rightlen = DFS(root->right, parentlen + 1);
			if (leftlen == rightlen)
			{
				if ((parentlen + 1 + leftlen) >= maxdepth)
				{
					maxdepth = parentlen + 1 + leftlen;
					res = root;
				}
			}
			return max(leftlen, rightlen) + 1;
		}
	}

public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		DFS(root, 0);
		return res;
	}
};
