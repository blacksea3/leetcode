#include "public.h"

//16ms, 93.94%

//use DFS(BackTracking) algorithm, use recursive solution

class Solution {
private:
	vector<vector<int>> res = {};
	void DFS(unordered_map<int, int>& candidates_dict, vector<int>& candidates, int startloc, vector<int> prenums, int pretarget, int lastnum_times)
	{
		if (lastnum_times < candidates_dict[candidates[startloc]])
		{
			if (candidates[startloc] > pretarget) return;
			prenums.push_back(candidates[startloc]);
			if (candidates[startloc] < pretarget)
				DFS(candidates_dict, candidates, startloc, prenums, pretarget - candidates[startloc], lastnum_times + 1);
			else res.push_back(prenums);
			prenums.pop_back();
		}

		for (int i = startloc + 1; i < candidates.size(); i++)
		{
			if (candidates[i] > pretarget) break;
			prenums.push_back(candidates[i]);
			if (candidates[i] < pretarget) DFS(candidates_dict, candidates, i, prenums, pretarget - candidates[i], 1);
			else res.push_back(prenums);
			prenums.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//count the number of each item in candidates, and remove the duplicate items
		unordered_map<int, int> candidates_dict = {};
		for (auto ca:candidates) candidates_dict[ca] += 1;
		vector<int> candidates_no_duplicate = {};
		for (unordered_map<int, int>::const_iterator iter = candidates_dict.cbegin(); iter != candidates_dict.cend(); ++iter)
			candidates_no_duplicate.push_back(iter->first);
		sort(candidates_no_duplicate.begin(), candidates_no_duplicate.end());
		//use DFS, recursive solution
		DFS(candidates_dict, candidates_no_duplicate, 0, vector<int>{}, target, 0);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> candidates = { 10,1,2,7,6,1,5};

	vector<vector<int>> res = s->combinationSum2(candidates, 8);

	return 0;
}
