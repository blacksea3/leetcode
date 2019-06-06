#include "public.h"

//DFS, brute force, 332ms, 90.87%

class Solution {
private:
	set<vector<int>> res = {};
	void DFS(const vector<int>& nums, int preloc, vector<int>& prenums)
	{
		if (prenums.size() >= 2) res.insert(prenums);
		for (int i = preloc; i < nums.size(); ++i)
		{
			if (prenums.empty() || (nums[i] >= prenums[prenums.size() - 1]))
			{
				prenums.push_back(nums[i]);
				DFS(nums, i + 1, prenums);
				prenums.pop_back();
			}
		}
	}

public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> prenums = {};
		DFS(nums, 0, prenums);
		return vector<vector<int>>(res.begin(), res.end());
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,3,1 };
	vector<vector<int>> res = s->findSubsequences(nums);
	return 0;
}

