#include "listnode.h"

//16ms, 91.75%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Simple solution, use double pointer

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		//one traverse
		//double pointer
		ListNode* dump = new ListNode(0);
		dump->next = head;
		ListNode* loc = dump;
		ListNode *left, *right;

		while (loc->next)
		{
			left = loc->next;
			right = left;
			while (right->next && right->next->val == left->val)
				right = right->next;
			if (left == right) loc = loc->next;
			else loc->next = right->next;
		}
		return dump->next;
	}
};