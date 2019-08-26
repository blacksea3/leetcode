#include "public.h"

//4ms, 92.58%
//反向DP
//不如先对bits reverse, 然后去掉第一个0, 设置dp[i]表示前i个的字符是否可以编码, dp[0] = true;
//此时合适的编码为0, 01, 11

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		bits.pop_back();
		reverse(bits.begin(), bits.end());

		vector<bool> dp(bits.size() + 1, false);
		dp[0] = true;

		for (int index = 0; index < bits.size(); ++index)
		{
			if (index == 0)
			{
				if (bits[index] == 0) dp[1] = true;
			}
			else
			{
				if (bits[index] == 0)
				{
					if (dp[index])
					{
						dp[index + 1] = true;
						continue;
					}
				}
				else
				{
					if (dp[index - 1])
					{
						dp[index + 1] = true;
						continue;
					}
				}
			}
		}
		return dp[bits.size()];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> bits = { 1,0,0 };
	cout << s->isOneBitCharacter(bits);
	return 0;
}
*/