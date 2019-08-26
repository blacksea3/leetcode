#include "public.h"

//500ms, 6.21%
//dp[i]记录到达某个加油站位置i的已经加油次数/当前油量, 用unordered_map存储
//对于相同加油次数, 取当前油量高者存储
//如果某次dp直接空了, 那么就完蛋了, 否则取最后dp的最低加油次数

//剪枝: 如果当前油量>剩余路程那么之后就别加了

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		vector<unordered_map<int, long long>> v(stations.size() + 1);
		v[0].insert({ 0, startFuel });

		int minr = INT_MAX;

		for (int i = 0; i < stations.size(); ++i)
		{
			//存在加油与不加油
			unordered_map<int, long long> next;
			if (i == 0)
			{
				if (stations[i][0] > startFuel);
				else
				{
					next[0] = startFuel - stations[i][0];
					next[1] = startFuel - stations[i][0] + stations[i][1];
				}
			}
			else
			{
				for (auto& choice : v[i])
				{
					if ((stations[i][0] - stations[i - 1][0]) > choice.second) continue;
					else
					{
						if (choice.second >= (target - stations[i - 1][0])) minr = min(minr, choice.first);
						else
						{
							if (next.find(choice.first) == next.end()) next[choice.first] = choice.second - (long long)(stations[i][0] - stations[i - 1][0]);
							else next[choice.first] = max(next[choice.first], choice.second - (long long)(stations[i][0] - stations[i - 1][0]));
							if (next.find(choice.first + 1) == next.end()) next[choice.first + 1] = stations[i][1] + choice.second - (long long)(stations[i][0] - stations[i - 1][0]);
							else next[choice.first + 1] = max(next[choice.first + 1], stations[i][1] + choice.second - (long long)(stations[i][0] - stations[i - 1][0]));
						}
					}
				}
			}
			if (next.empty()) return (minr == INT_MAX) ? -1 : minr;
			else v[i + 1] = next;
		}

		//查找最小加油次数
		for (auto& iiv : v[stations.size()])
		{
			if (stations.empty())
			{
				if ((target) > iiv.second) continue;
				else minr = min(minr, iiv.first);
			}
			else
			{
				if ((target - stations[stations.size() - 1][0]) > iiv.second) continue;
				else minr = min(minr, iiv.first);
			}
		}
		return (minr == INT_MAX) ? -1 : minr;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> stations2 = { {5,100},{997,100},{998,100}};
	cout << s->minRefuelStops(999, 1000, stations2);

	//vector<vector<int>> stations1 = { {10,60},{20,30},{30,30},{60,40} };
	//cout << s->minRefuelStops(100, 10, stations1);
	
	//vector<vector<int>> stations = { };
	//cout << s->minRefuelStops(1, 1, stations);

	return 0;
}
*/
