#include "public.h"

//56ms, 87.25%
//分治
//一定是从nums1中取i个数, 从nums2中取k-i个数

class Solution {
private:
	vector<int> extract(vector<int>& nums, int k)
	{
		vector<int> max(k, 0);
		for (int i = 0, j = 0; i < nums.size(); i++) {
			while (j > 0 && k - j < nums.size() - i && max[j - 1] < nums[i]) j--;
			if (j < k) max[j++] = nums[i];
		}
		return max;
	}

	bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j)
	{
		while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
		{
			i++;
			j++;
		}
		return j == nums2.size() || (i<nums1.size() && nums1[i]>nums2[j]);
	}

	vector<int> merge(vector<int>& nums1, vector<int>& nums2)
	{
		int loc1 = 0;
		int loc2 = 0;
		vector<int> res(nums1.size()+nums2.size());
		while ((loc1 + loc2) < res.size())
		{
			if (greater(nums1, loc1, nums2, loc2))
			{
				res[loc1 + loc2] = nums1[loc1];
				loc1++;
			}
			else
			{
				res[loc1 + loc2] = nums2[loc2];
				loc2++;
			}
		}
		return res;
	}

public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res(k, 0);
		for (int i = max(0, k - (int)nums2.size()); i <= min((int)nums1.size(), k); ++i)
		{
			vector<int> exnums1 = extract(nums1, i);
			vector<int> exnums2 = extract(nums2, k - i);
			vector<int> temp = merge(exnums1, exnums2);
			if (greater(temp, 0, res, 0)) res = temp;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> nums1 = { 3, 4, 6, 5 };
	//vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
	vector<int> nums1 = { 6,7 };
	vector<int> nums2 = { 5,0,4 };
	vector<int> res = s->maxNumber(nums1, nums2, 5);
	return 0;
}
*/
