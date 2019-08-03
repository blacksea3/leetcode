#include "public.h"

//500ms, 6.21%
//dp[i]��¼����ĳ������վλ��i���Ѿ����ʹ���/��ǰ����, ��unordered_map�洢
//������ͬ���ʹ���, ȡ��ǰ�������ߴ洢
//���ĳ��dpֱ�ӿ���, ��ô���군��, ����ȡ���dp����ͼ��ʹ���

//��֦: �����ǰ����>ʣ��·����ô֮��ͱ����

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		vector<unordered_map<int, long long>> v(stations.size() + 1);
		v[0].insert({ 0, startFuel });

		int minr = INT_MAX;

		for (int i = 0; i < stations.size(); ++i)
		{
			//���ڼ����벻����
			unordered_map<int, long long> next;
			if (i == 0)
			{
				if (stations[i][0] > startFuel);
				else
				{
					next[0] = startFuel - stations[i][0];
					next[1] = startFuel - stations[i][0] + stations[i][1];
				}
			}
			else
			{
				for (auto& choice : v[i])
				{
					if ((stations[i][0] - stations[i - 1][0]) > choice.second) continue;
					else
					{
						if (choice.second >= (target - stations[i - 1][0])) minr = min(minr, choice.first);
						else
						{
							if (next.find(choice.first) == next.end()) next[choice.first] = choice.second - (long long)(stations[i][0] - stations[i - 1][0]);
							else next[choice.first] = max(next[choice.first], choice.second - (long long)(stations[i][0] - stations[i - 1][0]));
							if (next.find(choice.first + 1) == next.end()) next[choice.first + 1] = stations[i][1] + choice.second - (long long)(stations[i][0] - stations[i - 1][0]);
							else next[choice.first + 1] = max(next[choice.first + 1], stations[i][1] + choice.second - (long long)(stations[i][0] - stations[i - 1][0]));
						}
					}
				}
			}
			if (next.empty()) return (minr == INT_MAX) ? -1 : minr;
			else v[i + 1] = next;
		}

		//������С���ʹ���
		for (auto& iiv : v[stations.size()])
		{
			if (stations.empty())
			{
				if ((target) > iiv.second) continue;
				else minr = min(minr, iiv.first);
			}
			else
			{
				if ((target - stations[stations.size() - 1][0]) > iiv.second) continue;
				else minr = min(minr, iiv.first);
			}
		}
		return (minr == INT_MAX) ? -1 : minr;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> stations2 = { {5,100},{997,100},{998,100}};
	cout << s->minRefuelStops(999, 1000, stations2);

	//vector<vector<int>> stations1 = { {10,60},{20,30},{30,30},{60,40} };
	//cout << s->minRefuelStops(100, 10, stations1);
	
	//vector<vector<int>> stations = { };
	//cout << s->minRefuelStops(1, 1, stations);

	return 0;
}
*/
