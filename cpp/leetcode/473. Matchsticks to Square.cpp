#include "public.h"

//112ms, 36.11% :(

//Note that nums.size() <= 15, so just use BRUTE FORCE with recursive
// First, cal the sum of nums, if sum%4 != 0, return false
// Second, DFS the (nums, presum:four items list, preloc, target_average_value
//   traverse the loc of each num, if corresponding sum > target_average_value, backtrack it
//   if all the nums are placed, then is ok! return true

class Solution {
private:
	bool DFS(const vector<int>& nums, vector<int>& sum, int preloc, const int& target, const int& maxloc)
	{
		if (preloc == maxloc)
			return true;
		for (int i = 0; i <= 3; ++i)
		{
			if ((sum[i] + nums[preloc]) > target) continue;
			else
			{
				sum[i] += nums[preloc];
				if (DFS(nums, sum, preloc + 1, target, maxloc)) return true;
				sum[i] -= nums[preloc];
			}
		}
		return false;
	}

	static bool mycmp(const int& a, const int& b) {
		return a > b;
	}

public:
	bool makesquare(vector<int>& nums) {
		int res = 0;
		for (auto s : nums) res += s;

		if ((res % 4 != 0) || (res == 0)) return false;
		else
		{
			sort(nums.begin(), nums.end(), mycmp);
			vector<int> sum = { 0,0,0,0 };
			return DFS(nums, sum, 0, res / 4, nums.size());
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> nums = { 1,1,2,2,2 };
	vector<int> nums = { 5,5,5,5,4,4,4,4,3,3,3,3 };
	cout << s->makesquare(nums);
	return 0;
}
*/
