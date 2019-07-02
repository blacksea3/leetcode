#include "public.h"

//复杂DP problem
//考虑到行远大于列, 对列进行划分
//双循环遍历每一列, 在第一层循环内开始初始化vector<int> curSum记录每一行的当前所有列的和

//然后如果j之前存在位置i满足curSum[j] - curSum[i] <= K, 表明以位置j结尾的序列有满足条件不大于K的, 注意到我们应当对curSum预排序, 然后可以找到最小的curSum[i]满足上述的不等式, 对应位置即是以j结尾且相加和不大于K的最大序列的开始位置, 比较并决定是否更新当前的最大序列

//我不是很清楚题意: 题目貌似隐藏了一定存在<=k的矩阵和?, 否则怎么不说不存在怎么办呢?

//大约是个O(m*m*n*log(n))的复杂度?

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
				if (preSum < k) continue;   //直接剪枝, 这是因为不存在没有判断过的矩阵和<k且比现在的preSum还大了
				else preSum = 0;

				set<int> sumSet;
				sumSet.insert(0); //哨兵值, 如果lower_bound查到了这个值, 说明存在一个从第一行到当前行的矩阵元素和满足条件
				for (int r = 0; r < rows; ++r) {
					preSum += prerowSum[r];
					auto it = sumSet.lower_bound(preSum - k);  //查找第一个>=curSum-k的下标, 注意: sumSet是个升序排序的set
					if (it != sumSet.end())
					{
						if (preSum - *it == k) return k;   //直接返回k
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

