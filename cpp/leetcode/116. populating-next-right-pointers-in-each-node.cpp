#include "public.h"
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

//note this is a perfect binary tree!, 84ms, 92.98%

class Solution {
private:
	void helper(Node* root)
	{
		if (!root) return;
		if (!root->left) return;
		root->left->next = root->right;
		if (root->next) root->right->next = root->next->left;
		helper(root->left);
		helper(root->right);
	}

public:
	Node* connect(Node* root) {
		helper(root);
		return root;
	}
};