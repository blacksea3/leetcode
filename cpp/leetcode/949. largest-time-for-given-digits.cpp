#include "public.h"

//12ms, 18.63%
//暴力, 直接DFS组合

class Solution {
private:
	int res = INT_MIN;
	void DFS(int pre, vector<int> v)
	{
		if (v.empty())
		{
			if (pre >= 2400) return;
			else
			{
				if (pre % 100 >= 60) return;
				else res = max(res, pre);
			}
		}
		else
		{
			for (int i = 0; i < v.size(); ++i)
			{
				vector<int> temp = v;
				temp.erase(temp.begin() + i);
				DFS(pre * 10 + v[i], temp);
			}
		}
	}

public:
	string largestTimeFromDigits(vector<int>& A) {
		DFS(0, A);
		if (res == INT_MIN) return "";
		else
		{
			string r = "xx:xx";
			r[0] = res / 1000 + '0';
			r[1] = (res % 1000) / 100 + '0';
			r[3] = (res % 100) / 10 + '0';
			r[4] = res % 10 + '0';
			return r;
		}
	}
};
