#include "public.h"

//356ms, 19.35%
//��һ��vector, �±��ʾ�˵�ID-1, ������һ��unordered_set, �洢�����εĶ���
//��һ��vector, �±��ʾ�˵�ID-1, ������һ��unordered_set, �洢�������εĶ���
//��������ε�set����=N-1�����γ���=0, ���һ���Ψһ����Ϊ����

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


