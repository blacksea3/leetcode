#include "public.h"

//44ms, 6.85%
//统计自i位置开始包括自己若让后面全是1, 应当翻转的0个数, 那么这情况下实际总反转次数等于i位置之前的1个数+i位置之后的0个数
//这样应当进行两轮线性搜索
//建立一个dp[i][0]与dp[i][1]表示0-i的1个数以及i-最后的0个数, 两两相加求最小值即可, 注意下标0, 统计1, 下标1, 统计0, 这是反的

class Solution {
public:
	int minFlipsMonoIncr(string S) {
		vector<vector<int>> dp(S.size(), vector<int>(2, 0));
		if (S[0] == '1') dp[0][0] = 1;
		for (int i = 1; i < S.size(); ++i)
		{
			if (S[i] == '1') dp[i][0] = dp[i - 1][0] + 1;
			else dp[i][0] = dp[i - 1][0];
		}
		if (S[S.size() - 1] == '0') dp[S.size() - 1][1] = 1;
		for (int i = S.size() - 2; i >= 0; --i)
		{
			if (S[i] == '0') dp[i][1] = dp[i + 1][1] + 1;
			else dp[i][1] = dp[i + 1][1];
		}

		int res = INT_MAX;
		for (int i = 1; i < S.size(); ++i)
			res = min(res, dp[i-1][0] + dp[i][1]);
		res = min(res, dp[S.size() - 1][0]);
		res = min(res, dp[0][1]);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->minFlipsMonoIncr("00110");
	//cout << s->minFlipsMonoIncr("0101100011");
	cout << s->minFlipsMonoIncr("00000000000000000000000000000000000000000000000000000000000000000010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
	return 0;
}
*/
