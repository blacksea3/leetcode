#include "public.h"

//
//dp[i]:截止到i的工作最大利润, 离散处理
//对所有出现过的时间离散化处理


class Solution {
private:
	static bool msort(vector<int> const& t1, vector<int> const& t2)
	{
		if (t1[1] < t2[1]) return true;
		else if (t1[1] > t2[1]) return false;
		else return t1[0] < t2[0];
	}

public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		vector<vector<int>> v;
		int sSize = startTime.size();

		for (int index = 0; index < sSize; ++index)
		{
			v.emplace_back(vector<int>{startTime[index], endTime[index], profit[index]});
		}
		sort(v.begin(), v.end(), msort);

		//内卷
		map<int, vector<pair<int, int>>> umv; //endTime:多个startTime,及对应的index
		set<int> findIndexs;    //单独记录entTime排序后

		for (int index = 0; index < v.size(); ++index)
		{
			umv[v[index][1]].push_back(pair<int, int>{v[index][0], index});
			findIndexs.insert(v[index][1]);
		}
		vector<int> findIndexv(findIndexs.begin(), findIndexs.end());

		vector<int> dp(umv.size(), 0);   //记忆化某个entTime后的最大利润

		//开始dp
		int umvindex = 0;
		int res = 0;
		for (auto& iterumv : umv)
		{
			int preMaxProfit = 0;

			for (auto& stPair : iterumv.second)
			{
				vector<int>::iterator iter = upper_bound(findIndexv.begin(), findIndexv.end(), stPair.first);
				int abs = iter - findIndexv.begin() - 1;
				if (abs == -1)
				{
					preMaxProfit = max(preMaxProfit, v[stPair.second][2]);
				}
				else
				{
					preMaxProfit = max(preMaxProfit, v[stPair.second][2] + dp[abs]);
				}
			}
			if (umvindex == 0) dp[umvindex] = preMaxProfit;
			else dp[umvindex] = max(dp[umvindex - 1], preMaxProfit);
			umvindex++;
		}

		return *max_element(dp.begin(), dp.end());
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> startTime0 = { 4,2,4,8,2 };
	vector<int> endTime0 = { 5,5,5,10,8 };
	vector<int> profit0 = { 1,2,8,10,4 };
	cout << s->jobScheduling(startTime0, endTime0, profit0) << endl;  //18

	vector<int> startTime = { 1,2,3,3 };
	vector<int> endTime = { 3,4,5,6 };
	vector<int> profit = { 50,10,40,70 };
	cout << s->jobScheduling(startTime, endTime, profit) << endl;  //120
	vector<int> startTime1 = { 1,1,1 };
	vector<int> endTime1 = { 2,3,4 };
	vector<int> profit1 = { 5,6,4 };
	cout << s->jobScheduling(startTime1, endTime1, profit1) << endl; //6
	return 0;
}
*/
