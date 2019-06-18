#include "public.h"

//8ms, 95.52%

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//һ�����,��ס���±�1��ʼ������Ԫ��֮ǰ����СԪ�ز����뵱ǰԪ�رȽϼ���
		int res = 0;
		int premin = INT_MAX;
		for (int i = 1; i < prices.size(); i++)
		{
			premin = min(premin, prices[i - 1]);
			res = max(res, prices[i] - premin);
		}
		return res;
	}
};
