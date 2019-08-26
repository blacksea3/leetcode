#include "BinaryTree.h"

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

		for (int colstart = 0; colstart < cols; ++colstart)
		{
			for (int colend = colstart; colend < cols; ++colend)
			{
				for (int rowstart = 0; rowstart < rows; ++rowstart)
				{
					int presum = colsum[rowstart][colend + 1] - colsum[rowstart][colstart];
					if (presum == target) res++;
					for (int rowend = rowstart + 1; rowend < rows; ++rowend)
					{
						presum += colsum[rowend][colend + 1] - colsum[rowend][colstart];
						if (presum == target) res++;
					}
				}
			}
		}
		return res;
	}
};

/*
int main() {
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {0,1,0},{1,1,1},{0,1,0} };
	cout << s->numSubmatrixSumTarget(matrix, 0);



	return 0;
}

*/