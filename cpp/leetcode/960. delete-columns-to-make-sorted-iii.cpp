#include "public.h"

//204ms, 8.00%
//dp[i][j]: i与j都在, 最长满足字典序排序的长度, 按长度扩展
//初始化: dp[i][i] = 1,
//扩展: dp[i][i+len-1](len >= 2) : 分为右扩展与左扩展: 遍历搜索dp[j][k], 其中j>i或者 k<i+len-1, 令半边等于边界,
//  若所有的A[i]同时<=A[j] 且A[i+len-1]>=A[k] 那么记录当前可能长度=dp[j][k]+1,  
//  遍历搜索结束后dp[i][i+len-1] = max当前可能长度, 特别注意极有可能当前可能长度从未被记录, 那么就取它的默认值INT_MIN:)

//最后在每次记录当前可能长度的时候, max(res, pre)一下, 最终返回res即可

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		vector<vector<int>> dp(A[0].size(), vector<int>(A[0].size(), INT_MIN));
		for (int i = 0; i < A[0].size(); ++i)
		{
			dp[i][i] = 1;
		}

		int res = 1;
		for (int len = 2; len <= A[0].size(); ++len)
		{
			for (int i = 0; i <= A[0].size() - len; ++i)
			{
				//cal dp[i][i+len-1]
				int tempmax = INT_MIN;
				//左扩展
				for (int j = i + 1; j <= i + len - 1; ++j)
				{
					if (dp[j][i + len - 1] == INT_MIN) continue;
					else
					{
						bool canexpand = true;
						for (int loca = 0; loca < A.size(); ++loca)
						{
							if ((A[loca][i] <= A[loca][j])) continue;
							else
							{
								canexpand = false;
								break;
							}
						}
						if (canexpand)
						{
							tempmax = max(tempmax, 1 + dp[j][i + len - 1]);
						}
					}
				}
				//右扩展
				for (int k = i + len - 2; k >= i; --k)
				{
					if (dp[i][k] == INT_MIN) continue;
					else
					{
						bool canexpand = true;
						for (int loca = 0; loca < A.size(); ++loca)
						{
							if ((A[loca][k] <= A[loca][i + len - 1])) continue;
							else
							{
								canexpand = false;
								break;
							}
						}
						if (canexpand)
						{
							tempmax = max(tempmax, 1 + dp[i][k]);
						}
					}
				}
				dp[i][i + len - 1] = tempmax;
				res = max(res, tempmax);
			}
		}
		return A[0].size() - res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> A = { "ghi","def","abc" };
	cout << s->minDeletionSize(A);
	vector<string> B = { "babca","bbazb" };
	cout << s->minDeletionSize(B);
	vector<string> C = { "edcba" };
	cout << s->minDeletionSize(C);
	return 0;
}
*/
