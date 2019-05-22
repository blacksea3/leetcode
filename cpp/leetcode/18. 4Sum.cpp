#include "public.h"

//16ms, 99.62%

//similar to problem15: 3 Sum
//use a BIG iteration outside 3 Sum algorithm

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int nlen = nums.size();
		//border input: nums.size() < 4 is A FUCK input
		if (nlen < 4) return vector<vector<int>> {};

		//sort first
		std::sort(nums.begin(), nums.end());

		//border input: targer is SO HIGH or SO LOW
		if (nums[0] + nums[1] + nums[2] + nums[3] > target) return vector<vector<int>> {};
		if (nums[nlen - 1] + nums[nlen - 2] + nums[nlen - 3] + nums[nlen - 4] < target) return vector<vector<int>> {};

		vector<vector<int>> returnv;

		for (int i = 0; i < nlen - 2; i++)    //
		{
			if (i && (nums[i] == nums[i-1])) continue;
			vector<vector<int>> three_sum_res;
			//use three_sum_target function
			three_sum_res = three_sum_target(nums, target - nums[i], i + 1, nlen - 1);

			for (int j = 0; j < three_sum_res.size(); j++)
			{
				three_sum_res[j].insert(three_sum_res[j].begin(), nums[i]);
				returnv.push_back(three_sum_res[j]);
			}
		}
		return returnv;
	}

	//similar to problem 15: 3 Sum
	vector<vector<int>> three_sum_target(vector<int>& nums, int target, int startloc, int endloc) {
		vector<vector<int>> returnv = {};

		for (int i = startloc; i <= endloc - 2; i++)
		{
			if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;
			if ((i > startloc) && (nums[i] == nums[i-1])) continue;
			int iter_target = target - nums[i];
			int left = i + 1;
			int right = endloc;
			while (left < right)
			{
				if ((nums[left] + nums[right]) < iter_target) left++;
				else if ((nums[left] + nums[right]) > iter_target) right--;
				else
				{
					vector<int> temp = { nums[i], nums[left], nums[right] };
					returnv.push_back(temp);
					while ((left < right) && (nums[left] == nums[left + 1])) left++;
					while ((left < right) && (nums[right] == nums[right - 1])) right--;
					left++; right--;
				}
			}
		}
		return returnv;
	}
};