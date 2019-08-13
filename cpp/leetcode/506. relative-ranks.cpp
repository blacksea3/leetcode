#include "public.h"

//32ms, 62.08%
//把所有的数字塞到map里面, 键是成绩, 值是名词, 这个map使用greater排序
//然后遍历map即可

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> res(nums.size());
		map<int, int, greater<int>> m;

		for (int i = 0; i < nums.size(); ++i)
		{
			m[nums[i]] = i;
		}

		map<int, int>::iterator iter = m.begin();
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i == 0) res[iter->second] = "Gold Medal";
			else if (i == 1) res[iter->second] = "Silver Medal";
			else if (i == 2) res[iter->second] = "Bronze Medal";
			else res[iter->second] = to_string(i + 1);
			iter++;
		}
		return res;
	}
};
