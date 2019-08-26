#include "listnode.h"

//52ms, 82.81%
//将G转成unordered_set, 然后进行对连续查询

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
	int numComponents(ListNode* head, vector<int>& G) {
		int res = 0;
		bool prefind = false;
		unordered_set<int> us(G.begin(), G.end());

		ListNode* pre = head;
		while (pre)
		{
			if (!prefind)
			{
				if (us.find(pre->val) != us.end()) prefind = true;
			}
			else
			{
				if (us.find(pre->val) == us.end())
				{
					prefind = false;
					res++;
				}
			}
			pre = pre->next;
		}
		return (prefind) ? res + 1 : res;

	}
};
