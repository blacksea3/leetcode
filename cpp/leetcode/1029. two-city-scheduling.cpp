#include "public.h"

//12ms, 79.94%
//作差排序
//用A地-B地
//前一半大的去A剩下的去B

class Solution {
private:
	static bool msort(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.first < p2.first) return true;
		else if (p1.first > p2.first) return false;
		else return p1.second < p2.second;
	}

public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		vector<pair<int, int>> v;

		for (int i = 0; i < costs.size(); ++i)
			v.push_back({ costs[i][0] - costs[i][1], i });
		
		sort(v.begin(), v.end(), msort);

		int res = 0;

		for (int i = 0; i < costs.size() / 2; ++i)
			res += costs[v[i].second][0];
		
		for (int i = costs.size() / 2; i < costs.size(); ++i)
			res += costs[v[i].second][1];
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> costs = { {10, 20},{30, 200},{400, 50},{30, 20} };
	auto res = s->twoCitySchedCost(costs);
	return 0;
}*/