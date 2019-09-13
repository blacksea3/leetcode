#include "listnode.h"

//8ms, 99.93%
//Ä£Äâ

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dump = new ListNode(0);
		dump->next = head;
		ListNode *pre = dump;

		while (true)
		{
			ListNode* pNext = pre->next;
			if (!pNext) break;
			else if (pNext->next && pNext->val == pNext->next->val)
			{
				pre->next = pNext->next;
			}
			else
			{
				pre = pNext;
			}
		}
		return dump->next;
	}
};
