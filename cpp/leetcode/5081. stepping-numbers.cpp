#include "public.h"

//
//模拟
//全列出来, 排序, 然后剪除一部分

class Solution {
private:
	vector<vector<int>> tempv;
	//rem:剩余位数
	void recDCstepping_numbers(int rem, vector<int>& last)
	{
		if (rem == 1) tempv.emplace_back(last);
		else
		{
			if (last.back() > 0)
			{
				last.emplace_back(last.back() - 1);
				recDCstepping_numbers(rem - 1, last);
				last.pop_back();
			}
			if (last.back() < 9)
			{
				last.emplace_back(last.back() + 1);
				recDCstepping_numbers(rem - 1, last);
				last.pop_back();
			}
		}
	}

	//count:位数
	vector<int> DCstepping_numbers(int count)
	{
		vector<int> pre(1);
		vector<int> res;

		for (int i = 1; i <= 9; ++i)
		{
			tempv.clear();
			pre[0] = i;
			recDCstepping_numbers(count, pre);

			for (auto& p : tempv)
			{
				long long pll = 0;
				for (auto& iterp : p)
				{
					pll *= 10;
					pll += iterp;
				}
				if (pll <= INT_MAX)
				{
					res.emplace_back(pll);
				}
			}
		}
		return res;
	}

public:
	vector<int> countSteppingNumbers(int low, int high) {
		vector<int> pres;
		if (low == 0) pres.emplace_back(0);

		for (int i = 1; i <= 10; ++i)
		{
			vector<int> t = DCstepping_numbers(i);
			pres.insert(pres.end(), t.begin(), t.end());
		}

		sort(pres.begin(), pres.end());
		int lowIndex = lower_bound(pres.begin(), pres.end(), low) - pres.begin();
		int highIndex = upper_bound(pres.begin(), pres.end(), high) - pres.begin();

		vector<int> realres(pres.begin() + lowIndex, pres.begin() + highIndex);

		return realres;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->countSteppingNumbers(0, 21);
	return 0;
}
*/
