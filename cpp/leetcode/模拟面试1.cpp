#include "public.h"

//this is problem 132
class Solution {
public:
	int minCut(string s) {
		//dp problem

		//dp[i] means from s[0] to s[i-1], the value of res
		//note dp[0] is dump(0), I want to return dp[ssize]

		//p[i][j] means from s[i] to s[j], whether belongs to palindrome

		int ssize = s.size();

		vector<vector<bool>> p(ssize, vector<bool>(ssize, false));
		for (int i = 0; i < ssize; ++i)
		{
			int left = i;
			int right = i;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				p[left][right] = true;
				left--;
				right++;
			}
		}
		for (int i = 1; i < ssize; ++i)
		{
			int left = i - 1;
			int right = i;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				p[left][right] = true;
				left--;
				right++;
			}
		}

		vector<int> dp(ssize + 1, INT_MAX);
		dp[0] = 0;

		for (int end = 0; end < ssize; ++end)
		{
			for (int start = 0; start <= end; ++start)
			{
				if (p[start][end]) dp[end + 1] = min(dp[end + 1], dp[start] + 1);
			}
		}

		return dp[ssize] - 1;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->minCut("aab");

	return 0;
}
