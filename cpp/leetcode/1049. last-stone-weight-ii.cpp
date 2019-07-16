#include "public.h"

//24ms, 25.60%
//��������
//�൱�ڰ�stones�ֳ�����, ��Ҷ�Ҫ�ӽ�������sum��һ��, ��ô��Ȼ��һ��<=sum/2(����sum��������ż��)
//���dp�ɽ�, ʹ��set

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
