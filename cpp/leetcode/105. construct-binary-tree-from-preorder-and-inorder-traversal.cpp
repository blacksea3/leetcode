#include "BinaryTree.h"

//note: recursively will overflow, FUCK
//iterative: 20ms, 99.33%

//the first item in preorder is root, then divide inorder by root into left and right trees

//in the iteratively solution: 
//��preorder������ɨ,�����ǰ�ڵ�!=inorderδ�����ڵ�,�����ɵ�������ӽڵ�,���ӵ�root��
//Ȼ�����ջ,ע������ɨ��ʱ��,��ɨ�Ľڵ��ڵ�ǰ�ڵ��һ��
//����,ջ�˳�,��ǰ�ڵ�����
//inorder�ڵ�����������,����ֹͣʱ��ǰ�ڵ���ҽڵ�ǡ�õ���preorder�ı�ɨ��Ľڵ�

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return nullptr;

		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(preorder[0]);
		st.push(root);
		int index = 0;

		for (int i = 1; i <= preorder.size(); ++i)
		{
			TreeNode *cur = st.top();
			if (cur->val != inorder[index])
			{
				cur->left = new TreeNode(preorder[i]);
				st.push(cur->left);
			}
			else
			{
				while (!st.empty() && st.top()->val == inorder[index])
				{
					cur = st.top();
					st.pop();
					++index;
				}
				if (index < inorder.size())  //border check
				{
					cur->right = new TreeNode(preorder[i]);
					st.push(cur->right);
				}
			}
		}
		return root;
	}
};
