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

				for (int row = 0; row < rows; ++row)
				{
					preSum += prerowSum[row];
					if (preSum <= k) res = max(res, preSum);
					if (preSum < 0) preSum = 0;
				}
				if (preSum < k) continue;   //ֱ�Ӽ�֦, ������Ϊ������û���жϹ��ľ����<k�ұ����ڵ�preSum������
				else preSum = 0;

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

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {1, 0, 1},{0, -2, 3} };
	cout << s->maxSumSubmatrix(matrix, 2);
	return 0;
}

