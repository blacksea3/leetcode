#include "public.h"

//652ms, 10.53%
//并查集
//遍历dislikes对于已知的两者的关系, 若它们不在一个集合则放入同一个集合并给予假定的0/1, 分别代表两个组
//   给予时注意:若两个都是初始化状态-1,那么随便给, 若有一个是初始化状态, 那么这个得和另一个不一样, 若两个都不是初始化状态
//   但是是不同组, 那么直接合并, 若两个都不是初始化状态而且是相同组, 那么其中一组的所有人更换组, 然后合并

//若它们在一个集合, 是不同组不要紧, 是相同组则返回false

class Solution {
private:
	unordered_map<int, int> fa;
	unordered_map<int, int> group;

	void Init(int n) {
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
			group[i] = -1;
		}
	}
	int GetFather(int x) {
		return fa[x] = (fa[x] == x ? x : GetFather(fa[x]));
	}
	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			fa[b] = a;
		}
	}

public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		Init(N);

		for (auto& d : dislikes)
		{
			if (group[d[0]] == -1 && group[d[1]] == -1)
			{
				group[d[0]] = 0;
				group[d[1]] = 1;
				Merge(d[0], d[1]);
			}
			else if (group[d[0]] == -1)
			{
				group[d[0]] = (group[d[1]] == 1) ? 0 : 1;
				Merge(d[0], d[1]);
			}
			else if (group[d[1]] == -1)
			{
				group[d[1]] = (group[d[0]] == 1) ? 0 : 1;
				Merge(d[0], d[1]);
			}
			else
			{
				int f0 = GetFather(d[0]);
				int f1 = GetFather(d[1]);
				if (f0 == f1)
				{
					if (group[d[0]] != group[d[1]]) continue;
					else return false;
				}
				else
				{
					if (group[d[0]] != group[d[1]])
					{
						Merge(d[0], d[1]);
					}
					else
					{
						//更换和d[1]在一个集合的所有人的组
						for (int i = 1; i <= N; ++i)
						{
							if (GetFather(i) == f1) group[i] = (group[i] == 0) ? 1 : 0;
						}
						Merge(d[0], d[1]);
					}
				}
			}
		}
		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> dislikes = { {1,2},{2,3},{3,4},{4,5},{1,5} };
	cout << s->possibleBipartition(5, dislikes);
	return 0;
}
*/
