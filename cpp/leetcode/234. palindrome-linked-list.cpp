#include "listnode.h"

//24ms, 96.74%
//遍历两遍
//先获取长度,然后对前半段原地reverse,然后双指针分别从head和中间开始往后移动

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
	bool isPalindrome(ListNode* head) {
		int length = 0;
		ListNode* pre = head;
		while (pre)
		{
			pre = pre->next;
			length++;
		}
		if (length == 0) return true;
		if (length == 1) return true;

		//reverse
		int count = 1;
		ListNode* left = head;
		pre = left->next;
		left->next = nullptr;

		while (count < length / 2)
		{
			ListNode* temp = pre;
			pre = pre->next;
			temp->next = left;
			left = temp;
			count++;
		}
		if (length % 2) pre = pre->next;
		//analyse
		while (left)
		{
			if (left->val == pre->val)
			{
				left = left->next;
				pre = pre->next;
			}
			else return false;
		}
		return true;
	}
};
