#include "public.h"

//4ms, 95.02%
//�������, O(n)
//��������һ��n^2����, �ʶԳ�, һ����ѭ��->�� ��->�� ��->�� ��->�ϵ�˳��
//��������ּ�����Ϊѭ���߽�����

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int maxCount = n * n;
		int preCount = 1;
		int left = 0;
		int right = n - 1;
		int up = 0;
		int down = n - 1;

		while (preCount <= maxCount)
		{
			for (int c = left; c <= right; ++c) res[up][c] = preCount++;
			up++;
			for (int r = up; r <= down; ++r) res[r][right] = preCount++;
			right--;
			for (int c = right; c >= left; --c) res[down][c] = preCount++;
			down--;
			for (int r = down; r >= up; --r) res[r][left] = preCount++;
			left++;
		}
		return res;
	}
};
