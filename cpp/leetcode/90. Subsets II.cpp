#include "public.h"

//use iteration Backtracking or recursive BackTracking

//First: iteration Backtracking: 16ms, 93.54%
/*class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		//回溯
		//初始化:numdict:nums字典计数
		//length:nums长度
		//uniquenums:去重nums

		//维护:stack:未来可以用到的数字
		//prelength:当前长度
		//predict:当前数字字典
		//prenums:当前数字vector
		//res:返回值

		//初始化过程
		int length = nums.size();
		if (length == 0) return vector<vector<int>>{ {}};
		if (length == 1) return vector<vector<int>>{ {}, nums};

		unordered_map<int, int> numdict;
		for (auto num : nums) numdict[num]++;

		unordered_map<int, int>::iterator it;
		vector<int> uniquenums;
		for (it = numdict.begin(); it != numdict.end(); it++) {
			if (find(uniquenums.begin(), uniquenums.end(), it->first) == uniquenums.end())
				uniquenums.push_back(it->first);
		}
		sort(uniquenums.begin(), uniquenums.end());

		vector<vector<int>> stack = { uniquenums };
		int prelength = 0;
		unordered_map<int, int> predict;
		vector<int> prenums;
		vector<vector<int>> res = { {} };

		//回溯过程
		while ((stack.size() > 1) || (stack[0].size() >= 1))
		{
			if (stack[stack.size() - 1].size() > 0)
			{
				int pre_num = stack[stack.size() - 1][0];
				stack[stack.size() - 1].erase(stack[stack.size() - 1].begin());
				prenums.push_back(pre_num);
				predict[pre_num]++;
				prelength++;
				res.push_back(prenums);

				if (prelength == length) continue; //别查找了,数字满了

				//查找随后可能的数字
				vector<int> temp = {};
				for (auto tempnum : uniquenums)
					if (tempnum < pre_num)
						temp.push_back(tempnum);
				//对于重复数字,特别处理
				if (predict[pre_num] < numdict[pre_num]) temp.push_back(pre_num);
				stack.push_back(temp);
			}
			else
			{
				int last_num = prenums[prenums.size() - 1];
				predict[last_num]--;
				prenums.pop_back();
				prelength--;
				stack.pop_back();
			}
		}
		return res;
	}
};*/

//Second: recursive BackTracking:  16ms, 93.54%
class Solution {
private:
	vector<vector<int>> res = {};
	void DFS(const vector<int>& nums, int oldloc, int prenums, const int& totalnums, vector<int> preres)
	{
		if (prenums == totalnums)
		{
			res.push_back(preres);
			return;
		}
		unordered_set<int> used = {};
		for (int i = oldloc + 1; i < nums.size() - (totalnums - prenums - 1); ++i)
		{
			if (used.find(nums[i]) != used.end()) continue;
			else
			{
				preres.push_back(nums[i]);
				DFS(nums, i, prenums + 1, totalnums, preres);
				preres.pop_back();
				used.insert(nums[i]);
			}
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i <= nums.size(); i++)
		{
			DFS(nums, -1, 0, i, {});
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 4,4,4,1,4 };
	vector<vector<int>> res = s->subsetsWithDup(nums);
	return 0;
}
*/
