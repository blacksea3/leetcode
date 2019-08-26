#include "public.h"

//124ms, 57.35%
//DFS

class Solution {
private:
	vector<vector<int>> res;
	int gblN;
	void DFS(const vector<vector<int>>& graph, int old, vector<int> prepaths)
	{
		if (old == gblN - 1) res.push_back(prepaths);

		for (int i = 0; i < graph[old].size(); ++i)
		{
			prepaths.push_back(graph[old][i]);
			DFS(graph, graph[old][i], prepaths);
			prepaths.pop_back();
		}
	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		gblN = graph.size();
		DFS(graph, 0, { 0 });
		return res;
	}
};
