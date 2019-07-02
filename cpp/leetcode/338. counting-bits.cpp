#include "public.h"

//80ms, 92.35%
//��������Ĺ���:
//ÿ������n��1������ȡ�������ĩβ�Ƿ���1�Լ�������2������(int)n/2��1�ĸ���

class Solution {
public:
	vector<int> countBits(int num) {
		//ÿ�θ���2^n����
		vector<int> res(num + 1, 0);

		for (int i = 1; i <= num; ++i)
			res[i] = res[i >> 1] + i % 2;

		return res;
	}
};


/*
128ms, 32.84%
//��������Ĺ���:
//ע�⵽: ����: �ʼ��4���������4�����������Ͻ�����һ������λ
//�����µĹ���: 0 -> 0 1 -> 01 12 -> 01121223
//ÿ�μ���1,2,4,8...������������, ��2^n��ֵ����ǰ2^n��ֵ���λ�ü�1

class Solution {
public:
	vector<int> countBits(int num) {
		//ÿ�θ���2^n����
		int prelen = 1;
		vector<int> res(1, 0);

		while (2 * prelen <= num + 1)
		{
			for (int i = 0; i < prelen; ++i)
				res.push_back(res[i] + 1);
			prelen *= 2;
		}
		//���һ�����
		for (int i = 0; i < (num + 1 - prelen); ++i)
			res.push_back(res[i] + 1);

		return res;
	}
};
*/

