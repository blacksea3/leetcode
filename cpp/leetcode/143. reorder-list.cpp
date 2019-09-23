#include "listnode.h"

//60ms, 98.78%
//分成三部分处理：找到中点分离后半段、反转后半段，后半段插入前半段
class Solution {
public:
	void reorderList(ListNode* head) {
		//特殊情况
		if (head == nullptr) return;
		if (head->next == nullptr) return;

		//快慢指针找到中点,分离出后半段
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* latterhalf = slow->next;
		slow->next = nullptr;

		//反转后半段
		//人工拆成两个链表,不要混在一起操作
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

		//后半段插入前半段,从latterhalf开始
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
