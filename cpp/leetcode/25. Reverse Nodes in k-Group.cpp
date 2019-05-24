#include "listnode.h"
#include "public.h"

//28ms, 97.26%

//no special solution, 
// this is similar to 24. Swap Nodes in Pairs,
// only node: you can count the length first, then do these swaps
// consider the border condition carefully

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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		//k=1 special condition
		if (k == 1) return head;

		//count length first,
		int length = 0;
		ListNode* dump = new ListNode(0);  //dump
		dump->next = head;
		while (head != NULL)
		{
			head = head->next;
			length++;
		}

		//init first and second ptr
		// caculate real operations this will do
		if (length >= k)
		{
			//real operation    //none:dump, first:1, second:2   1->2->3
			// =>      2->1->3,   first = 1 will not move, second = 2 will move to first->next, none not move
			// =>      ......
			// this may be difficult, you can draw these node on a notebook
			ListNode* iter_head = dump;
			ListNode* first;
			ListNode* second;
			ListNode* none;
			while (length >= k)
			{
				first = iter_head;
				second = iter_head->next;
				for (int i = 1; i < k; i++)
				{
					ListNode* temp = first->next;
					first->next = second->next;
					second->next = second->next->next;
					first->next->next = temp;
				}
				length -= k;
				iter_head = second;
			}
		}

		ListNode* returnln = dump->next;
		delete dump;
		return returnln;
	}
};
