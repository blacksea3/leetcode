#include "listnode.h"

//68ms, 84.26%

//�ȼ�������������
//Ȼ���Ҷ���ͷ��ʼ���ó�������һ�Σ�Ȼ��һ���ܵĻ������ͬ��һ�����ཻ��ʼ��

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
		//������ȡ����

		ListNode* lnA = headA;
		ListNode* lnB = headB;
		int abs = 0;  //����

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
			//��ͷ��ʼ����һ��
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
			//��ͷ��ʼ����һ��
			while (abs-- != 0)
				lnA = lnA->next;
		}
		else
		{
			lnA = headA;
			lnB = headB;
		}

		//��ͷ��ʼ��
		while (lnA)
		{
			if (lnB == lnA) return lnB;
			lnB = lnB->next;
			lnA = lnA->next;
		}
		return nullptr;
	}
};
