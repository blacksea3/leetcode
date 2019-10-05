#include "public.h"

//
//±©Á¦

class Solution {
public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int> res;

		for (auto& a : arr1)
		{
			if ((find(arr2.begin(), arr2.end(), a) != arr2.end()) &&
				(find(arr3.begin(), arr3.end(), a) != arr3.end())
				)
				res.emplace_back(a);
		}
		return res;
	}
};
