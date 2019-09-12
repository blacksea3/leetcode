#include "public.h"
#include "listnode.h"

//16ms, 91.86%
//链表, 先计算链表长度得出真实移动距离, 再移动, O(n), 常数2倍

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//get the length of listnode
		int length = 1;
		ListNode* lastln = head;
		if (lastln == NULL) return nullptr;
		while (lastln->next != NULL)
		{
			lastln = lastln->next;
			length++;
		}
		//get the real move distance
		k %= length;
		if (k == 0) return head;
		else
		{
			ListNode* dump = new ListNode(0);
			dump->next = head;
			ListNode* anoln = dump;

			for (int i = 0; i < length-k; ++i) anoln = anoln->next;

			//use three pointers
			lastln->next = dump->next;
			dump->next = anoln->next;
			anoln->next = NULL;
			return dump->next;
		}
	}
};