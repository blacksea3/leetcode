#include "listnode.h"

//12ms, 98.32%

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
	bool hasCycle(ListNode *head) {
		//O(n)内存很简单
		//采用常量内存

		//来自评论:快慢指针
		if (head == nullptr) return false;

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};
