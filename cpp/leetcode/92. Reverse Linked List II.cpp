#include "listnode.h"

//8ms, 91.04%

//No special algorithm

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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;

		//one traverse
		ListNode *dump = new ListNode(0);
		dump->next = head;
		int loc = 0;
		ListNode *left = dump;
		ListNode * right = dump;
		bool isstart = false;
		ListNode *preln = dump;
		while (loc < n)
		{
			if (!isstart)
			{
				if ((loc + 1) == m)
				{
					left = preln;
					isstart = true;
				}
				loc++;
				preln = preln->next;
			}
			else
			{
				right = preln;  //in fact: they are sawp of left->next and right->next
				// 1->3->2->4->5  left:1 right:2
				ListNode *temp = left->next;
				left->next = right->next;
				right->next = left->next->next;
				left->next->next = temp;

				loc++;
			}
		}
		return dump->next;
	}
};