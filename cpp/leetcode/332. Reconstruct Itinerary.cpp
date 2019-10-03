#include "public.h"

//24ms, 96.25%
//图, DFS, 倒过来生成行程, 然后reverse它
//对某个机场的下一个目的地, 按照优先队列排序

class Solution {
private:
	vector<string> res = {};

	void DFS(const string& pre, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph)
	{
		while (graph[pre].size())
		{
			string temp = graph[pre].top();
			graph[pre].pop();
			DFS(temp, graph);
		}
		res.push_back(pre);
	}

public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

		//generate the graph
		for (auto& ticket : tickets)
			graph[ticket[0]].push(ticket[1]);

		DFS("JFK", graph);
		reverse(res.begin(), res.end());
		return res;
	}
};
