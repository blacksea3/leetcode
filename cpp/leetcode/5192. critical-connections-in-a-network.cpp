#include "public.h"

//
//由题意，**整个集群构成一个无向图，且所有元素都互相连接**
//根据关键连接的定义，它不能在某个环内，借鉴有向图的拓扑排序，首先生成图，
//  每个节点有值、邻居列表以及邻居数量。既然所有元素都互相连接，那么一开始所有节点的邻居数量 >= 1。
//  初始化将邻居数量为1的节点放入栈，然后对栈进行循环操作，依次删去内部的节点，
//  并判断与其相连的节点在邻居数量 - 1后的邻居数量。这一操作等于拓扑排序中的剥离不在环中的节点。
//最终的结果通过删除栈中节点时，把对应连接记录下来可以得到。

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		struct Node { int indegree = 0; set<int> neighbour = {}; };  //包括邻居数量indegree和邻居们

		//生成图
		vector<Node> nodes(n, Node());
		for (auto& connect : connections)
		{
			nodes[connect[1]].neighbour.insert(connect[0]);
			nodes[connect[1]].indegree++;
			nodes[connect[0]].neighbour.insert(connect[1]);
			nodes[connect[0]].indegree++;
		}

		//初始化邻居数量为1的节点进stack
		stack<int> st;
		for (int i = 0; i < n; i++)
		{
			if (nodes[i].indegree == 1) st.push(i);
		}

		vector<vector<int>> res;
		//寻找邻居数量为1的点, 删除连接, 迭代循环
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
