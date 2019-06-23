#include "public.h"

//Backtracking, 4ms, 93.41%
//Here I use iterative solution

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		//回溯
		vector<vector<int>> res = {};
		if ((k <= 0) || (k > 9)) return res;
		if (k == 1) return ((n <= 9) && (n >= 1)) ? vector<vector<int>> {vector<int> {n}} : res;

		unordered_map<int, pair<int, int>> um; //可以有解的最大值与最小值
		um[2] = pair<int, int>{ 3,17 };
		um[3] = pair<int, int>{ 6,24 };
		um[4] = pair<int, int>{ 10,30 };
		um[5] = pair<int, int>{ 15,35 };
		um[6] = pair<int, int>{ 21,39 };
		um[7] = pair<int, int>{ 28,42 };
		um[8] = pair<int, int>{ 36,44 };
		um[9] = pair<int, int>{ 45,45 };
		if ((n > um[k].second) || (n < um[k].first)) return res;
		vector<int> pre = { 1 };
		int prelen = 1;
		int presum = 1;
		bool isneedrecall = false;

		while (true)
		{
			if (!isneedrecall)
			{
				if (prelen == (k - 1))
					if (((n - presum) > 9) || ((n - presum) < 1))
					{
						isneedrecall = true;
					}
					else if (pre[pre.size() - 1] < (n - presum))
					{
						res.push_back(pre);
						res[res.size() - 1].push_back(n - presum);
						isneedrecall = true;
					}
					else
						isneedrecall = true;
				else
				{
					if (pre[pre.size() - 1] == 9)
					{
						isneedrecall = true;
					}
					else
					{
						pre.push_back(pre[pre.size() - 1] + 1);
						prelen++;
						presum += pre[pre.size() - 1];
					}
				}
			}
			else
			{
				if (pre[pre.size() - 1] == 9)
				{
					presum -= pre[pre.size() - 1];
					pre.pop_back();
					prelen--;
					if (pre.empty()) break;
				}
				else
				{
					pre[pre.size() - 1]++;
					presum++;
					isneedrecall = false;
				}
			}
		}
		return res;
	}
};
