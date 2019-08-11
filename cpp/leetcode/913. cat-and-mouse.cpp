#include "public.h"

//68ms, 76.19%
//dp: ��״̬ f(t,x,y) ��ʾ t ʱ�̣�����λ�� x ��èλ�� y ʱ�Ľ����0��1 �� 2��, 0:����, 1:����ʤ 2:èʤ
//��֪״̬: dp[t][0][y] = 1, dp[t][x][x] = 2, 
//״̬ת��: ��tѭ����������ߵ�dp[t+1][x->next][y] �������1��ô����1, �������2��ô����2, 
//è�෴
//��ʼλ����: dp[0][1][2]

//ע��: ���ѭ����t�λ�û�н��(t == 2*graph.size()), ˵���γɻ���, ��ƽ��

//д��: ��̽����, �����л�, ��ʵ��DFS���ݵ�д��

class Solution {
private:
	vector<vector<vector<int>>> dp;

	int DFS(const vector<vector<int>>& graph, int t, int x, int y)
	{
		if (t == graph.size() * 2) return 0;
		if (x == y) return dp[t][x][y] = 2;  //�ر�ע��:����x��y(�����è�߶���)���ᴥ��
		if (x == 0) return dp[t][x][y] = 1;  //�ر�ע��: ����������:һ����x(�����߶�������)����ʵ
		if (dp[t][x][y] != -1) return dp[t][x][y]; //�Ѿ�������������

		bool flag;
		if (t % 2 == 0) //������
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
		else  //è��
		{
			flag = true;
			for (int i = 0; i < graph[y].size(); ++i)
			{
				if (graph[y][i] != 0) //è���ܽ�����
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
