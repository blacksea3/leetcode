#include "listnode.h"

//60ms, 98.78%
//�ֳ������ִ����ҵ��е������Ρ���ת���Σ����β���ǰ���
class Solution {
public:
	void reorderList(ListNode* head) {
		//�������
		if (head == nullptr) return;
		if (head->next == nullptr) return;

		//����ָ���ҵ��е�,���������
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* latterhalf = slow->next;
		slow->next = nullptr;

		//��ת����
		//�˹������������,��Ҫ����һ�����
		ListNode* current = latterhalf;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		//���β���ǰ���,��latterhalf��ʼ
		ListNode *ret = head;
		ListNode *temp = NULL;

		while (prev != NULL) {
			temp = prev;
			prev = prev->next;
			temp->next = head->next;
			head->next = temp;
			head = head->next->next;
		}
		return;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//ListNode* l = stringToListNode("[1,2,3,4,5]");
	ListNode* l = stringToListNode("[1,2,3,4]");
	s->reorderList(l);
	return 0;
}
*/
