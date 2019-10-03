#include "BinaryTree.h"

//92ms, 84.24%
//初始化将叶节点(nodes[i].size()==1)记录下来,然后对于叶节点的下一个节点,判断其删除那个叶节点后是否是叶节点,是则记录下来
//直至当前只有1个或两个节点,他们就是root

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
				int beginIndex = *nodes[temp].begin();
				nodes[beginIndex].erase(temp);
				if (nodes[beginIndex].size() == 1)
				{
					next.push(beginIndex);
				}
			}
			q = next;
		}

		vector<int> res;
		while (!q.empty())
		{
			res.emplace_back(q.front());
			q.pop();
		}
		return res;
	}
};
