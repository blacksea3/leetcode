#include "public.h"

//DP problem, 12ms, 98.57%

class Solution {
public:
	int minCut(string s) {
		//应当注意到 当分割次数最少时，这些回文字串的长度对于中心处是最长的
		//设置dp[i]表示第i下标处的最少分割次数 d初始化INTMAX
		//从每个位置都往外扩散 若是回文 dp扩展位置值等于左边界外dp加一或者不变
		int ssize = s.size();

		vector<int> dp(ssize, 0);
		for (int i = 0; i < ssize; i++)
			dp[i] = i;

		for (int i = 0; i < ssize; i++)
		{
			//判断回文
			int left = i;
			int right = i;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
		}

		return dp[ssize - 1];
	}
};