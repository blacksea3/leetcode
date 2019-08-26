#include "public.h"

//4ms, 92.11%
//ȷ����һ��ȫ��1
//������0/1����

//��һ��ȫ��1���������һ���ǵ�ǰ0���ĳ�1, һ���ǵ�ǰ1���ĳ�0(���и�)

class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		//���е��ѵ�һ�ж�Ū��1
		for (int r = 0; r < A.size(); ++r)
		{
			if (A[r][0] == 0)
			{
				for (int c = 0; c < A[0].size(); ++c)
				{
					A[r][c] = (A[r][c] == 0) ? 1 : 0;
				}
			}
		}

		//������һ���������е�0��1�и���������ָ���, ע��: ��һ��ȫ��0�����ͬʱ��������, ��Ϊ��������ж�ͳһ��ת, �е�0��1�и���������ָ�����һ����
		int res = 0;
		res += A.size()*pow(2, A[0].size() - 1);

		for (int c = 1; c < A[0].size(); ++c)
		{
			int zero = 0;
			int one = 0;
			for (int r = 0; r < A.size(); ++r)
			{
				if (A[r][c] == 1) one++;
				else zero++;
			}
			res += max(zero, one)*pow(2, A[0].size() - 1 - c);
		}
		return res;
	}
};
