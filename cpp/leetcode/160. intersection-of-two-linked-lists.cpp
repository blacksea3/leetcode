#include "listnode.h"

//52ms, 97.61%
//先一起跑, 找到长度差, 然后让长的先跑
//然后一起跑的话如果相同则一定是相交起始点, 否则直到终点

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//遍历读取长度
		ListNode* lnA = headA;
		ListNode* lnB = headB;
		ListNode* fi;
		ListNode* se;

		while ((lnB) && (lnA))
		{
			lnB = lnB->next;
			lnA = lnA->next;
		}
		if (lnB)
		{
			fi = headB;
			while (lnB)
			{
				lnB = lnB->next;
				fi = fi->next;
			}
			se = headA;
		}
		else if (lnA)
		{
			fi = headA;
			while (lnA)
			{
				lnA = lnA->next;
				fi = fi->next;
			}
			se = headB;
		}
		else
		{
			fi = headA;
			se = headB;
		}

		//从头开始跑
		while (fi)
		{
			if (fi == se) return fi;
			fi = fi->next;
			se = se->next;
		}
		return nullptr;
	}
};
