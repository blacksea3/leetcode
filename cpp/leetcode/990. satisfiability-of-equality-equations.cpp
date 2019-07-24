#include "public.h"

//4ms, 98.92%
//并查集
//用vector表示
//给一个vector, 里面是unordered_set字母们
//先研究相同字母: 按普通并查集处理 
//再研究不同字母, 两字母不同, 都不在/一个在一个不在/都在而且在不同组, 无视; 都在但是是相同组则完蛋咯 :)

class Solution {
private:
	int findloc(const vector<unordered_set<int>>& vus, const int& val)
	{
		for (int i = 0; i < vus.size(); ++i)
		{
			if (vus[i].find(val) != vus[i].end()) return i;
		}
		return -1;
	}

public:
	bool equationsPossible(vector<string>& equations) {
		vector<unordered_set<int>> vus;

		//先找等于号
		for (auto& e : equations)
		{
			if (e[1] == '=')
			{
				int loc1 = findloc(vus, e[0]);
				int loc2 = findloc(vus, e[3]);
				if (loc1 == -1 && loc2 == -1)
				{
					vus.push_back(unordered_set<int>{e[0], e[3]});
				}
				else if (loc1 == -1)
				{
					vus[loc2].insert(e[0]);
				}
				else if (loc2 == -1)
				{
					vus[loc1].insert(e[3]);
				}
				else
				{
					if (loc1 == loc2) continue;
					else
					{
						//merge
						for (auto& val : vus[loc2])
						{
							vus[loc1].insert(val);
						}
						vus.erase(vus.begin() + loc2);
					}
				}
			}
		}
		//再找不等于号
		for (auto& e : equations)
		{
			if (e[1] == '!')
			{
				if (e[0] == e[3]) return false;

				int loc1 = findloc(vus, e[0]);
				int loc2 = findloc(vus, e[3]);
				if (!(loc1 == -1 || loc2 == -1 || loc1 != loc2))
				{
					return false;
				}
			}
		}
		return true;
	}
};
