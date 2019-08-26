#include "public.h"

//28ms, 98.18%
//单调栈

class Solution {
public:
	int longestWPI(vector<int>& hours) {
		int hsize = hours.size();
		//int* sum = new int[hsize + 1];
		vector<int> sum(hsize + 1, 0);
		int res = 0;

		for (int i = 0; i < hsize; ++i)
		{
			if (hours[i] > 8) sum[i + 1] = sum[i] + 1;
			else sum[i + 1] = sum[i] - 1;
		}

		//单调栈
		stack<int> st;

		//init
		for (int i = 0; i <= hsize; ++i)
			if (st.empty() || sum[st.top()] > sum[i]) st.push(i);

		//cal
		int loc = hsize;
		while (loc > res)
		{
			while ((!st.empty()) && (sum[loc] > sum[st.top()]))
			{
				res = max(res, loc - st.top());
				st.pop();
			}
			loc--;
		}

		return res;
	}

};
