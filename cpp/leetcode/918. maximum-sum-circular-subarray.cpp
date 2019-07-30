#include "public.h"

//164ms, 7.78%
//贪心
//从左边开始presum, premax扫过去, 如果presum<0, 更新premax, 重置presum=0; 最后再更新一次premax

//关键是这个环: 如果重置过记录一下被重置的位置, 然后倒着扫过去, 如果presum能够<0, 那么停止, 拿当前premax+leftmax
//否则一直扫到被重置的位置再停止

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		//如果最大数<0, 那么就返回最大数(负数)
		int maxValue = *max_element(A.begin(), A.end());
		//如果最小数>0, 那么返回所有数之和sum
		int minValue = *min_element(A.begin(), A.end());
		if (maxValue < 0) return maxValue;
		else if (minValue > 0) return accumulate(A.begin(), A.end(), 0);

		int premax = 0;
		int presum = 0;
		int leftmax = 0;
		int resmax = 0;
		int updateloc = 0;
		bool isupdated = false;

		for (int i = 0; i < A.size(); ++i)
		{
			int a = A[i];
			if (a >= 0)
			{
				presum += a;
				premax = max(premax, presum);
				resmax = max(resmax, premax);
			}
			else
			{
				presum += a;
				if (presum < 0)
				{
					if (!isupdated)
					{
						leftmax = premax;
						isupdated = true;
						updateloc = i;
					}
					premax = 0;
					presum = 0;
				}
			}
		}
		{
			//两端同时扫, 求leftmax和rightmax
			vector<int> lm(A.size());
			vector<int> rm(A.size());

			int presum = 0;
			int premax = 0;
			for (int i = 0; i < A.size(); ++i)
			{
				presum += A[i];
				premax = max(presum, premax);
				lm[i] = premax;
			}
			presum = 0;
			premax = 0;
			for (int i = A.size() - 1; i >= 0; --i)
			{
				presum += A[i];
				premax = max(presum, premax);
				rm[i] = premax;
			}

			int thiswaymaxsum = 0;
			for (int i = 0; i < A.size() - 1; ++i)
			{
				thiswaymaxsum = max(thiswaymaxsum, lm[i] + rm[i + 1]);
			}
			resmax = max(resmax, thiswaymaxsum);
		}

		return resmax;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 1,-2,3,-2 };
	vector<int> A = { 5,-3,5 };
	cout << s->maxSubarraySumCircular(A);
	return 0;
}
*/
