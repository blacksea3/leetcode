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

//640ms, 67.32%
//层序遍历, 用队列是显然的, 但是为了获取O(1)空间复杂度, 可以直接使用next指针代替队列
//参考 https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/mo-bai-da-lao-de-si-lu-yong-nextdai-ti-queue-by-gi/

class Solution {
public:
	Node* connect(Node* root) {
		Node *last = root;
		while (last) {
			// 获得队首元素
			while (last && !last->left && !last->right)last = last->next;
			if (!last)break;
			Node *cur = NULL;
			// 遍历队列
			for (Node *i = last; i; i = i->next) {
				// 进行push和pop操作
				if (i->left) {
					if (cur) {
						cur->next = i->left;
					}
					cur = i->left;
				}
				if (i->right) {
					if (cur) {
						cur->next = i->right;
					}
					cur = i->right;
				}
			}
			// 更新队首
			last = last->left ? last->left : last->right;
		}
		return root;
	}
};
