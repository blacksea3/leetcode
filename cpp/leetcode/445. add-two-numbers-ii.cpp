#include "listnode.h"

//32ms, 90.81%
//¸øvector´æ´¢

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> v1;
		vector<int> v2;
		vector<int> v3;

		while (l1)
		{
			v1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			v2.push_back(l2->val);
			l2 = l2->next;
		}

		int carry = 0;
		int loc1 = (int)v1.size() - 1;
		int loc2 = (int)v2.size() - 1;
		ListNode* dump = new ListNode(0);
		ListNode* pre = dump;
		while (loc1 >= 0 || loc2 >= 0 || carry)
		{
			int n1 = (loc1 >= 0) ? v1[loc1--] : 0;
			int n2 = (loc2 >= 0) ? v2[loc2--] : 0;
			int sum = (n1 + n2 + carry) % 10;
			carry = (n1 + n2 + carry) / 10;
			v3.push_back(sum);
		}

		for (int i = v3.size() - 1; i >= 0; --i)
		{
			ListNode* temp = new ListNode(v3[i]);
			pre->next = temp;
			pre = temp;
		}
		return dump->next;
	}
};
