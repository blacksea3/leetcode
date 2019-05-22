#include "public.h"
#include "listnode.h"

//12ms, 98.41%

//no special solution
// this is simple

//only pay attention: there must be one listnode remaining some nodes, which should be considered carefully

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		//不要泄露内存
		//下面俩ListNode都存在
		ListNode* head;
		//确定ListNode头
		if (l1->val >= l2->val)
		{
			ListNode* temp = new ListNode(l2->val);
			head = temp;
			l2 = l2->next;
		}
		else
		{
			ListNode* temp = new ListNode(l1->val);
			head = temp;
			l1 = l1->next;
		}

		ListNode* iter = head;
		//双遍历
		while ((l1 != NULL) && (l2 != NULL))
		{
			if (l1->val >= l2->val)
			{
				iter->next = new ListNode(l2->val);
				l2 = l2->next;
				iter = iter->next;
			}
			else
			{
				iter->next = new ListNode(l1->val);
				l1 = l1->next;
				iter = iter->next;
			}
		}

		//一定有某个链表有剩下的
		if (l1 == NULL) iter->next = l2;
		else iter->next = l1;

		return head;
	}
};