#include "BinaryTree.h"

//20ms, 98.37%
//����ջ

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
	TreeNode* recoverFromPreorder(string S) {
		vector<TreeNode*> v;

		//��ȡ��
		int val = 0;
		int loc = 0;
		while (loc < S.size() && isdigit(S[loc]))
		{
			val = 10 * val + S[loc] - '0';
			loc++;
		}

		TreeNode* t = new TreeNode(val);
		TreeNode* root = t;
		v.push_back(t);

		while (loc < S.size())
		{
			//�ȶ������ٶ�����
			int depth = 0;
			while (S[loc] == '-')
			{
				depth++;
				loc++;
			}
			int tempval = 0;
			while (loc < S.size() && isdigit(S[loc]))
			{
				tempval = 10 * tempval + S[loc] - '0';
				loc++;
			}
			//ɾ��v�������ڵ�
			int dabs = v.size() - depth;
			for (int i = 0; i < dabs; ++i) v.pop_back();
			//�������
			if (!v[depth - 1]->left)
			{
				v[depth - 1]->left = new TreeNode(tempval);
				v.push_back(v[depth - 1]->left);
			}
			else
			{
				v[depth - 1]->right = new TreeNode(tempval);
				v.push_back(v[depth - 1]->right);
			}
		}
		return root;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->recoverFromPreorder("1-2--3--4-5--6--7");
	prettyPrintTree(res);
	return 0;
}*/