#include "public.h"

//60ms, 49.11%
//展开绝对值表达式, 然后使用dp以及保存从右边数的sum_p最大,sum_n最小,del_p最大,del_n最小

class Solution {
public:
	int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		vector<int> sum_p(arr1.size(), 0);
		vector<int> sum_n(arr1.size(), 0);
		vector<int> del_p(arr1.size(), 0);
		vector<int> del_n(arr1.size(), 0);

		for (int i = 0; i < arr1.size(); ++i)
		{
			sum_p[i] = arr1[i] + arr2[i] + i;
			sum_n[i] = arr1[i] + arr2[i] - i;
			del_p[i] = arr1[i] - arr2[i] + i;
			del_n[i] = arr1[i] - arr2[i] - i;
		}

		vector<vector<int>> dp(arr1.size(), vector<int>(4, 0));
		vector<int> prem(4);
		prem[0] = INT_MIN;  //分别存从右边数的sum_p最大,sum_n最小,del_p最大,del_n最小
		prem[1] = INT_MAX;
		prem[2] = INT_MIN;
		prem[3] = INT_MAX;
		for (int i = arr2.size() - 1; i >= 0; --i)
		{
			prem[0] = max(prem[0], sum_p[i]);
			dp[i][0] = prem[0];
			prem[1] = min(prem[1], sum_n[i]);
			dp[i][1] = prem[1];
			prem[2] = max(prem[2], del_p[i]);
			dp[i][2] = prem[2];
			prem[3] = min(prem[3], del_n[i]);
			dp[i][3] = prem[3];
		}

		int resmax = 0;

		for (int i = 0; i < arr1.size() - 1; ++i)
		{
			resmax = max(resmax, max(
				max(dp[i + 1][0] - sum_p[i], sum_n[i] - dp[i + 1][1]),
				max(dp[i + 1][2] - del_p[i], del_n[i] - dp[i + 1][3])
			));
		}
		return resmax;
	}
};
