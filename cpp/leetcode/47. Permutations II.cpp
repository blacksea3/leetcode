#include "public.h"

//116ms, 19.81%

//use iterative solution, similar to problem 46
// sort first, then insert one item to previous nums( any possible location shall be inserted )
//  note: need to remove duplicate(here I judge these duplicate conditions, then neglect them)

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end()); //sort first

		int nsize = nums.size();
		if (nsize == 1) return vector<vector<int>> {nums};

		vector<vector<int>> nums1, nums2;
		bool isnums1 = true;
		nums1.push_back(vector<int> {});
		nums1[0].push_back(nums[0]);
		int oldnum = nums[0];   //init oldnum

		for (int i = 1; i < nsize; i++)
		{
			bool need_if_unique = (oldnum == nums[i]);

			//insert
			if (isnums1)
			{
				nums2.clear();
				for (int j = 0; j <= i; j++)
				{
					for (int k = 0; k < nums1.size(); k++)
					{
						vector<int> temp = nums1[k];
						temp.insert(temp.begin() + j, nums[i]);
						if (!need_if_unique) nums2.push_back(temp);
						else if (find(nums2.begin(), nums2.end(), temp) == nums2.end())
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
						if (!need_if_unique) nums1.push_back(temp);
						else if (find(nums1.begin(), nums1.end(), temp) == nums1.end())
							nums1.push_back(temp);
					}
				}
				isnums1 = true;
			}
			oldnum = nums[i];
		}
		return (isnums1) ? nums1 : nums2;
	}
};

//84ms, 24.34%

//recursive solution, DFS, similar to problem 46

class Solution {
private:
	vector<vector<int>> res = {};
	unordered_map<int, bool> um = {};

	void DFS(vector<int> nums, vector<int> pre)
	{
		unordered_map<int, bool> DFSum = um;
		for (int i = 0; i < nums.size(); ++i)
		{
			int temp = nums[i];
			if (DFSum[temp]) continue;
			else
			{
				pre.push_back(temp);
				nums.erase(nums.begin() + i);
				if (!nums.empty()) DFS(nums, pre);
				else
				{
					if (find(res.begin(), res.end(), pre) == res.end())
						res.push_back(pre);
				}
				nums.insert(nums.begin() + i, temp);
				pre.pop_back();
				DFSum[temp] = true;
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		for (auto num : nums)
			um[num] = false;

		DFS(nums, vector<int>{});
		return res;
	}
};
