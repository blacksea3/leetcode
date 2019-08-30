#include "public.h"

//0ms, 100%
//除数最大, 被除数最小, 因此将第二个开始的数字括起来就可以
//注意边界条件

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		if (nums.size() > 2)
		{
			string res = "";
			res += to_string(nums[0]) + "/(";
			res += to_string(nums[1]);
			for (int index = 2; index < nums.size(); ++index)
			{
				res += "/" + to_string(nums[index]);
			}
			res += ")";
			return res;
		}
		else
		{
			string res = "";
			res += to_string(nums[0]);
			if (nums.size() == 2)
			{
				res += "/" + to_string(nums[1]);
			}
			return res;
		}
	}
};