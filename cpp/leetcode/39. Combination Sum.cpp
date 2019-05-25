#include "public.h"

//16ms, 99.00%

//use DFS(BackTracking) algorithm, use recursive solution

class Solution {
private:
	vector<vector<int>> res = {};
	void DFS(vector<int>& candidates, int startloc, vector<int> prenums, int pretarget)
	{
		for (int i = startloc; i < candidates.size(); i++)
		{
			if (candidates[i] > pretarget) break;
			prenums.push_back(candidates[i]);
			if (candidates[i] < pretarget) DFS(candidates, i, prenums, pretarget - candidates[i]);
			else res.push_back(prenums);
			prenums.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//use DFS, recursive solution
		sort(candidates.begin(), candidates.end());
		DFS(candidates, 0, vector<int>{}, target);
		return res;
	}
};
