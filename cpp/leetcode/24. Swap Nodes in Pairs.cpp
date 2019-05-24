#include "public.h"
#include "listnode.h"

//4ms 98.84%

//no special solution
//just use double pointer
// note the border contition

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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return nullptr;

		//  dump->1->2  =>      a=dump, b=2  =>     a.next.next=b.next;  b.next=a.next;  a.next=b;
		// then move a and b
		ListNode* first;
		ListNode* second;
		ListNode* dump = new ListNode(0);  //dump
		dump->next = head;

		//init
		first = dump;
		second = head->next;

		while (second != NULL)
		{
			first->next->next = second->next;
			second->next = first->next;
			first->next = second;
			if (second->next->next == NULL) break;
			first = second->next;
			second = first->next->next;
		}

		ListNode* returnln = dump->next;
		delete dump;
		return returnln;
	}
};
