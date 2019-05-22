#include "public.h"

//12ms, 97.31%

//pay attention: the problem say there must occur only ONE solution, so nums should at least have three items
//solution is similar to problem 15: iterally fix the first item, and then use double pointer, they come from the left and right side
// and will end at a relative middle location(also similar to binary search)
//
//note some prune condition: 1 (border contition): the target may be SO HIGH or SO LOW!
//2 and 3 are euqal to problem 15

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());

		//border condition
		int nsize = nums.size();
		if ((nums[0] + nums[1] + nums[2]) >= target) return (nums[0] + nums[1] + nums[2]);
		if ((nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]) <= target) return (nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]);

		//main loop: iterally fix the first item, and then use double pointer
		int sign_diff_closest_sum = target - (nums[0] + nums[1] + nums[2]);  //dump init value
		for (int outer_loc = 0; outer_loc < nsize; outer_loc++)
		{
			if (outer_loc && (nums[outer_loc - 1] == nums[outer_loc])) continue;

			int new_target = target - nums[outer_loc];
			int left = outer_loc + 1;
			int right = nsize - 1;
			int temp_diff_closest_sum = target - (nums[0] + nums[1] + nums[2]);  //dump init value
			while (left < right)
			{
				if ((nums[left] + nums[right] - new_target) < 0)
				{
					if ((new_target - nums[left] - nums[right]) < abs(temp_diff_closest_sum))
						temp_diff_closest_sum = new_target - nums[left] - nums[right];
					while ((left < right) && (nums[left] == nums[left + 1])) left++;  //merge left++ and dump move left one line, prune
					left++;
				}
				else if ((nums[left] + nums[right] - new_target) > 0)
				{
					if ((nums[left] + nums[right] - new_target) < abs(temp_diff_closest_sum))
						temp_diff_closest_sum = new_target - nums[left] - nums[right];
					while ((left < right) && (nums[right] == nums[right - 1])) right--; //merge right-- and dump move right one line, prune
					right--;
				}
				else return target;
				if (abs(sign_diff_closest_sum) > abs(temp_diff_closest_sum)) sign_diff_closest_sum = temp_diff_closest_sum;
			}
		}
		return (target - sign_diff_closest_sum);
	}
};