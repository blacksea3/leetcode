#include "listnode.h"

//12ms, 93.12%

//merge two new build listnode is simple!

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

		if (leftdump->next)
		{
			left->next = rightdump->next;
			return leftdump->next;
		}
		else return rightdump->next;
	}
};