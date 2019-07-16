#include "public.h"

//24ms, 25.60%
//背包问题
//相当于把stones分成两堆, 大家都要接近总重量sum的一半, 那么必然有一堆<=sum/2(无论sum奇数还是偶数)
//因此dp可解, 使用set

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		set<int, greater<int>> dp;
		dp.insert(0);

		for (int i = 0; i < stones.size(); ++i)
			for (auto& s : dp)
				if (s + stones[i] <= sum / 2) dp.insert(s + stones[i]);
		return sum - 2 * (*dp.begin());
	}
};
