#include "public.h"

//48ms, 92.02%
//ÿ���ƶ��൱�ڸ�1��Ԫ�ؼ�1
//�ҵ���Сֵ, ��Ķ������Ǹ�ֵ����

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int res = 0;
		int minval = *min_element(nums.begin(), nums.end());

		for (auto& num : nums) res += num - minval;
		return res;
	}
};
