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
//�������, �ö�������Ȼ��, ����Ϊ�˻�ȡO(1)�ռ临�Ӷ�, ����ֱ��ʹ��nextָ��������
//�ο� https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/mo-bai-da-lao-de-si-lu-yong-nextdai-ti-queue-by-gi/

class Solution {
public:
	Node* connect(Node* root) {
		Node *last = root;
		while (last) {
			// ��ö���Ԫ��
			while (last && !last->left && !last->right)last = last->next;
			if (!last)break;
			Node *cur = NULL;
			// ��������
			for (Node *i = last; i; i = i->next) {
				// ����push��pop����
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
			// ���¶���
			last = last->left ? last->left : last->right;
		}
		return root;
	}
};
