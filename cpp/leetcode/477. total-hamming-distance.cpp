#include "public.h"

//76ms, 57.28%
//ͳ���������ֵĸ���������λ��0��1������
//��������32λ, ��β����ÿһλ��0������1�����ĺ�

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		vector<int> countOne(32, 0);
		vector<int> countZero(32, 0);

		for (int bitIndex = 0; bitIndex < 32; ++bitIndex)
		{
			int mask = 1 << bitIndex;
			for (auto& num : nums)
			{
				if (num&mask) countOne[bitIndex]++;
				else countZero[bitIndex]++;
			}
		}

		int res = 0;

		for (int bitIndex = 0; bitIndex < 32; ++bitIndex)
		{
			res += countOne[bitIndex] * countZero[bitIndex];
		}
		return res;
	}
};
