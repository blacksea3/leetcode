#include "listnode.h"

//20ms, 89.16%
//ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)

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
