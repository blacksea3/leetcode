#include "public.h"

/*
//20ms, 38.25%
//贪婪1
//从后往前跳, 如果发现的前面有落脚点就跳, 判断能否跳到起点

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nSize = nums.size();
		int preLoc = nSize - 1;

		while (preLoc > 0)
		{
			int preStartLoc = preLoc - 1;
			while (preStartLoc >= 0)
			{
				if ((nums[preStartLoc] + preStartLoc) >= preLoc)
				{
					preLoc = preStartLoc;
					break;
				}
				preStartLoc--;
			}
			if (preStartLoc < 0) break;
		}
		return (preLoc == 0);
	}
};
*/

//12ms, 88.10%
//贪婪2
//从前往后跳, 每次更新最远坐标, 如果当前坐标超过了当前最远坐标则false, 否则最终true
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxIndex = 0;

		for (int index = 0; index < nums.size(); ++index)
		{
			if (index > maxIndex) return false;
			else maxIndex = max(maxIndex, index + nums[index]);
		}

		return true;
	}
};
