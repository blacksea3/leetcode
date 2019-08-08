#include "BinaryTree.h"

//8ms, 55.77%
//һ��DFS, ����Լ���0�������Ҷ��ǿ�/ȫ0(ͨ��ɾ������ж�), ��ô����ɾ�����
//�����б���

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
	//��ȫ0��Ϊ���򷵻�true, ����false
	bool DFS(TreeNode* root)
	{
		if (!root) return true;
		bool left = DFS(root->left);
		bool right = DFS(root->right);
		if (left) root->left = nullptr;
		if (right) root->right = nullptr;
		if (left && right && root->val == 0) return true;
		else return false;
	}


public:
	TreeNode* pruneTree(TreeNode* root) {
		if (DFS(root)) return nullptr;
		else return root;
	}
};
