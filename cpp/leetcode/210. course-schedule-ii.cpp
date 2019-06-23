#include "public.h"

//拓扑排序, 复用207题, 28ms, 98.18%

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//复用207题
		if (numCourses == 0) return vector<int> {};

		//拓扑排序
		struct Node { int indegree = 0; vector<int> nexts = {}; };  //包含入度以及下一节点,值就是vector的下标

		//init节点们/入度为0的节点进stack
		stack<int> st;
		vector<Node> courses(numCourses, Node());
		vector<int> res = {};
		int num_of_removed_nodes = 0;

		for (auto& prere : prerequisites)
		{
			courses[prere[1]].nexts.push_back(prere[0]);
			courses[prere[0]].indegree++;
		}
		for (int i = 0; i < numCourses; i++)
			if (courses[i].indegree == 0) st.push(i);

		//拆分节点
		while (!st.empty())
		{
			int prenodeid = st.top();
			res.push_back(prenodeid);
			st.pop();
			num_of_removed_nodes++;
			for (auto& nextnodeid : courses[prenodeid].nexts)
			{
				if (--courses[nextnodeid].indegree == 0)
					st.push(nextnodeid);
			}
		}
		return (num_of_removed_nodes == numCourses) ? res : vector<int>{};
	}
};
