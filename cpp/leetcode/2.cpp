#include "public.h"

#include "listnode.h"

//32ms 98.92%

//注意我使用了dump头节点
//然后注意进位细节


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		bool carry = false;
		ListNode* dump = new ListNode(NULL);
		ListNode* old_ln = dump;

		while ((l1) && (l2))
		{
			int new_res = l1->val + l2->val;
			if (carry) new_res++;
			if (new_res >= 10)
			{
				new_res -= 10;
				carry = true;
			}
			else
			{
				carry = false;
			}
			ListNode* new_ln = new ListNode(new_res);
			old_ln->next = new_ln;
			old_ln = new_ln;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1)
		{
			while (l1)
			{
				int new_res = l1->val;
				if (carry) new_res++;
				if (new_res >= 10)
				{
					new_res -= 10;
					carry = true;
				}
				else
				{
					carry = false;
				}
				ListNode* new_ln = new ListNode(new_res);
				old_ln->next = new_ln;
				old_ln = new_ln;
				l1 = l1->next;
			}
			if (carry)
			{
				ListNode* new_ln = new ListNode(1);
				old_ln->next = new_ln;
				old_ln = new_ln;
			}
		}
		else if (l2)
		{
			while (l2)
			{
				int new_res = l2->val;
				if (carry) new_res++;
				if (new_res >= 10)
				{
					new_res -= 10;
					carry = true;
				}
				else
				{
					carry = false;
				}
				ListNode* new_ln = new ListNode(new_res);
				old_ln->next = new_ln;
				old_ln = new_ln;
				l2 = l2->next;
			}
			if (carry)
			{
				ListNode* new_ln = new ListNode(1);
				old_ln->next = new_ln;
				old_ln = new_ln;
			}
		}
		else if (carry)
		{
			ListNode* new_ln = new ListNode(1);
			old_ln->next = new_ln;
			old_ln = new_ln;
		}
		else
			;
		return dump->next;
	}
};

int main()
{
	Solution* s = new Solution();
	ListNode* l1 = initlistnode(vector<int> {2, 4, 3});
	ListNode* l2 = initlistnode(vector<int> {5, 6, 4});
	printlistnode(s->addTwoNumbers(l1, l2));
	l1 = initlistnode(vector<int> {2, 4});
	l2 = initlistnode(vector<int> {5, 6, 4});
	printlistnode(s->addTwoNumbers(l1, l2));
	l1 = initlistnode(vector<int> {2, 4, 3});
	l2 = initlistnode(vector<int> {5, 6});
	printlistnode(s->addTwoNumbers(l1, l2));
	l1 = initlistnode(vector<int> {9, 9, 9});
	l2 = initlistnode(vector<int> {1});
	printlistnode(s->addTwoNumbers(l1, l2));
	return 0;
}
