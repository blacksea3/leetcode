#include "BinaryTree.h"

//60ms, 26.91%
//递归
//普通中左右遍历
//右儿子空可以省略括号, 左儿子空不能省略

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
	string preorder(TreeNode* root)
	{
		if (!root) return "";
		else
		{
			string left = preorder(root->left);
			string right = preorder(root->right);
			if (left == "")
			{
				if (right != "")
					return to_string(root->val) + "(" + left + ")(" + right + ")";
				else
					return to_string(root->val);
			}
			else if (right == "")
			{
				return to_string(root->val) + "(" + left + ")";
			}
			else
				return to_string(root->val) + "(" + left + ")(" + right + ")";
		}
	}

public:
	string tree2str(TreeNode* t) {
		return preorder(t);
	}
};
