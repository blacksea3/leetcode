#include "public.h"

//188ms, 49.18%
//������ͨ�����ǲ�����·��
//������������ѡ��һ���ڵ㵱��root, ��������ѡ��0�ڵ�
//Ȼ�������ڵ㿪ʼDFS�õ����ľ����, ͬʱ����һ���ܹ���ȡ�Խ������Ľڵ���Ϊroot�����ڵ�����
//Ȼ�����ս������һ��DFSͨ���Լ���ȡ����׽���ɼ���õ�.

class Solution {
private:
	vector<int> tn_nums;
	vector<int> depths;
	vector<int> res;
	vector<unordered_set<int>> con;
	int gblN;

	//�������, ��ȡ��rootΪ���Ľڵ���(������), ͬʱ��ȡ�����(�������ڵ㵽0�ľ����)
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

	//DFS, ע��: ������Ǹ��׽ڵ�
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
		//�Ȼ�ȡ��ϵͼ
		for (auto& e : edges)
		{
			con[e[0]].insert(e[1]);
			con[e[1]].insert(e[0]);
		}

		//��0���ɸ�: ���ȵó�0�Ľ��
		DFS1(0, 0);
		res[0] = 0;
		for (int i = 0; i < N; ++i)
			res[0] += depths[i];
		//Ȼ����DFSһ�εó����
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
