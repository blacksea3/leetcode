#include "public.h"

//904ms, 6.38%
//应当倒过来操作
//设置这样的dp值: dp[i][0]表示从i开始经过奇数跳可以到终点, dp[i][1]表示从i开始经过偶数跳可以到终点
//在倒序遍历的途中记录unordered_map<int, int>: 是val, index, 再记录一个vector<int>是val升序, 用lower_bound查找和插入值
//dp[i][0]:找最小的val>=A[i], 然后dp[i][0]=dp[index][1]
//dp[i][1]:找最小的val<=A[i], 然后dp[i][1]=dp[index][0]
//初始化dp[A.size()-1][0]=true, dp[A.size()-1][1]=true

class Solution {
public:
	int oddEvenJumps(vector<int>& A) {
		vector<vector<bool>> dp(A.size(), vector<bool>(2, false));
		dp[A.size() - 1][0] = true;
		dp[A.size() - 1][1] = true;

		unordered_map<int, int> ps;
		vector<int> p_vals;

		ps[A[A.size() - 1]] = A.size() - 1;
		p_vals.push_back(A[A.size() - 1]);

		for (int i = A.size() - 2; i >= 0; --i)
		{
			vector<int>::iterator piter = lower_bound(p_vals.begin(), p_vals.end(), A[i]);
			if (piter == p_vals.end())
				dp[i][0] = false;
			else
				dp[i][0] = dp[ps[*piter]][1];

			if (piter != p_vals.end() && *piter == A[i])
				dp[i][1] = dp[ps[*piter]][0];
			else
			{
				if (piter == p_vals.begin())
					dp[i][1] = false;
				else
					dp[i][1] = dp[ps[*(piter - 1)]][0];
			}

			if (piter != p_vals.end() && *piter == A[i])
			{
				ps[A[i]] = i;
			}
			else
			{
				ps[A[i]] = i;
				p_vals.insert(piter, A[i]);
			}
		}

		int res = 0;
		for (int i = 0; i < dp.size(); ++i)
		{
			if (dp[i][0]) res++;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 5, 1, 3, 4, 2 };
	auto res = s->oddEvenJumps(A);
	return 0;
}
*/
