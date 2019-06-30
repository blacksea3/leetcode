#include "BinaryTree.h"

//92ms, 97.39%
//��ʼ����Ҷ�ڵ�(nodes[i].size()==1)��¼����,Ȼ�����Ҷ�ڵ����һ���ڵ�,�ж���ɾ���Ǹ�Ҷ�ڵ���Ƿ���Ҷ�ڵ�,�����¼����
//ֱ����ǰֻ��1���������ڵ�,���Ǿ���root

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) return { 0 };

		vector<unordered_set<int>> nodes(n);

		for (auto& e : edges)
		{
			nodes[e[0]].insert(e[1]);
			nodes[e[1]].insert(e[0]);
		}

		queue<int> q;
		//init
		for (int i = 0; i < n; ++i)
			if (nodes[i].size() == 1) q.push(i);

		int remain = n;

		while (n > 2)
		{
			queue<int> next;
			while (!q.empty())
			{
				int temp = q.front();
				q.pop();
				n--;
				unordered_set<int>::iterator iter = nodes[temp].begin();
				nodes[*iter].erase(temp);
				if (nodes[*iter].size() == 1)
				{
					next.push(*iter);
				}
			}
			q = next;
		}

		vector<int> res;
		while (!q.empty())
		{
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};
