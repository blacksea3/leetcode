#include "public.h"

//356ms, 19.35%
//给一个vector, 下标表示人的ID-1, 内容是一个unordered_set, 存储他信任的对象
//给一个vector, 下标表示人的ID-1, 内容是一个unordered_set, 存储他被信任的对象
//如果被信任的set长度=N-1且信任长度=0, 而且还是唯一的则为法官

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<unordered_set<int>> vus_trust(N);
		vector<unordered_set<int>> vus_trusted(N);

		for (auto& t : trust)
		{
			vus_trust[t[0] - 1].insert(t[1]);
			vus_trusted[t[1] - 1].insert(t[0]);
		}

		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if (vus_trust[i].size() == 0 && vus_trusted[i].size() == N - 1) res.push_back(i);
		}

		if (res.size() == 1) return res[0] + 1;
		else return -1;
	}
};


