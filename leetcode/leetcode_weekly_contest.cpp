#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_WC

vector<vector<int>> Solution::colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
{
	//ֻҪ������߽�Ϳ��Կ�
	//�����ĵ���ͼ������ɢ,����ĸ������Ǻ����ĵ���ֵͬ,�򱣴���ĸ��������ɢ,ɾ�����ĵ�
	//����:������ֵͬ�ĵ�Ȼ����ɢ
	//���ڱ߽��,������ֵͬ�ĵ�Ȼ����ɢ

	//�����Ѿ�����/ɾ���ĵ�,��ɢʱ������,��Ϊ����ֵͬ

	//m��n��
	int m = grid.size();
	int n = grid[0].size();

	//ά��һ��stack�������ɢ�ĵ�
	//ά��һ��res����ȷ���Ǳ߽�ĵ�
	//ά��һ��full�����ڲ���
	int findcolor = grid[r0][c0];
	vector<pair<int, int>> stack = { pair<int,int>(r0,c0) };
	vector<pair<int, int>> res = {};
	vector<pair<int, int>> full = {};

	while (stack.size() > 0)
	{
		int same_time = 0;
		pair<int, int> pre_loc = stack[stack.size()-1];
		stack.pop_back();

		if ((pre_loc.first != 0) && (grid[pre_loc.first - 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first - 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.first != (m - 1)) && (grid[pre_loc.first + 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first + 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.second != 0) && (grid[pre_loc.first][pre_loc.second - 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second - 1));
			}
			same_time++;
		}
		if ((pre_loc.second != (n - 1)) && (grid[pre_loc.first][pre_loc.second + 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second + 1));
			}
			same_time++;
		}

		if (same_time == 4) full.push_back(pre_loc);
		else res.push_back(pre_loc);
	}

	for (int i = 0; i < res.size(); i++)
	{
		grid[res[i].first][res[i].second] = color;
	}
	return grid;
}

#else
#endif
