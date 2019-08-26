#include "public.h"

//32ms, 65.61%
//BFS, 记录已访问过的节点

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<bool> v(graph.size(), 0);
		unordered_set<int> searched;
		unordered_set<int> pre;

		int preloc = 0;
		while (preloc < graph.size())
		{
			if (searched.find(preloc) == searched.end())
			{
				pre.insert(preloc);
				bool now = true;
				while (!pre.empty())
				{
					unordered_set<int> nextus;
					for (auto& p : pre)
					{
						v[p] = now;
						searched.insert(p);
						for (auto& next : graph[p])
						{
							if (searched.find(next) == searched.end())
							{
								if (nextus.find(next) == searched.end()) nextus.insert(next);
							}
							else if (v[next] == now) return false;
						}
					}
					pre = nextus;
					now = (now) ? false : true;
				}
			}
			preloc++;
		}

		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();

	return 0;
}
*/
