#include "BinaryTree.h"

//16ms. 99.41%
//�������, ������

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
