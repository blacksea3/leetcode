#include "public.h"

//
//先生成图, 加入水源节点, 所有节点都和这个节点(0号节点)有个连接
//求最小生成树

class Solution {
	unordered_map<int, int> um;

	void init(vector<int>& vals)
	{
		for (auto& s : vals)
		{
			um[s] = s;
		}
	}

	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}

	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}

	static bool msort(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[2] < v2[2];
	}

public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		for (int index = 0; index < wells.size(); ++index)
		{
			pipes.push_back({ 0, index + 1, wells[index] });
		}

		sort(pipes.begin(), pipes.end(), msort);

		int res = 0;

		vector<int> initvals;

		for (int index = 0; index < wells.size(); ++index)
		{
			initvals.push_back(index);
		}
		initvals.push_back(wells.size());
		init(initvals);


		for (auto& pipe : pipes)
		{
			int firstFa = GetFather(pipe[0]);
			int secondFa = GetFather(pipe[1]);

			if (firstFa == secondFa)
				continue;
			else
			{
				Merge(pipe[0], pipe[1]);
				res += pipe[2];
			}
		}

		return res;
	}
};

int main()
{
	Solution* s = new Solution();

	vector<int> wells = {1,2,2};
	vector<vector<int>> pipes = { {1,2,1}, {2,3,1} };

	cout << s->minCostToSupplyWater(3, wells, pipes) << endl;

	return 0;
}
