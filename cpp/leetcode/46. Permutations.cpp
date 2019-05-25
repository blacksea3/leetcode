#include "public.h"

//20ms, 95.03%

//(divide and conquer)iterative solution: 
//  we can cacluate the res of nums[0:-1] then add the last num to all the possible location

//iterative this, note that we start from one single(here the first) num of nums

/*
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 1) return vector<vector<int>> {nums};

		vector<vector<int>> nums1, nums2;
		bool isnums1 = true;
		nums1.push_back(vector<int> {});
		nums1[0].push_back(nums[0]);

		for (int i = 1; i < nsize; i++)
		{
			//for exm:cacluate the res of nums[0:-1] then 
			//  add the last num to all the possible location
			if (isnums1)
			{
				nums2.clear();
				for (int j = 0; j <= i; j++)
				{
					for (int k = 0; k < nums1.size(); k++)
					{
						vector<int> temp = nums1[k];
						temp.insert(temp.begin() + j, nums[i]);
						nums2.push_back(temp);
					}
				}
				isnums1 = false;
			}
			else
			{
				nums1.clear();
				for (int j = 0; j <= i; j++)
				{
					for (int k = 0; k < nums2.size(); k++)
					{
						vector<int> temp = nums2[k];
						temp.insert(temp.begin() + j, nums[i]);
						nums1.push_back(temp);
					}
				}
				isnums1 = true;
			}
		}
		return (isnums1) ? nums1 : nums2;
	}
};
*/

//16ms, 97.80%

//DFS, recursive solution

class Solution {
private:
	vector<vector<int>> res = {};

	void DFS(vector<int> nums, vector<int> pre)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			int temp = nums[i];
			pre.push_back(temp);
			nums.erase(nums.begin() + i);
			if (!nums.empty()) DFS(nums, pre);
			else res.push_back(pre);
			nums.insert(nums.begin() + i, temp);
			pre.pop_back();
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		DFS(nums, vector<int>{});
		return res;
	}
};
