#include "public.h"

//88ms, 77.61%
//按并查集处理
//搞清楚有多少个集合:), 那么结果就是石头总数减去集合数
//将坐标转换为一个唯一值: 根据题意: pair<int, int>转为10000*first+second

class Solution {
private:
	unordered_map<int, int> um;

	void init(vector<int>& newstones)
	{
		for (auto& s : newstones)
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

public:
	int removeStones(vector<vector<int>>& stones) {
		vector<int> convert(stones.size(), 0);
		for (int i = 0; i < stones.size(); ++i)
		{
			convert[i] = 10000 * stones[i][0] + stones[i][1];
		}
		init(convert);
		//统计行列情况
		vector<vector<int>> rowstones(10000, vector<int>{});
		vector<vector<int>> columnstones(10000, vector<int>{});

		for (int i = 0; i < stones.size(); ++i)
		{
			rowstones[stones[i][0]].push_back(i);
			columnstones[stones[i][1]].push_back(i);
		}

		//按行列找哪些可以merge
		for (int r = 0; r < 10000; ++r)
		{
			if (rowstones[r].size() <= 1) continue;
			else
			{
				for (int loc = 0; loc < rowstones[r].size() - 1; ++loc)
				{
					Merge(convert[rowstones[r][loc]], convert[rowstones[r][loc + 1]]);
				}
			}
		}

		for (int c = 0; c < 10000; ++c)
		{
			if (columnstones[c].size() <= 1) continue;
			else
			{
				for (int loc = 0; loc < columnstones[c].size() - 1; ++loc)
				{
					Merge(convert[columnstones[c][loc]], convert[columnstones[c][loc + 1]]);
				}
			}
		}

		//统计现在有多少个集合
		unordered_set<int> us;
		for (auto& u : um)
		{
			int f = GetFather(u.first);
			if (us.find(f) == us.end())
			{
				us.insert(f);
			}
		}
		return stones.size() - us.size();
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> xstones = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
	//cout << s->removeStones(xstones);
	//vector<vector<int>> stones = { {0,0},{0,2},{1,1},{2,0},{2,2} };
	//cout << s->removeStones(stones);
	vector<vector<int>> sstones = { {0,1},{1,0},{1,1}};
	cout << s->removeStones(sstones);
	return 0;
}
*/
