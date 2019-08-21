#include "public.h"

//84ms, 32.90%
//一轮扫描得到各数字的频数已经每个数字的开头结尾位置
//对各个数字频数再扫描一次, 根据开头结尾位置得到结果

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> count;
		unordered_map<int, int> start;
		unordered_map<int, int> end;

		for (int index = 0; index < nums.size(); ++index)
		{
			int currentVal = nums[index];
			if (count.find(currentVal) == count.end())
				start[currentVal] = index;
			count[currentVal]++;
			end[currentVal] = index;
		}

		int resMinLen = INT_MAX;
		int resMaxFreVal = INT_MIN;

		for (auto& iter_count : count)
		{
			if (resMaxFreVal < iter_count.second)
			{
				resMaxFreVal = iter_count.second;
				resMinLen = end[iter_count.first] - start[iter_count.first] + 1;
			}
			else if (resMaxFreVal == iter_count.second)
				resMinLen = min(resMinLen, end[iter_count.first] - start[iter_count.first] + 1);
		}

		return resMinLen;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,2,2,3,1};
	cout << s->findShortestSubArray(nums);
	return 0;
}
*/
