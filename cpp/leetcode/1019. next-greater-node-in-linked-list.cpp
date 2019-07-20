#include "listnode.h"

//304ms, 71.87%

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
	vector<int> nextLargerNodes(ListNode* head) {
		//���浽vector

		vector<int> v = {};
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		//ʹ��ջ, �������, �����ջ����С��
		stack<int> st;
		vector<int> res(v.size());

		for (int loc = v.size() - 1; loc >= 0; --loc)
		{
			while (!st.empty() && v[loc] >= st.top())
			{
				st.pop();
			}
			if (st.empty()) res[loc] = 0;
			else res[loc] = st.top();
			st.push(v[loc]);
		}

		return res;
	}
};
