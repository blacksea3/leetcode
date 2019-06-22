#include "public.h"

//4ms, 98.18%

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//��ŵ�ǰ�����ֵ����Сֵ
		//�������0,��ǰ���ֵ����Сֵ������0
		//�����������,��չ
		//�����������,����
		int res = INT_MIN;
		int smax = 1;
		int smin = 1;
		for (auto num : nums)
		{
			if (num < 0) swap(smax, smin); //����
			smax = max(smax*num, num);
			smin = min(smin*num, num);
			res = max(res, smax);
		}
		return res;
	}
};
