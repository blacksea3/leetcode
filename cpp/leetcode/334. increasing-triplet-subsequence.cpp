#include "public.h"

//12ms, 46.96%
//一遍扫描nums, 记录两个min:
//先填充, 然后如果当前数字比后一个min大那么true, 如果小, 去掉一个min, 再比较
//其实就相当于单调栈

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		bool minmindump = true;
		bool minmiddump = true;
		int minmin = -1;
		int minmid = -1;

		for (auto &n : nums)
		{
			if (minmindump)
			{
				minmin = n;
				minmindump = false;
			}
			else if (minmiddump)
			{
				if (n < minmin)
				{
					minmin = n;
				}
				else if (n > minmin)
				{
					minmid = n;
					minmiddump = false;
				}
			}
			else
			{
				if (n < minmid)
				{
					if (n < minmin)
					{
						minmin = n;
						minmiddump = false;
					}
					else if (n > minmin) minmid = n;
				}
				else if (n > minmid) return true;
			}
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,1,2,1,2 };
	//vector<int> nums = { 1,0,0,-1,0,0,1000 };
	cout << s->increasingTriplet(nums);
	return 0;
}
*/
