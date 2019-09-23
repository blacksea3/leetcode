#include "listnode.h"

//56ms, 98.72%
//ԭ���㷨
//�鲢����

class Solution {
private:
	//�ⲿȷ��head��Ϊ��
	ListNode* iter_sortList(ListNode* head)
	{
		if (head->next == nullptr) return head;

		//��˫ָ���и�����
		ListNode* fast = head;
		ListNode* slow = head;

		while (true)
		{
			if ((fast->next) && (fast->next->next))
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else break;
		}
		//slow->nextΪ�������

		ListNode* lefthalf = head;
		ListNode* righthalf = slow->next;
		slow->next = nullptr;
		lefthalf = iter_sortList(lefthalf);
		righthalf = iter_sortList(righthalf);

		//�ϲ�
		ListNode* returnhead;
		ListNode* pre;
		if (lefthalf->val < righthalf->val)
		{
			returnhead = lefthalf;
			lefthalf = lefthalf->next;
		}
		else
		{
			returnhead = righthalf;
			righthalf = righthalf->next;
		}
		pre = returnhead;
		while (lefthalf && righthalf)
		{
			if (lefthalf->val < righthalf->val)
			{
				pre->next = lefthalf;
				lefthalf = lefthalf->next;
			}
			else
			{
				pre->next = righthalf;
				righthalf = righthalf->next;
			}
			pre = pre->next;
		}
		if (lefthalf) pre->next = lefthalf;
		else pre->next = righthalf;
		return returnhead;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) return nullptr;  //�˴����״ε���
		return iter_sortList(head);
	}
};

