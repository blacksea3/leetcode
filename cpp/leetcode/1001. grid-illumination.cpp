#include "public.h"

//1393ms, 18.18%
//四个unordered_map分别存储行/列/行-列/行+列 供查找
//1个unordered_map存储当前灯(行列), 供删除

class Solution {
public:
	vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		//全部用unordered_map
		unordered_map<int, int> rows;
		unordered_map<int, int> cols;
		unordered_map<int, int> mrcs;
		unordered_map<int, int> prcs;
		unordered_map<int, set<int>> locs;

		for (auto& l : lamps)
		{
			rows[l[0]]++;
			cols[l[1]]++;
			mrcs[l[0] - l[1]]++;
			prcs[l[0] + l[1]]++;
			locs[l[0]].insert(l[1]);
		}

		vector<int> res(queries.size(), 0);

		vector<vector<int>> abs = { {0,1}, {0,-1}, {0,0}, {1,1}, {1,-1}, {1,0}, {-1,1}, {-1,-1}, {-1,0} };

		for (int i = 0; i < queries.size(); ++i)
		{
			int pr = queries[i][0];
			int pc = queries[i][1];

			if ((rows[pr] + cols[pc] + mrcs[pr - pc] + prcs[pr + pc]) > 0) res[i] = 1;

			for (int j = 0; j < 9; ++j)
			{
				int nr = pr + abs[j][0];
				int nc = pc + abs[j][1];
				if (locs[nr].find(nc) != locs[nr].end())
				{
					locs[nr].erase(nc);
					rows[nr]--;
					cols[nc]--;
					mrcs[nr - nc]--;
					prcs[nr + nc]--;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> lamps = { {0, 0},{4, 4 }};
	//vector<vector<int>> queries = { {1, 1},{1, 0 } };
	//auto res = s->gridIllumination(5, lamps, queries);

	//vector<vector<int>> lamps = { {0, 0},{0, 4 } };
	//vector<vector<int>> queries = { {0, 4},{0, 1 }, {1,4} };
	//auto res = s->gridIllumination(5, lamps, queries);

	vector<vector<int>> lamps = { {7,55},{53,61},{2,82},{67,85},{81,75},{38,91},{68,0},{60,43},{40,19},{12,75},{26,2},{24,89},{42,81},{60,58},{77,72},{33,24},{19,93},{7,16},{58,54},{78,57},{97,49},{65,16},{42,75},{90,50},{89,34},{76,97},{58,23},{62,47},{94,28},{88,65},{3,87},{81,10},{12,81},{44,81},{54,92},{90,54},{17,54},{27,82},{48,15},{8,46},{4,99},{15,13},{90,77},{2,87},{18,33},{52,90},{4,95},{57,61},{31,22},{32,8},{49,26},{24,65},{88,55},{88,38},{64,76},{94,76},{59,12},{41,46},{80,28},{38,36},{65,67},{75,37},{56,97},{83,57},{2,4},{44,43},{71,90},{62,40},{79,94},{81,11},{96,34},{38,11},{22,3},{54,96},{78,33},{54,54},{79,98},{1,28},{0,32},{37,11} };
	vector<vector<int>> queries = { {24,84},{95,68},{80,35},{31,53},{69,45},{85,29},{87,25},{42,47},{7,59},{99,3},{31,70},{64,62},{44,91},{55,25},{15,52},{95,33},{21,29},{61,34},{93,34},{79,27},{30,86},{52,0},{18,10},{5,1},{40,21},{11,48},{55,94},{22,42},{81,0},{39,43},{5,25},{43,29},{45,47},{83,93},{77,70},{22,63},{30,73},{18,48},{39,88},{91,47} };
	auto res = s->gridIllumination(100, lamps, queries);
	return 0;
}
*/
