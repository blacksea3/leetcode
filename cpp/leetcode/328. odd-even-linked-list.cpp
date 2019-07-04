#include "listnode.h"

//24ms, 83.79%
//easy problem, but code may be difficult

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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* odd = head;
		if (!odd) return odd;
		ListNode* even = odd->next;
		if (!even) return odd;

		ListNode* firsteven = even;

		while (true)
		{
			odd->next = even->next;
			if (!odd->next) break;
			else odd = odd->next;
			even->next = even->next->next;
			if (!even->next) break;
			else even = even->next;
		}
		odd->next = firsteven;
		return head;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	ListNode* res = s->oddEvenList(stringToListNode("[1,2,3,4,5]"));
	return 0;
}
*/
