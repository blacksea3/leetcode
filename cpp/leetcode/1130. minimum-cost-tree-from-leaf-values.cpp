#include "public.h"

//48ms, 13.51%
//dp[i][j]:�±�i���±�j�ĵ�ǰ���ֵ

//�����ȸ���dp, ��ʼ������1: dp[i][i]=0, ����: dp[i][j] = max(�������: dp[i][k] + dp[k][j] + ������Χ�����ֵ�˻�, i<=k<=j)
//���ȡarr[0][arr.size()-1]

class Solution {
private:
	int get_range_max(const vector<int>& arr, int s, int e)
	{
		int res = arr[s];
		for (int i = s + 1; i <= e; ++i)
			res = max(res, arr[i]);
		return res;
	}

public:
	int mctFromLeafValues(vector<int>& arr) {
		vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

		for (int len = 2; len <= arr.size(); ++len)
		{
			for (int start = 0; start <= arr.size() - len; ++start)
			{
				int tempmax = INT_MAX;
				int tempend = start + len - 1;
				for (int k = start; k < tempend; ++k)
				{
					tempmax = min(tempmax, dp[start][k] + dp[k + 1][tempend] +
						get_range_max(arr, start, k)*get_range_max(arr, k + 1, tempend));
				}
				dp[start][tempend] = tempmax;
			}
		}
		return dp[0][arr.size() - 1];
	}
};
