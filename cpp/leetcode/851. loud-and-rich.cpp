#include "public.h"

//308ms, 23.64% 
//按图处理, 节点含入度, 父亲们, 儿子们

class Solution {
private:
	struct Node {
		int indegree = 0;
		unordered_set<int> old;
		unordered_set<int> next;
	};

public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int N = quiet.size();
		//初始化图
		vector<Node*> nodes;
		for (int i = 0; i < N; ++i)
		{
			Node* n = new Node();
			nodes.push_back(n);
		}
		vector<int> minquiets(N);
		for (auto& r : richer)
		{
			nodes[r[0]]->next.insert(r[1]);
			nodes[r[1]]->old.insert(r[0]);
			nodes[r[1]]->indegree++;
		}
		vector<int> quiet_people(N);
		for (int i = 0; i < N; ++i)
			quiet_people[quiet[i]] = i;

		//初始化, 查找入度为0的节点
		vector<int> res(N);
		unordered_set<int> first;
		//init
		for (int i = 0; i < N; ++i)
		{
			if (nodes[i]->indegree == 0)
			{
				first.insert(i);
			}
		}

		while (!first.empty())
		{
			unordered_set<int> next;
			for (auto& f : first)
			{
				//获取他的父亲们的安静程度
				set<int> pre;
				for (auto& ol : nodes[f]->old)
				{
					pre.insert(minquiets[ol]);
				}
				pre.insert(quiet[f]);
				minquiets[f] = *pre.begin();
				//获取最安静的那个
				res[f] = quiet_people[minquiets[f]];
				//更新入度
				for (auto& n : nodes[f]->next)
				{
					nodes[n]->indegree--;
					if (nodes[n]->indegree == 0) next.insert(n);
				}
			}
			first = next;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> richer = { {1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3} };
	vector<int> quiet = { 3,2,5,4,6,1,7,0 };
	auto res = s->loudAndRich(richer, quiet);
	return 0;
}
*/
