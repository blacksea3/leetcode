#include "listnode.h"

//32ms, 97.55%
//链表, 原位操作

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//朴素的操作
		ListNode* dump = new ListNode(0);
		dump->next = head;
		ListNode* returnd = dump;

		while (dump->next)
		{
			if (dump->next->val == val)
			{
				dump->next = dump->next->next;
			}
			else
			{
				dump = dump->next;
			}
		}
		return returnd->next;
	}
};
