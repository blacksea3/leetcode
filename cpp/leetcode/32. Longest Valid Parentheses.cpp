#include "public.h"

//12ms, 95.79%

//use stack

//the value in stack means the loc of '('s.
//for there only one value in stack, just update the loc of (may occur) first '(' - 1  (this is the present i)
//so for init : applying stack.push(-1)

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		st.push(-1);
		int ssize = s.size();
		int res = 0;
		for (int i = 0; i < ssize; i++)
		{
			if (s[i] == '(') st.push(i);
			else
			{
				st.pop();
				if (st.empty()) st.push(i);
				else res = max(res, i - st.top());
			}
		}
		return res;
	}
};