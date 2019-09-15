#include "public.h"

//
//��������, ���ܹ�ɾ���ı߼�¼����

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		//��������
		struct Node { int indegree = 0; set<int> neighbour = {}; };  //��������Լ���һ�ڵ�,ֵ����vector���±�

		//init�ڵ���/���Ϊ0�Ľڵ��stack
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

		//Ѱ�����Ϊ1�ĵ�, ɾ������, ����ѭ��

		//��ֽڵ�
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
