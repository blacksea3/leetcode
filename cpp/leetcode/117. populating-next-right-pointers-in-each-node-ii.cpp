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

//620ms, 81.48%
//level order traverse, first you can use queue, but if we want to achieve O(1) space use,
// we can directedly use next to replace the use of queue
// this is from https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/mo-bai-da-lao-de-si-lu-yong-nextdai-ti-queue-by-gi/

Node* connect(Node* root) {
	Node *last = root;
	while (last != NULL) {
		// 获得队首元素
		while (last && last->left == NULL && last->right == NULL)last = last->next;
		if (last == NULL)break;
		Node *cur = NULL;
		// 遍历队列
		for (Node *i = last; i != NULL; i = i->next) {
			// 进行push和pop操作
			if (i->left) {
				if (cur != NULL) {
					cur->next = i->left;
				}
				cur = i->left;
			}
			if (i->right) {
				if (cur != NULL) {
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

