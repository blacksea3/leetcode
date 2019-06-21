#include "listnode.h"

//16ms, 91.17%

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
	ListNode *detectCycle(ListNode *head) {
		//����ָ��

		//����head���뻷��ʼ��Ϊa,����b(�ܽڵ�����Ϊa+b)
		//��ָ�뽫��ǰ��ָ���Ȧa����,
		//�������ͬʱ��Ȧ��ʼ�㿪ʼ��,��ôӦ����Ȧ��ʼ������
		//���ڿ�ָ����ǰ��a����,��ô���ھ���Ȧ��ʼ��a��(Ȧ�ڵ�)����
		//��������������ָ�����ʼ����ָ�밴ͬ���ٶ���a���Ⱥ���Ȧ��ʼ�㴦����

		//�������
		if (head == nullptr) return nullptr;

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
