#include "public.h"

//
//��������, BFS

class Solution {
public:
	int treeDiameter(vector<vector<int>>& edges) {
		if (edges.empty()) return 0;


		int numEdges = edges.size();
		//��������
		struct Node { int indegree = 0; unordered_set<int> nexts = {}; };  //��������Լ���һ�ڵ�,ֵ����vector���±�

		//init
		queue<int> q;
		vector<Node> courses(numEdges + 1, Node());

		for (auto& edge : edges)
		{
			courses[edge[1]].nexts.insert(edge[0]);
			courses[edge[0]].indegree++;
			courses[edge[0]].nexts.insert(edge[1]);
			courses[edge[1]].indegree++;
		}
		for (int i = 0; i <= numEdges; i++)
			if (courses[i].indegree == 1) q.push(i);

		int time = 0;

		//��ֽڵ�
		while (!q.empty())
		{
			if (q.size() == 1) return 2 * time;
			else
			{
				queue<int> next;
				time++;
				while (!q.empty())
				{
					int prenodeid = q.front();
					q.pop();
					if (!courses[prenodeid].nexts.empty())
					{
						int nei = *courses[prenodeid].nexts.begin();
						--courses[nei].indegree;
						courses[nei].nexts.erase(prenodeid);
						if (courses[nei].indegree == 1) next.push(nei);
					}
				}
				q = next;
			}
		}

		return 2 * time - 1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> edges0 = { {0, 1}, { 1,2 }, { 0,3 }, { 3,4 }, { 2,5 }, { 3,6 } };
	cout << s->treeDiameter(edges0) << endl;
	

	vector<vector<int>> edges = { {0,1},{0,2} };
	cout << s->treeDiameter(edges) << endl;

	vector<vector<int>> edges2 = { {0,1},{1,2},{2,3},{1,4},{4,5} };
	cout << s->treeDiameter(edges2) << endl;
	return 0;
}
*/
