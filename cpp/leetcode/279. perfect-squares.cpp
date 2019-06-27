#include "public.h"

//����������������ƽ����, ������, �Ժ����Ż�
//DP problem, 252ms, 22.08%, ��˵python ������DP�ᳬʱ?

//���ǵ����µ����Σ�������ÿ�ζ���������ã�
//�������12: (size): 9+1+1+1 > 4+4+4

//ע�⵽���µ����Σ�����ĳ��n����һ����һ������С��n������ּ���ĳ��ƽ����
//0��default
//1��de + ->1
//2��1 + ->1
//3��2 + ->1
//4��de + ->4

//n�� min(n-1, n-4, n-9, ...) + 1  ???

class Solution {
public:
	int numSquares(int n) {
		//DP, O(n*sqrt(n))

		vector<int> dp(n + 1, 0);

		for (int i = 1; i <= n; ++i)
		{
			int temp = INT_MAX;
			for (int j = 1; j <= (int)(sqrt(i));++j)
			{
				temp = min(dp[i - j * j], temp);
			}
			dp[i] = temp + 1;
		}
		return dp[n];
	}
};
