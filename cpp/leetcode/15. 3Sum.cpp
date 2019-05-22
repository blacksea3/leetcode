#include "public.h"

//148ms, 92.95%

//对nums排序后可以：迭代第一个数,并且对余下的数进行二分查找
//注意剪枝：如果第一个数已经比0大了/第一个数是重复的（和上一个数比），那么可以结束迭代/跳过迭代
//二分查找时注意剪枝：如果已经找到了合适的三元对，如果有数字和后两个数是重复的则跳过他，
//  注意：仅需要比较当前left与left+1/right与right-1即可，这是因为找到了合适的三元对一定是此组合的首个三元对，与之前不同
//  但若无这个剪枝步骤，后面会有三元对与此相同

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> returnv = {};
		std::sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size - 2; i++)
		{
			if (nums[i] > 0) break;
			if (i&&(nums[i] == nums[i-1])) continue;  //注意：你应当和之前的i比较，来剪枝重复情况
			int target = -1 * nums[i];
			int left = i + 1;
			int right = size - 1;
			while (left < right)
			{
				if ((nums[left] + nums[right]) < target) left++;
				else if ((nums[left] + nums[right]) > target) right--;
				else
				{
					vector<int> temp = { nums[i], nums[left], nums[right] };
					returnv.push_back(temp);
					while ((left < right) && (nums[left] == nums[left + 1])) left++;
					while ((left < right) && (nums[right] == nums[right - 1])) right--;
					left++; 
					right--;
				}
			}
		}
		return returnv;
	}
};
