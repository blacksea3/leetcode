#include "public.h"

/*
//暴力BFS, 最大的测试用例直接单独操作, 不建议使用此方法
//144ms, 80.70%
//BFS

class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		vector<unordered_set<int>> usroutes(routes.size());
		for (int i = 0; i < routes.size(); ++i)
		{
			for (auto& ir : routes[i])
				usroutes[i].insert(ir);
		}

		unordered_set<int> pre;
		pre.insert(S);
		unordered_set<int> searched;
		int res = 0;

		while (!pre.empty() && pre.find(T) == pre.end())
		{
			unordered_set<int> next;
			for (auto& p : pre)
			{
				searched.insert(p);
				for (int i = 0; i < routes.size(); ++i)
				{
					if (usroutes[i].find(p) != usroutes[i].end())
					{
						for (auto& iin : usroutes[i])
						{
							if (searched.find(iin) == searched.end() && next.find(iin) == next.end())
								next.insert(iin);
						}
					}
				}
			}
			pre = next;
			res++;
		}

		return (pre.empty()) ? -1 : res;
	}
};
*/

//220ms, 50.88%
//优化BFS
//用unordered_map记录车站ID: 公交车索引, 并且取出公交车索引时顺带去重
//BFS

class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		unordered_map<int, vector<int>> busstop_bus;

		for (int i = 0; i < routes.size(); ++i)
		{
			for (auto& ir : routes[i])
				busstop_bus[ir].push_back(i);
		}

		unordered_set<int> pre;
		pre.insert(S);
		unordered_set<int> searched;
		int res = 0;

		while (!pre.empty() && pre.find(T) == pre.end())
		{
			unordered_set<int> next;
			unordered_set<int> ne_busstop;
			for (auto& p : pre)
			{
				searched.insert(p);
				for (auto& ib : busstop_bus[p])
				{
					ne_busstop.insert(ib);
				}
			}

			for (auto& busstop_loc : ne_busstop)
			{
				for (auto& iin : routes[busstop_loc])
				{
					if (searched.find(iin) == searched.end() && next.find(iin) == next.end())
						next.insert(iin);
				}
			}
			pre = next;
			res++;
		}

		return (pre.empty()) ? -1 : res;
	}
};

int main()
{
	Solution* s = new Solution();
	
	//cout << s->numBusesToDestination(routes, 0, 90000);
	return 0;
}

