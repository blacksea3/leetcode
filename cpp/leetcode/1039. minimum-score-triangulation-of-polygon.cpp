#include "public.h"

//28ms, 9.64%
//��̬�滮
//ά��dp[start][end],:ע�����������һЩ�ռ�û���õ�
//��end��start�������,��2��size-1;��start����,��0��size-1;��mid����,��start+1��end-1����
//ע����start->mid->end�����ηָ����������������Ķ����,���������ε���ʼ���յ������ܹ�ֱ�ӱ�ʾ����!
//���ֱ����dp[0][size-1],�㵽������۴����￪ʼ,����һȦ����һ�����

class Solution {
private:
	int noborder(int num, int size)
	{
		return (num >= size) ? (num - size) : (num < 0) ? num + size : num;
	}

public:
	int minScoreTriangulation(vector<int>& A)
	{
		int size = A.size();
		vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

		for (int diff = 2; diff < A.size(); ++diff)
			for (int start = 0; start < A.size(); ++start)
			{
				int end = noborder(start + diff, size);
				int mul = A[start] * A[end];
				dp[start][end] = INT_MAX;
				for (int mid = noborder(start + 1, size); mid != end; mid = noborder(mid + 1, size))
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid][end] + mul * A[mid]);
			}

		return dp[0][size - 1];
	}
};

