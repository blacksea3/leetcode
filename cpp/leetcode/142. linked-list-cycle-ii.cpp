#include "listnode.h"

//16ms, 75.62%
//����ָ��
//����head���뻷��ʼ��Ϊa,����b(�ܽڵ�����Ϊa+b)
//��ָ�뽫��ǰ��ָ���Ȧa����,
//�������ͬʱ��Ȧ��ʼ�㿪ʼ��,��ôӦ����Ȧ��ʼ������
//���ڿ�ָ����ǰ��a����,��ô���ھ���Ȧ��ʼ��a��(Ȧ�ڵ�)����
//��������������ָ�����ʼ����ָ�밴ͬ���ٶ���a���Ⱥ���Ȧ��ʼ�㴦����

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//��һ����
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) goto step2;
		}
		return nullptr;

		//�ڶ�����
	step2:
		ListNode* start = head;
		while (start != slow)
		{
			start = start->next;
			slow = slow->next;
		}
		return start;
	}
};
