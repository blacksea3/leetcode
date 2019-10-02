#include "listnode.h"

//8ms, 98.30%
//µü´ú·¨, Ë«Ö¸Õë
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

//12ms, 83.35%
//µÝ¹é

/*
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		else
		{
			ListNode* p = reverseList(head->next);
			head->next->next = head;
			head->next = nullptr;
			return p;
		}
	}
};
*/
