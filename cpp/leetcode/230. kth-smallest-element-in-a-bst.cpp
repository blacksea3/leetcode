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
		//�������
		int preloc = 0;
		stack<TreeNode*> st;

		//ע:�����, root!=None, ��k��Ч

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
