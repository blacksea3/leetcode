#include "listnode.h"

//16ms, 75.62%
//快慢指针
//假设head距离环起始处为a,环长b(总节点数即为a+b)
//快指针将提前慢指针进圈a长度,
//如果二者同时在圈起始点开始走,那么应当在圈起始点相遇
//现在快指针提前了a长度,那么将在距离圈起始点a处(圈内的)相遇
//这样从相遇出的指针和起始处的指针按同样速度走a长度后将在圈起始点处相遇

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//第一部分
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) goto step2;
		}
		return nullptr;

		//第二部分
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
