#include "public.h"

//12ms, 74.70%
//贪心
//P-min, res++; 然后p+max, res--; 然后p-多个min, res+=多个; 然后p+一个大的, res--......

class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int P) {
		if (tokens.size() == 0) return 0;
		sort(tokens.begin(), tokens.end());
		if (tokens[0] > P) return 0;
		else
		{
			int left = 0;
			int right = tokens.size() - 1;
			int res = 0;
			int realres = 0;
			//循环模拟
			while (left <= right)
			{
				//减多个小的
				while (left <= right && P >= tokens[left])
				{
					P -= tokens[left];
					left++;
					res++;
				}
				realres = max(res, realres); //最大值出现在不能减小的的情况
				//加一个大的
				if (left <= right)
				{
					P += tokens[right];
					right--;
					res--;
				}
			}
			return realres;
		}
	}
};
