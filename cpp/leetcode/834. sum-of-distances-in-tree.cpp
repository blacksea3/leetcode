#include "public.h"

//188ms, 49.18%
//无向、连通的树是不含回路的
//首先我们任意选择一个节点当作root, 这里我们选择0节点
//然后从这个节点开始DFS得到它的距离和, 同时我们一定能够获取以接下来的节点作为root的树节点总量
//然后最终结果再用一个DFS通过自己深度、父亲结果可计算得到.

class Solution {
private:
	vector<int> tn_nums;
	vector<int> depths;
	vector<int> res;
	vector<unordered_set<int>> con;
	int gblN;

	//后序遍历, 获取以root为根的节点数(包括根), 同时获取总深度(即各个节点到0的距离和)
	int DFS1(int root, int depth)
	{
		int thisnodes = 0;
		for (auto& c : con[root])
		{
			con[c].erase(root);
			thisnodes += DFS1(c, depth + 1);
		}
		tn_nums[root] = thisnodes + 1;
		depths[root] = depth;
		return thisnodes + 1;
	}

	//DFS, 注意: 输入的是父亲节点
	void DFS2(int parent)
	{
		int parent_nodes = tn_nums[parent];
		for (auto& c : con[parent])
		{
			res[c] = res[parent] - tn_nums[c] + (gblN - tn_nums[c]);
			DFS2(c);
		}
	}

public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		gblN = N;
		tn_nums.resize(N);
		res.resize(N);
		depths.resize(N);
		con.resize(N);
		//先获取关系图
		for (auto& e : edges)
		{
			con[e[0]].insert(e[1]);
			con[e[1]].insert(e[0]);
		}

		//把0当成根: 首先得出0的结果
		DFS1(0, 0);
		res[0] = 0;
		for (int i = 0; i < N; ++i)
			res[0] += depths[i];
		//然后再DFS一次得出结果
		DFS2(0);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> edges = { {0, 1}, { 0,2 }, { 2,3 }, { 2,4 }, { 2,5 } };
	auto res = s->sumOfDistancesInTree(6, edges);
	return 0;
}
