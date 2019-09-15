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

//80ms, 89.03%
//注意这是完美二叉树, 不会残缺

class Solution {
private:
	void helper(Node* root)
	{
		if (!root || !root->left) return;
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
