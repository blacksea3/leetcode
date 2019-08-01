#include "public.h"

//652ms, 10.53%
//���鼯
//����dislikes������֪�����ߵĹ�ϵ, �����ǲ���һ�����������ͬһ�����ϲ�����ٶ���0/1, �ֱ����������
//   ����ʱע��:���������ǳ�ʼ��״̬-1,��ô����, ����һ���ǳ�ʼ��״̬, ��ô����ú���һ����һ��, �����������ǳ�ʼ��״̬
//   �����ǲ�ͬ��, ��ôֱ�Ӻϲ�, �����������ǳ�ʼ��״̬��������ͬ��, ��ô����һ��������˸�����, Ȼ��ϲ�

//��������һ������, �ǲ�ͬ�鲻Ҫ��, ����ͬ���򷵻�false

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
						//������d[1]��һ�����ϵ������˵���
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
