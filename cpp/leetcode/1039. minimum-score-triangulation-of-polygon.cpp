#include "public.h"

//28ms, 9.64%
//动态规划
//维护dp[start][end],:注意这个数组有一些空间没有用到
//对end与start间隔遍历,从2至size-1;对start遍历,从0至size-1;对mid遍历,从start+1至end-1遍历
//注意用start->mid->end三角形分割两个顶点是连续的多边形,而且这多边形的起始与终点坐标能够直接表示出来!
//最后直接用dp[0][size-1],算到最后无论从哪里开始,绕了一圈都是一个结果

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

