#include "listnode.h"

//40ms, 77.72%
//ģ��
//ʱ�临�Ӷ�O(n^2)

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		//�����½�������
		//if ((head == nullptr) || (head->next == nullptr)) return head;
		ListNode* dumphead = new ListNode(0);
		ListNode* preright = head;
		ListNode* preleft;

		while (preright)
		{
			int preval = preright->val;
			preleft = dumphead;
			ListNode* temp = preleft->next;
			while ((temp) && (temp->val < preval))
			{
				preleft = temp;
				temp = temp->next;
			}
			preleft->next = new ListNode(preval);
			preleft->next->next = temp;
			preright = preright->next;
		}
		return dumphead->next;
	}
};
