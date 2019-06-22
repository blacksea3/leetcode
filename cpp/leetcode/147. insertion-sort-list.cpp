#include "listnode.h"

//64ms, 60.32%

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
	ListNode* insertionSortList(ListNode* head) {
		//返回新建的链表

		if ((head == nullptr) || (head->next == nullptr)) return head;
		
		ListNode* dumphead = new ListNode(0);

		ListNode* preright = head;
		ListNode* preleft;
		//O(n^2)时间复杂度
		while (preright)
		{
			int preval = preright->val;
			preleft = dumphead;
			ListNode* temp = preleft->next;
			while ((temp) && (temp->val < preval))
			{
				preleft = temp;
				temp = temp->next;
			}
			preleft->next = new ListNode(preval);
			preleft->next->next = temp;
			preright = preright->next;
		}
		head = dumphead->next;
		dumphead->next = nullptr;
		delete dumphead;
		return head;
	}
};

