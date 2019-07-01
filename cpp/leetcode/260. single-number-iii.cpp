#include "public.h"

//16ms, 90.54%
//λ����
//��ȫ�����һ��
//�õ�������ͬ���ֵ����ֵ
//Ȼ��Ѱ�ҵ����ֵ����ĩβһ��1(������λ�õ�1)

//��������, �����bitΪ1,��Ϊһ��;Ϊ0��Ϊ��һ��
//��ô����ֻ����һ�ε����ֱ�Ȼ�ֿ�����������

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (auto& n : nums) s ^= n;

		int mask = s & (-s) & 0x7FFFFFFF;

		vector<int> res(2, 0);
		for (auto& n : nums)
		{
			if (n&mask) res[0] ^= n;
			else res[1] ^= n;
		}
		return res;
	}
};
