#include "public.h"

//
//≈≈–Ú

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());

		int minabs = INT_MAX;
		vector<vector<int>> res;

		for (int index = 1; index < arr.size(); ++index)
		{
			if (minabs > (arr[index] - arr[index - 1]))
			{
				res.clear();
				res.emplace_back(vector<int>{arr[index - 1], arr[index]});
				minabs = (arr[index] - arr[index - 1]);
			}
			else if (minabs == (arr[index] - arr[index - 1]))
			{
				res.emplace_back(vector<int>{arr[index - 1], arr[index]});
			}
		}
		return res;
	}
};
