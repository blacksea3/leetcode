#include "listnode.h"

//92.54%

//similar to problem 82, use double pointer

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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dump = new ListNode(0);
		dump->next = head;

		ListNode *left, *right;
		ListNode *loc = head;

		while (loc)
		{
			left = loc;
			right = loc->next;
			while (right && (right->val == left->val)) right = right->next;
			if (left->next == right) loc = loc->next;
			else loc->next = right;
		}
		return dump->next;
	}
};