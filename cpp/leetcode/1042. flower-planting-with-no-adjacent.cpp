#include "public.h"

//252ms, 74.52%
//ע����������, ֱ���������԰������, ���迼�ǳ�ͻ������

class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		struct Node
		{
			int col = 0;
			vector<int> nexts;
		};

		vector<Node> gardens(N + 1); //�±�Ϊ��԰���, ����Ϊ�ھӻ�԰�����

		for (auto& path : paths)
		{
			gardens[path[0]].nexts.push_back(path[1]);
			gardens[path[1]].nexts.push_back(path[0]);
		}

		vector<int> res(N + 1, 0);

		//ֲ��
		for (int i = 1; i <= N; ++i)
		{
			vector<bool> cols(5, true);
			for (auto& next : gardens[i].nexts)
			{
				cols[gardens[next].col] = false;
			}
			for (int j = 1; j <= 4; ++j)
			{
				if (cols[j])
				{
					gardens[i].col = j;
					res[i] = j;
				}
			}
		}
		res.erase(res.begin());
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> paths = { {1, 2},{2, 3},{3, 1} };
	auto res = s->gardenNoAdj(3, paths);
	return 0;
}
*/
