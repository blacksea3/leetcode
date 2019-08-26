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
		//��ʾ��,�ƺ����ȱ���������,Ȼ�������,Ȼ�����������
		//ÿ����һ��,�滻�Ǹ��ڵ��ֵ,�õ�ǰ�Ѿ��滻�Ľڵ�ֵ֮��+�Ǹ��ڵ��ֵ�滻;Ȼ������Ѿ��滻�Ľڵ�ֵ֮��

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
				//����һ��
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

