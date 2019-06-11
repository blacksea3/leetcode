#include "public.h"

//BFS problem
//I just copy another solution, I will write my own code later

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue <pair<int, int>> q;
		int m = matrix.size();
		int n = matrix[0].size();
		vector <pair<int, int>> around = { {0,1},{0,-1},{-1,0},{1,0} }; //��Χ�ڵ�
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0) q.push({ i,j }); //��Ԫ��Ϊ0 �ĵ��������
				else matrix[i][j] = INT_MAX;
			}
		}
		while (!q.empty())
		{
			pair <int, int> temp = q.front();
			q.pop();
			for (int b = 0; b < 4; ++b) //̽����Χ�ڵ�
			{
				int y = temp.first + around[b].first;
				int x = temp.second + around[b].second;
				//�ж���ͼ�ڣ����µ��Ԫ�ش��ڸõ�Ԫ�ء�
				if (0 <= x && x < n && 0 <= y && y < m && matrix[temp.first][temp.second] < matrix[y][x])
				{
					matrix[y][x] = matrix[temp.first][temp.second] + 1;
					q.push({ y,x });
				}
			}
		}
		return matrix;
	}
};
