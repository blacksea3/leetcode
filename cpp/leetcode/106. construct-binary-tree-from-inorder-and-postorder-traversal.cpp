#include "BinaryTree.h"

//24ms, 96.72%

//similar to problem 105
//��һ��������
//��preorder������ɨ,�����ǰ�ڵ�!=inorderδ�����ڵ�,���¼�������
//Ȼ�����ջ,ע������ɨ��ʱ��,��ɨ�Ľڵ��ڵ�ǰ�ڵ��һ��
//����,ջ�˳�,��ǰ�ڵ�����
//inorder�ڵ�����������,����ֹͣʱ��ǰ�ڵ���ҽڵ�ǡ�õ���preorder
//�ı�ɨ��Ľڵ�

//��һ��������
//�Ѻ������"��"�������Ǹ�->��->��
//���������"��"����������->��->��
//��������һ�ⲻ�ǲ����!

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return nullptr;

		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
		st.push(root);
		int index = inorder.size() - 1;

		for (int i = postorder.size() - 2; i >= 0; --i)
		{
			TreeNode *cur = st.top();
			if (cur->val != inorder[index])
			{
				cur->right = new TreeNode(postorder[i]);
				st.push(cur->right);
			}
			else
			{
				while (!st.empty() && st.top()->val == inorder[index])
				{
					cur = st.top();
					st.pop();
					--index;
				}
				if (index >= 0)  //���൱���˳�ѭ����־
				{
					cur->left = new TreeNode(postorder[i]);
					st.push(cur->left);
				}
			}
		}
		return root;
	}
};