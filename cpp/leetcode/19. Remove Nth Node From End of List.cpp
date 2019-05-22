#include "public.h"
#include "listnode.h"

//4ms, 99.83%

//use double pointer
//  init: first/second pointer point to the dump, dump->next is head,
//    then move the second pointer n times(one time == second=second->next)
//    then move first and second synchronously(together) to when (second->next == NULL)
//  at this stop time, first->next is what you want to del!

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//init
		ListNode* dump = new ListNode(0);
		dump->next = head;
		ListNode* first = dump;
		ListNode* second = dump;

		//move the second pointer n times
		for (int i = 0; i < n; ++i)
			second = second->next;

		//move first and second synchronously
		while ((second->next) != NULL)
		{
			first = first->next;
			second = second->next;
		}

		first->next = first->next->next;
		return dump->next;
	}
};