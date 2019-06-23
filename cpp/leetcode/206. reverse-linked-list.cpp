#include "listnode.h"

//simple solution, 12ms, 94.20%

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
	ListNode* reverseList(ListNode* head) {
		ListNode* left = nullptr;
		ListNode* right = head;
		ListNode* temp;

		while (right)
		{
			temp = right;
			right = right->next;
			temp->next = left;
			left = temp;
		}
		return left;
	}
};
