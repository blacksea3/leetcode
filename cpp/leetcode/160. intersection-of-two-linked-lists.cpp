#include "listnode.h"

//52ms, 97.61%
//��һ����, �ҵ����Ȳ�, Ȼ���ó�������
//Ȼ��һ���ܵĻ������ͬ��һ�����ཻ��ʼ��, ����ֱ���յ�

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//������ȡ����
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

		//��ͷ��ʼ��
		while (fi)
		{
			if (fi == se) return fi;
			fi = fi->next;
			se = se->next;
		}
		return nullptr;
	}
};
