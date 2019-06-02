#include "public.h"

//THIS BRUTE FORCE is TLE !!! O(n^4)

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size() + 1, 0));

		//dp[i][j] means: i row: from 0 to j-1 the sum of values.
		//  dp[i][j1] - dp[i][j2] = i row: from j2 to j1-1 the sum of values;

		//BRUTE FORCE

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 1; j <= matrix[0].size(); j++)
			{
				dp[i][j] = dp[i][j - 1] + matrix[i][j - 1];
			}
		}

		//main big loop, O(n^4)

		int res = 0;
		for (int startrow = 0; startrow < matrix.size(); startrow++)
		{
			vector<vector<int>> presum(matrix[0].size(), vector<int>(matrix[0].size(), 0));
			//here use presum
			for (int endrow = startrow; endrow < matrix.size(); endrow++)
			{
				for (int startcolumn = 0; startcolumn < matrix[0].size(); startcolumn++)
				{
					for (int endcolumn = startcolumn; endcolumn < matrix[0].size(); endcolumn++)
					{
						presum[startcolumn][endcolumn] += (dp[endrow][endcolumn+1] - dp[endrow][startcolumn]);
						if (presum[startcolumn][endcolumn] == target) 
							res++;
					}
				}
			}
			//presum.clear();
			
			//reset
			//for (int startcolumn = 0; startcolumn < matrix[0].size(); startcolumn++)
			//{
			//	for (int endcolumn = startcolumn; endcolumn < matrix[0].size(); endcolumn++)
			//	{
			//		presum[startcolumn][endcolumn] = 0;
			//	}
			//}
		}
		return res;
	}
};


int main()
{
	Solution * s = new Solution();

	vector<vector<int>> matrix = { {0,1,0},{1,1,1},{0,1,0} };
	cout << s->numSubmatrixSumTarget(matrix,0);
	return 0;
}
