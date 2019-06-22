#include "public.h"

//特殊排序:基数排序 16ms, 77.31%

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		//基数排序
		//都是非负整数!
		if (nums.size() <= 1) return 0;
		else
		{
			int nmax = 0;
			//先搞清楚最大的
			for (auto& num : nums) nmax = max(num, nmax);

			//搞清楚这个最大的有多少位,理论上order10_value最大是10
			int order10_value = 0;
			while (nmax > 0)
			{
				nmax /= 10;
				order10_value++;
			}

			//特殊情况,全0?????
			if (order10_value == 0)
				return 0;
			else
			{
				//正式基数排序
				vector<queue<int>> base(10, queue<int>{});
				vector<int> constants = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

				for (int i = 1; i <= order10_value; i++)  //i是位数
				{
					for (auto& num : nums)
					{
						if (i < 10)
							base[num%constants[i] / constants[i - 1]].push(num);
						else
							base[num / constants[i - 1]].push(num);
					}
					//合并至nums
					vector<int> newnums = {};
					for (auto& qb : base)
					{
						while (!qb.empty())
						{
							newnums.push_back(qb.front());
							qb.pop();
						}
					}
					nums = newnums;
					//nums.clear();
					//nums.assign(newnums.begin(), newnums.end());
				}

				//排序结束,查找最大差值
				int maxdiff = 0;
				for (int i = 1; i < nums.size(); i++)
					maxdiff = max(nums[i] - nums[i - 1], maxdiff);

				return maxdiff;
			}
		}
	}
};
