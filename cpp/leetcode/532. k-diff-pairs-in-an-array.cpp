#include "public.h"

//112ms, 14.08%
//��numsת��searched��res
//res���������Ľ�Сֵ
//���set��С

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;

		set<int> searched;
		set<int> res;

		for (auto& num : nums)
		{
			if (searched.find(num - k) != searched.end())
			{
				res.insert(num - k);
			}
			if (searched.find(num + k) != searched.end())
			{
				res.insert(num);
			}
			searched.insert(num);
		}
		return res.size();
	}
};
