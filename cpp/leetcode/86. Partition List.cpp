#include "listnode.h"

//4ms, 99.55%
//�ϲ�����������

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *leftdump = new ListNode(0);
		ListNode *rightdump = new ListNode(0);
		ListNode *left = leftdump;
		ListNode *right = rightdump;

		while (head != nullptr)
		{
			if (head->val < x)
			{
				left->next = new ListNode(head->val);
				left = left->next;
			}
			else
			{
				right->next = new ListNode(head->val);
				right = right->next;
			}
			head = head->next;
		}

		left->next = rightdump->next;
		return leftdump->next;
	}
};
