#include "public.h"

//8ms, 87.38%
//һ�����,��ס���±�1��ʼ������Ԫ��֮ǰ����СԪ�ز����뵱ǰԪ�رȽϼ���
//ע�⣺���ܴ�����ò���뵱ǰԪ�رȽϵ�Ԫ�ؿ��ܻ�����������Ӱ����

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		
		int res = 0;
		int premin = INT_MAX;
		for (int i = 0; i < prices.size(); i++)
		{
			premin = min(premin, prices[i]);
			res = max(res, prices[i] - premin);
		}
		return res;
	}
};
