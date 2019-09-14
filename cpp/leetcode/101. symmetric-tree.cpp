#include "BinaryTree.h"

//iterately solution, 16ms, 74.61%
//traverse both left and right, use one queue
/*
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		//speial input
		if (root == nullptr) return true;

		queue<TreeNode*> q;
		bool isvalid1 = true;

		//init q
		q.push(root->left);
		q.push(root->right);

		while (!q.empty())
		{
			TreeNode* left = q.front();
			q.pop();
			TreeNode* right = q.front();
			q.pop();
			if ((left == nullptr) && (right == nullptr)) continue;
			if ((left == nullptr) || (right == nullptr)) return false;
			if (left->val != right->val) return false;
			q.push(left->left);
			q.push(right->right);
			q.push(left->right);
			q.push(right->left);
		}
		
		return true;
	}
};*/

//recursively, 4ms, 98.64%
class Solution {
private:
	bool recu_isSymmetric(TreeNode* left, TreeNode* right)
	{
		if ((left == nullptr) && (right == nullptr)) return true;
		if ((left == nullptr) || (right == nullptr)) return false;
		if (left->val != right->val) return false;
		return (recu_isSymmetric(left->left, right->right) && 
			recu_isSymmetric(left->right, right->left));
	}

public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		else return recu_isSymmetric(root->left, root->right);
	}
};
