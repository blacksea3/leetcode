#include "BinaryTree.h"

//12ms, 29.04%

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
public:
	TreeNode* bstToGst(TreeNode* root) {
		//看示例,似乎是先遍历右子树,然后遍历根,然后遍历左子树
		//每遍历一次,替换那个节点的值,用当前已经替换的节点值之和+那个节点的值替换;然后更新已经替换的节点值之和

		int pre_sum = 0;
		vector<TreeNode*> stack = {};
		TreeNode *rootbak = root;
		TreeNode *pre = root;
		while ((pre != nullptr) || !stack.empty())
		{
			if (pre != nullptr)
			{
				stack.push_back(pre);
				pre = pre->right;
			}
			else
			{
				//撤回一步
				pre = stack[stack.size() - 1];
				stack.pop_back();
				pre->val += pre_sum;
				pre_sum = pre->val;
				pre = pre->left;
			}
		}
		return rootbak;
	}
};

