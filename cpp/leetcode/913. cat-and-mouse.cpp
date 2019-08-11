#include "public.h"

//68ms, 76.19%
//dp: 设状态 f(t,x,y) 表示 t 时刻，老鼠位于 x 且猫位于 y 时的结果（0，1 或 2）, 0:待定, 1:老鼠胜 2:猫胜
//已知状态: dp[t][0][y] = 1, dp[t][x][x] = 2, 
//状态转移: 按t循环如果老鼠走到dp[t+1][x->next][y] 如果存在1那么就是1, 如果都是2那么就是2, 
//猫相反
//起始位置是: dp[0][1][2]

//注意: 如果循环了t次还没有结果(t == 2*graph.size()), 说明形成环了, 则平局

//写法: 试探型走, 轮流切换, 其实是DFS回溯的写法

class Solution {
private:
	vector<vector<vector<int>>> dp;

	int DFS(const vector<vector<int>>& graph, int t, int x, int y)
	{
		if (t == graph.size() * 2) return 0;
		if (x == y) return dp[t][x][y] = 2;  //特别注意:这里x或y(老鼠或猫走动后)都会触发
		if (x == 0) return dp[t][x][y] = 1;  //特别注意: 这里隐藏了:一定是x(老鼠走动触发的)的现实
		if (dp[t][x][y] != -1) return dp[t][x][y]; //已经发现了这个情况

		bool flag;
		if (t % 2 == 0) //老鼠走
		{
			flag = true;
			for (int i = 0; i < graph[x].size(); ++i)
			{
				int next = DFS(graph, t + 1, graph[x][i], y);
				if (next == 1) return dp[t][x][y] = 1;
				else if (next != 2) flag = false;
			}
			if (flag) return dp[t][x][y] = 2;
			else return dp[t][x][y] = 0;
		}
		else  //猫走
		{
			flag = true;
			for (int i = 0; i < graph[y].size(); ++i)
			{
				if (graph[y][i] != 0) //猫不能进老鼠洞
				{
					int next = DFS(graph, t + 1, x, graph[y][i]);
					if (next == 2) return dp[t][x][y] = 2;
					else if (next != 1) flag = false;
				}
			}
			if (flag) return dp[t][x][y] = 1;
			else return dp[t][x][y] = 0;
		}
	}

public:
	int catMouseGame(vector<vector<int>>& graph) {
		int gsize = graph.size();
		dp = vector<vector<vector<int>>>(2 * gsize, vector<vector<int>>(gsize, vector<int>(gsize, -1)));
		return DFS(graph, 0, 1, 2);
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> graph = { {2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3} };
	cout << s->catMouseGame(graph);
	return 0;
}
