#include "listnode.h"

//40ms, 98.23%
//ȡ����һ����, �ڶ�������1/2�����滻��, ����������1/3�����滻....
//��֤����ÿ�����ø��ʶ���1/n, nΪ������

class Solution {
private:
	ListNode* prehead;
public:
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		prehead = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* temp = prehead;
		int res = temp->val;
		temp = temp->next;
		int count = 2;
		while (temp)
		{
			if ((rand() % count) == 0)
			{
				res = temp->val;
			}
			temp = temp->next;
			count++;
		}
		return res;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

/*
int main()
{
	Solution* s = new Solution(stringToListNode("[10,1,10,20,100]"));
	int param_1 = s->getRandom();
	return 0;
}
*/
