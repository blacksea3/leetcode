#include "public.h"

//
//混合dp
//dp[i][j] 删掉它们用的最小次数

//dp[i][j]等于多个内部分两块然后切开
//如果arr[i] == arr[j] 那么 dp[i][j] = min(dp[i - 1][j - 1], dp[i][j])

//初始化dp[i][i] = 1
// dp[i][i + 1] = 2 如果arr[i] != arr[i + 1] 否则 1

class Solution {
public:
	int minimumMoves(vector<int>& arr) {
		int aSize = arr.size();
		vector<vector<int>> dp(aSize, vector<int>(aSize, INT_MAX));

		for (int i = 0; i < aSize; ++i)
			dp[i][i] = 1;

		for (int i = 0; i < aSize - 1; ++i)
		{
			if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
			else dp[i][i + 1] = 2;
		}

		for (int len = 3; len <= aSize; ++len)
		{
			for (int left = 0; left <= aSize - len; ++left)
			{
				int right = left + len - 1;
				for (int mid = left; mid < right; ++mid)
				{
					dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
				}
				if (arr[left] == arr[right])
					dp[left][right] = min(dp[left][right], dp[left + 1][right - 1]);
			}
		}
		return dp[0][aSize - 1];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> arr = { 1,2 };
	cout << s->minimumMoves(arr) << endl;     //2
	vector<int> arr2 = { 1,3,4,1,5 };
	cout << s->minimumMoves(arr2) << endl;    //3
	vector<int> arr3 = { 2,5,1,3,4,1,6,5 };
	cout << s->minimumMoves(arr3) << endl;    //4
	vector<int> arr4= { 17,6,5,18,17,4,18,8,16,8,12,1,5,14,14,6,17,18,2,19,11,15,8,18,7,8,20,2,10,3,18,17,18,18,8,9,20,3,16,19,6,9,8,8,16,19,13,8,5,20 };
	cout << s->minimumMoves(arr4) << endl;    //25
	return 0;
}
*/
