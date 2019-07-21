#include "public.h"

//
//超级DP
//

class Solution {
private:
	vector<vector<int>> pub;
	void DFS(int remainlen, int maybelen, const vector<int>& nums, vector<int> prenums)
	{
		if (remainlen <= 0) return;

		if (prenums.size() == (maybelen - 1))
		{
			if (find(nums.begin(), nums.end(), remainlen) != nums.end())
			{
				prenums.push_back(remainlen);
				pub.push_back(prenums);
			}
		}
		else
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				prenums.push_back(nums[i]);
				remainlen -= nums[i];
				DFS(remainlen, maybelen, nums, prenums);
			}
		}
	}

	//从start至end的下标中找到可以组成K的
	//例如: start = 1, end = 5, 长度就是5, K=3, 则可能的组合是1 1 3 ...,返回下标们
	//start = 1, end = 7, 长度就是7, K=3, 可能: 1 1 5/ 1 3 3....
	vector<vector<pair<int, int>>> combine(int start, int end, int K)
	{
		vector<vector<pair<int, int>>> res;
		vector<int> nums;

		for (int i = 1; i <= 30; i += (K - 1))
			nums.push_back(i);

		pub.clear();
		DFS(end - start + 1, K, nums, {});

		for (int i = 0; i < pub.size(); ++i)
		{
			int temp = start;
			vector<pair<int, int>> s;
			for (int j = 0; j < pub[i].size(); ++j)
			{
				s.push_back(pair<int, int>{temp, temp + pub[i][j] - 1});
				temp += pub[i][j];
			}
			res.push_back(s);
		}
		return res;
	}

public:
	int mergeStones(vector<int>& stones, int K) {
		if (K > 2 && (stones.size() % (K - 1)) != 1) return false;

		vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));

		//init
		for (int i = 0; i < stones.size(); ++i)
			dp[i][i] = stones[i];

		//按长度更新
		for (int len = 1 + K - 1; len <= stones.size(); len += K - 1)
		{
			for (int start = 0; start <= stones.size() - len; ++start)
			{
				vector<vector<pair<int, int>>> group = combine(start, start + len - 1, K);
				int tempval = INT_MAX;

				for (int j = 0; j < group.size(); ++j)
				{
					int inner = 0;
					for (int p = 0; p < group[j].size(); ++p)
					{
						inner += dp[group[j][p].first][group[j][p].second];
					}
					tempval = min(tempval, inner);
				}
				dp[start][start + len - 1] = tempval;
			}
		}

		return dp[0][K - 1];
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> stones = {3,2,4,1};
	auto res = s->mergeStones(stones, 2);
	return 0;
}
