#include "listnode.h"

//4ms, 90.58%
//ÒıÈëÕ»

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		stack<ListNode*> stk;

		ListNode* header = new ListNode(0);
		header->next = head;

		ListNode* start;
		ListNode* end = header;

		int counter = 0;

		while (counter <= n)
		{
			if (counter >= m)
				stk.push(end);
			else if (counter == m - 1)
				start = end;
			end = end->next;
			counter++;
		}

		while (!stk.empty())
		{
			ListNode* top = stk.top();
			start->next = top;
			stk.pop();
			start = top;
		}
		start->next = end;
		return header->next;
	}
};
