#include "BinaryTree.h"

//40ms, 96.98%
//右中左遍历

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
	TreeNode* convertBST(TreeNode* root) {
		if (!root) return nullptr;

		stack<TreeNode*> st;
		TreeNode* pre = root;
		int history_sum = 0;

		while (true)  //一定能退出循环
		{
			if (pre->right)
			{
				st.push(pre);
				pre = pre->right;
			}
			else
			{
				pre->val += history_sum;
				history_sum = pre->val;
				while (!pre->left)
				{
					if (st.empty()) goto end;

					pre = st.top();
					st.pop();
					pre->val += history_sum;
					history_sum = pre->val;
				}
				pre = pre->left;
			}
		}
	end:
		return root;
	}
};
