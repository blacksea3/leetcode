#include "public.h"

//76ms, 57.28%
//统计所有数字的各个二进制位的0和1的数量
//对于所有32位, 结尾等于每一位的0数量乘1数量的和

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
