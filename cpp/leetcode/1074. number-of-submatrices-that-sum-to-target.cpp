#include "public.h"

//8976ms, 26.51%
//m��n��, O(m*n*n)
//��¼ÿһ�е�ǰi�еĺ�
//Ȼ����н���˫ѭ��, ʹ��unordered_map, ��¼ǰi��, ĳһ���еĺ�ֵ, �����ǰǰj�еĺ�ֵsum - target�����ҵ�������0, ˵������i����j�м�, ĳһ����, �����ֵΪtarget

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int res = 0;

		int rows = matrix.size();
		if (rows == 0) return 0;
		int cols = matrix[0].size();

		//����ǰ?�еĺ�
		vector<vector<int>> colsum(rows, vector<int>(cols + 1, 0)); //ע��colsum[0] = 0, dumpvalue
		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				colsum[row][col + 1] = colsum[row][col] + matrix[row][col];
			}
		}

		//��ѭ��, O(m*n*n)
		for (int colstart = 0; colstart < cols; ++colstart)
		{
			for (int colend = colstart; colend < cols; ++colend)
			{
				unordered_map<int, int> history_rowsum;
				history_rowsum[0] = 1;
				int prerowsum = 0;
				for (int row = 0; row < rows; ++row)
				{
					prerowsum += colsum[row][colend + 1] - colsum[row][colstart];
					if (history_rowsum.find(prerowsum - target) != history_rowsum.end())
					{
						res += history_rowsum[prerowsum - target];
					}
					history_rowsum[prerowsum]++;
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {1,-1},{-1,1} };
	auto res = s->numSubmatrixSumTarget(matrix, 0);
	return 0;
}

