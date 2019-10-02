#include "public.h"

//16ms, 44.48%
//特殊排序:基数排序 

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		else
		{
			int nmax = *max_element(nums.begin(), nums.end());
			//搞清楚这个最大的有多少位,理论上order10_value最大是10
			int order10_value = 0;
			while (nmax > 0)
			{
				nmax /= 10;
				order10_value++;
			}

			//特殊情况,全0
			if (order10_value == 0)
				return 0;
			else
			{
				//正式基数排序
				vector<long long> constants = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,
					1000000000, 10000000000 };

				for (int i = 1; i <= order10_value; i++)  //i是位数
				{
					vector<vector<int>> base(10);
					for (auto& num : nums)
					{
						base[num % constants[i] / constants[i - 1]].emplace_back(num);
					}
					//合并至nums
					nums.clear();
					for (auto& b:base)
					{
						nums.insert(nums.end(), b.begin(), b.end());
					}
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

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,3,100 };
	cout << s->maximumGap(nums);
	return 0;
}
*/
