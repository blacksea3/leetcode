#include "include.h"

#ifdef LEETCODE_141_150
#include "public.h"
#include "leetcode.h"

bool Solution::hasCycle(ListNode * head)
{
	//O(n)�ڴ�ܼ�
	//���ó����ڴ�

	//��������:����ָ��
	if (head == nullptr) return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while (true)
	{
		if (fast->next == nullptr) break;
		if (fast->next->next == nullptr) break;
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}

ListNode * Solution::detectCycle(ListNode * head)
{
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

	while (true)
	{
		if (fast->next == nullptr) break;
		if (fast->next->next == nullptr) break;
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

void Solution::reorderList(ListNode * head)
{
	//�������
	if (head == nullptr) return;
	if (head->next == nullptr) return;

	//����ָ���ҵ��е�,���������
	ListNode* fast = head->next;
	ListNode* slow = head;

	ListNode* latterhalf;

	while (true)
	{
		if (fast->next == nullptr)
		{
			latterhalf = slow->next;
			slow->next = nullptr;
			break;
		}
		if (fast->next->next == nullptr)
		{
			latterhalf = slow->next->next;
			slow->next->next = nullptr;
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}

	//��ת����
	//�˹������������,��Ҫ����һ�����
	ListNode *pre = nullptr;
	ListNode* p2 = latterhalf;
	ListNode* p3;
	while (p2)
	{
		p3 = p2->next;
		p2->next = pre;
		pre = p2;
		p2 = p3;
	}

	//���β���ǰ���,��latterhalf��ʼ
	latterhalf = pre;
	pre = head;

	while (latterhalf)
	{
		ListNode* temp = latterhalf->next;
		latterhalf->next = pre->next;
		pre->next = latterhalf;
		latterhalf = temp;
		pre = pre->next->next;
	}
	return;
}



#else
#endif
