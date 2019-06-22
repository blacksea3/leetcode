#include "listnode.h"

//68ms, 84.26%

//先计算两个链表长度
//然后大家都从头开始，让长的先跑一段，然后一起跑的话如果相同则一定是相交起始点

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//遍历读取长度

		ListNode* lnA = headA;
		ListNode* lnB = headB;
		int abs = 0;  //计数

		while ((lnB) && (lnA))
		{
			lnB = lnB->next;
			lnA = lnA->next;
		}
		if (lnB)
		{
			while (lnB)
			{
				lnB = lnB->next;
				abs++;
			}
			lnA = headA;
			lnB = headB;
			//从头开始先跑一段
			while (abs-- != 0)
				lnB = lnB->next;
		}
		else if (lnA)
		{
			while (lnA)
			{
				lnA = lnA->next;
				abs++;
			}

			lnA = headA;
			lnB = headB;
			//从头开始先跑一段
			while (abs-- != 0)
				lnA = lnA->next;
		}
		else
		{
			lnA = headA;
			lnB = headB;
		}

		//从头开始跑
		while (lnA)
		{
			if (lnB == lnA) return lnB;
			lnB = lnB->next;
			lnA = lnA->next;
		}
		return nullptr;
	}
};
