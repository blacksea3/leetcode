#include "public.h"

//��������, ����207��, 28ms, 98.18%

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//����207��
		if (numCourses == 0) return vector<int> {};

		//��������
		struct Node { int indegree = 0; vector<int> nexts = {}; };  //��������Լ���һ�ڵ�,ֵ����vector���±�

		//init�ڵ���/���Ϊ0�Ľڵ��stack
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

		//��ֽڵ�
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
