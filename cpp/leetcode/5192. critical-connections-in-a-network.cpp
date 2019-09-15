#include "public.h"

//
//拓扑排序, 把能够删掉的边记录下来

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		//拓扑排序
		struct Node { int indegree = 0; set<int> neighbour = {}; };  //包含入度以及下一节点,值就是vector的下标

		//init节点们/入度为0的节点进stack
		stack<int> st;
		vector<Node> nodes(n, Node());

		for (auto& connect : connections)
		{
			nodes[connect[1]].neighbour.insert(connect[0]);
			nodes[connect[1]].indegree++;
			nodes[connect[0]].neighbour.insert(connect[1]);
			nodes[connect[0]].indegree++;
		}

		for (int i = 0; i < n; i++)
		{
			if (nodes[i].indegree == 1) st.push(i);
		}

		vector<vector<int>> res;

		//寻找入度为1的点, 删除连接, 迭代循环

		//拆分节点
		while (!st.empty())
		{
			int prenodeid = st.top();
			st.pop();
			int nei = *nodes[prenodeid].neighbour.begin();

			nodes[nei].neighbour.erase(prenodeid);
			nodes[nei].indegree--;
			res.emplace_back(vector<int>{prenodeid, nei});
			if (nodes[nei].indegree == 1)
				st.push(nei);
		}

		return res;
	}
};
