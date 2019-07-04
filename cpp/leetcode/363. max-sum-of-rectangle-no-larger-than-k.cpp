#include "public.h"

//����DP problem
//���ǵ���Զ������, ���н��л���
//˫ѭ������ÿһ��, �ڵ�һ��ѭ���ڿ�ʼ��ʼ��vector<int> curSum��¼ÿһ�еĵ�ǰ�����еĺ�

//Ȼ�����j֮ǰ����λ��i����curSum[j] - curSum[i] <= K, ������λ��j��β����������������������K��, ע�⵽����Ӧ����curSumԤ����, Ȼ������ҵ���С��curSum[i]���������Ĳ���ʽ, ��Ӧλ�ü�����j��β����ӺͲ�����K��������еĿ�ʼλ��, �Ƚϲ������Ƿ���µ�ǰ���������

//�Ҳ��Ǻ��������: ��Ŀò��������һ������<=k�ľ����?, ������ô��˵��������ô����?

//��Լ�Ǹ�O(m*m*n*log(n))�ĸ��Ӷ�?


class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int rows = matrix.size();
		if (!rows) return 0;
		int cols = matrix[0].size();
		if (!cols) return 0;

		int res = INT_MIN;
		for (int colstart = 0; colstart < cols; ++colstart)
		{
			vector<int> prerowSum(rows, 0);
			for (int colend = colstart; colend < cols; ++colend)
			{
				for (int row = 0; row < rows; ++row)
					prerowSum[row] += matrix[row][colend];
				int preSum = 0;

				/*
				for (int row = 0; row < rows; ++row)
				{
					preSum += prerowSum[row];
					if (preSum <= k) res = max(res, preSum);
					if (preSum < 0) preSum = 0;
				}
				if (preSum < k) continue;   //ֱ�Ӽ�֦, ������Ϊ������û���жϹ��ľ����<k�ұ����ڵ�preSum������
				else preSum = 0;*/

				set<int> sumSet;
				sumSet.insert(0); //�ڱ�ֵ, ���lower_bound�鵽�����ֵ, ˵������һ���ӵ�һ�е���ǰ�еľ���Ԫ�غ���������
				for (int r = 0; r < rows; ++r) {
					preSum += prerowSum[r];
					auto it = sumSet.lower_bound(preSum - k);  //���ҵ�һ��>=curSum-k���±�, ע��: sumSet�Ǹ����������set
					if (it != sumSet.end())
					{
						if (preSum - *it == k) return k;   //ֱ�ӷ���k
						else res = max(res, preSum - *it);
					}
					sumSet.insert(preSum);
				}
			}
		}

		return res;
	}
};

/*  //��֦���ڱ���, ��ע�͵�
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size();

		int output = -1e9;
		for (int lc = 0; lc < n; lc++)
		{
			vector<int> dp(m, 0);
			for (int rc = lc; rc < n; rc++)
			{
				for (int r = 0; r < m; r++)
					dp[r] += matrix[r][rc];

				int curSum = 0;
				for (int r = 0; r < m; r++)
				{
					curSum += dp[r];
					if (curSum <= k && output < curSum) output = curSum;
					if (curSum + dp[r] < 0) curSum = 0;
				}
				if (curSum < k) continue;

				curSum = 0;
				set<int> st{ 0 };
				for (int r = 0; r < m; r++)
				{
					curSum += dp[r];
					auto it = st.lower_bound(curSum - k);
					if (it != st.end())
					{
						if (*it == curSum - k) return k;
						if (curSum - *it > output) output = curSum - *it;
					}
					st.insert(curSum);
				}
			}
		}
		return output < -1e8 ? -1 : output;
	}
};*/

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {3},{-7},{3},{3},{3},{-10} };
	cout << s->maxSumSubmatrix(matrix, 2);
	return 0;
}

