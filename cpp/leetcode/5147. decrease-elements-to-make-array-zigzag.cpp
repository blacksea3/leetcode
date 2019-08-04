#include "public.h"

//
//直接减奇数索引

class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int res1 = 0;

		//A[0] > A[1] < A[2] > A[3] < A[4] > ...
		//情况1
		for (int i = 1; i < nums.size(); i += 2)
		{
			if (i != nums.size() - 1)
			{
				if (min(nums[i - 1], nums[i + 1]) > nums[i])
				{
					continue;
				}
				else
					res1 += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
			}
			else
			{
				if (nums[i - 1] > nums[i]) continue;
				else res1 += nums[i] - nums[i - 1] + 1;
			}
		}

		//A[0] < A[1] > A[2] < A[3] > A[4] < ...
		int res2 = 0;
		//情况2
		for (int i = 0; i < nums.size(); i += 2)
		{
			if (i == 0)
			{
				if (nums[1] > nums[0]) continue;
				else res2 += nums[0] - nums[1] + 1;
			}
			else if (i == nums.size() - 1)
			{
				if (nums[i - 1] > nums[i]) continue;
				else res2 += nums[i] - nums[i - 1] + 1;
			}
			else
			{
				if (min(nums[i - 1], nums[i + 1]) > nums[i])
				{
					continue;
				}
				else
					res2 += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
			}
		}
		return min(res1, res2);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> fuck1 = { 1,2,3 };
	vector<int> fuck2 = { 9,6,1,6,2 };
	cout << s->movesToMakeZigzag(fuck1);
	cout << s->movesToMakeZigzag(fuck2);
	return 0;
}
*/
