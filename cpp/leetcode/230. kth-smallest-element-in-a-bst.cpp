#include "BinaryTree.h"

//24ms, 95.63%

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
	int kthSmallest(TreeNode* root, int k) {
		//中序遍历
		int preloc = 0;
		stack<TreeNode*> st;

		//注:由题干, root!=None, 且k有效

		TreeNode* pre = root;

		while (true)
		{
			if (!pre)
			{
				TreeNode* temp = st.top();
				if (++preloc == k) return temp->val;
				else
				{
					st.pop();
					pre = temp->right;
				}
			}
			else
			{
				st.push(pre);
				pre = pre->left;
			}
		}
		return -999; //dump
	}
};
