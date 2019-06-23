#include "listnode.h"

//链表, 原位操作, 36ms, 97.29%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
