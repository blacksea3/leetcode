#include "public.h"

//28ms, 100%

//Graph algorithm, carry out a route that can traverse all the tickets, and is the minimun (string sort)

//problem say that there must be a solution!
//because we need to carry out the minimun (string sort), so we should use multiset<string> to store the next airports

//In DFS: we traverse all the next airports and use ano DFS recursively
//note that if one DFS not include all the routes, this is not bug, because we "traverse" all the next airports
//note that in the whole recursive precedure, the graph is modified anywhere!

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
		for (auto ticket : tickets)
			graph[ticket[0]].push(ticket[1]);

		DFS("JFK", graph);
		reverse(res.begin(), res.end());
		return res;
	}
};