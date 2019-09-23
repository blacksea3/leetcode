#include "listnode.h"

//56ms, 98.72%
//原地算法
//归并排序

class Solution {
private:
	//外部确保head不为空
	ListNode* iter_sortList(ListNode* head)
	{
		if (head->next == nullptr) return head;

		//用双指针切割链表
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
		//slow->next为后半链表

		ListNode* lefthalf = head;
		ListNode* righthalf = slow->next;
		slow->next = nullptr;
		lefthalf = iter_sortList(lefthalf);
		righthalf = iter_sortList(righthalf);

		//合并
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
		if (head == nullptr) return nullptr;  //此处仅首次调用
		return iter_sortList(head);
	}
};

