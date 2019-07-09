#include "listnode.h"

//48ms, 89.39%
//取出第一个数, 第二个数有1/2概率替换它, 第三个数有1/3概率替换....
//可证明得每个数得概率都是1/n, n为链表长度

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

int main()
{
	Solution* s = new Solution(stringToListNode("[10,1,10,20,100]"));
	int param_1 = s->getRandom();
	return 0;
}
