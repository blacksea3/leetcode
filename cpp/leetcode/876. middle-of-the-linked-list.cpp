#include "listnode.h"

//0ms, 100%
//Á½±éÉ¨Ãè

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
	ListNode* middleNode(ListNode* head) {
		int len = 0;
		ListNode* pre = head;
		while (pre)
		{
			len++;
			pre = pre->next;
		}

		int maylen = len / 2 + 1;
		int time = 0;
		pre = head;
		while (time < maylen)
		{
			pre = pre->next;
			time++;
		}
		return pre;
	}
};
