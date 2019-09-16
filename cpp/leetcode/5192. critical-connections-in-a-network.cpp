#include "public.h"

//
//�����⣬**������Ⱥ����һ������ͼ��������Ԫ�ض���������**
//���ݹؼ����ӵĶ��壬��������ĳ�����ڣ��������ͼ������������������ͼ��
//  ÿ���ڵ���ֵ���ھ��б��Լ��ھ���������Ȼ����Ԫ�ض��������ӣ���ôһ��ʼ���нڵ���ھ����� >= 1��
//  ��ʼ�����ھ�����Ϊ1�Ľڵ����ջ��Ȼ���ջ����ѭ������������ɾȥ�ڲ��Ľڵ㣬
//  ���ж����������Ľڵ����ھ����� - 1����ھ���������һ�����������������еİ��벻�ڻ��еĽڵ㡣
//���յĽ��ͨ��ɾ��ջ�нڵ�ʱ���Ѷ�Ӧ���Ӽ�¼�������Եõ���

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		struct Node { int indegree = 0; set<int> neighbour = {}; };  //�����ھ�����indegree���ھ���

		//����ͼ
		vector<Node> nodes(n, Node());
		for (auto& connect : connections)
		{
			nodes[connect[1]].neighbour.insert(connect[0]);
			nodes[connect[1]].indegree++;
			nodes[connect[0]].neighbour.insert(connect[1]);
			nodes[connect[0]].indegree++;
		}

		//��ʼ���ھ�����Ϊ1�Ľڵ��stack
		stack<int> st;
		for (int i = 0; i < n; i++)
		{
			if (nodes[i].indegree == 1) st.push(i);
		}

		vector<vector<int>> res;
		//Ѱ���ھ�����Ϊ1�ĵ�, ɾ������, ����ѭ��
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
