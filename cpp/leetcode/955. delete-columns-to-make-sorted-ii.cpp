#include "public.h"

//12ms, 81.97%
//贪心+dp
//dp[i] i与i+1比的状态: true: 小于, false: 等于
//初始化全部都等于, 如果当前dp是小于, 那么后面不用比; 
//  如果当前dp是等于, 如果现在是小于则改成小于, 如果现在是等于则不变, 如果现在是大于, 则此轮不用比, 一定得删掉, 且这一轮之前的状态不保留
//  如果dp都小于了, 那么OK了, 如果有等于但是到末尾了, 那么也ok了

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		vector<bool> dp(A.size() - 1, false);
		int remain_equal = A.size() - 1;

		int res = 0;
		int loc = 0;
		while (remain_equal > 0 && loc < A[0].size())
		{
			vector<bool> temp(A.size() - 1, false);
			bool issave = true;
			int temp_remain_equal = remain_equal;
			for (int i = 0; i < A.size() - 1; ++i)
			{
				if (!dp[i])
				{
					if (A[i][loc] > A[i + 1][loc])
					{
						res++;
						issave = false;
						break;
					}
					else if (A[i][loc] < A[i + 1][loc])
					{
						temp[i] = true;
						temp_remain_equal--;
					}
					else temp[i] = false;
				}
				else temp[i] = dp[i];
			}
			if (issave)
			{
				dp = temp;
				remain_equal = temp_remain_equal;
			}
			loc++;
		}
		return res;
	}
};
