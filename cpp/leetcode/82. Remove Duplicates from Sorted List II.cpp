#include "listnode.h"

//8ms, 97.66%
//Ä£Äâ

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode* dump = new ListNode(0);
		dump->next = head;
		ListNode* pre = dump;

		while (true)
		{
			ListNode* pNext = pre->next;
			if (!pNext) break;
			else if (pNext->next && pNext->val == pNext->next->val)
			{
				int val = pNext->val;
				while (pNext && val == pNext->val)
				{
					pNext = pNext->next;
				}
				pre->next = pNext;
			}
			else pre = pNext;
		}
		return dump->next;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->deleteDuplicates(stringToListNode("[1,2,3,3,4,4,5]"));
	return 0;
}
*/
