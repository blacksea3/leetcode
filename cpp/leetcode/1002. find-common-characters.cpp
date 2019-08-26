#include "public.h"

//
//Í³¼Æ

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<vector<int>> v(A.size(), vector<int>(128, 0));

		for (int i = 0; i < A.size(); ++i)
		{
			for (auto& is : A[i])
			{
				v[i][is]++;
			}
		}

		vector<string> res;

		for (int i = 'a'; i <= 'z'; ++i)
		{
			int pmin = INT_MAX;
			for (int j = 0; j < v.size(); ++j)
			{
				pmin = min(pmin, v[j][i]);
			}

			for (int j = 0; j < pmin; ++j)
			{
				string temp = "";
				temp += i;
				res.push_back(temp);
			}
		}

		return res;
	}
};

