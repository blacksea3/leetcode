#include "public.h"

//44ms, 98.37%
//复用300.最长上升子序列 DP+二分 O(nlogn)
//先对信封排序: 宽度升序, 高度降序
//特别注意: 高度降序的目的是:
//  例如 [3,5], [6,8], [6,9] 这是按照高度升序的, 假设对高度我们应用最长上升子序列, 那么会三个连起来, 这不满足俄罗斯套娃的双重严格大于
// 因此认为对宽度相同下, 高度降序排序, 使得[6,9]在[6,8]前面, 两个永远不会相互连接

class Solution {
private:
	static bool msort(vector<int> const& v1, vector<int> const& v2)
	{
		if (v1[0] < v2[0]) return true;
		else if (v1[0] > v2[0]) return false;
		else return v1[1] > v2[1];
	}

	int lengthOfLIS(vector<vector<int>>& nums) {
		vector<int> dp;

		for (auto& num : nums)
		{
			vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), num[1]);
			if (iter == dp.end()) dp.emplace_back(num[1]);
			else dp[iter - dp.begin()] = num[1];
		}
		return dp.size();
	}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), msort);

		return lengthOfLIS(envelopes);
	}
};

/*
//688ms, 58.51%
//O(n^2) DP解法
//记录前面的最大信封数, 往数字大的方向更新

class Solution {
private:
	//经过查询资料，发现在VS2015中都是严格比较的，如果两个元素相等，必须返回false。故改成如下代码，可以通过编绎。
	static bool msort(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[0] < v2[0];
	}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		vector<int> dp(envelopes.size(), 0);

		sort(envelopes.begin(), envelopes.end(), msort);

		for (int i = 0; i < envelopes.size(); ++i)
		{
			int res = 1;
			for (int j = 0; j < i; ++j)
			{
				if ((envelopes[j][0] < envelopes[i][0]) && (envelopes[j][1] < envelopes[i][1]))
					res = max(res, dp[j] + 1);
			}
			dp[i] = res;
		}

		int rmax = 0;
		for (auto& idp : dp) rmax = max(idp, rmax);
		return rmax;
	}
};
*/

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> envelopes = { {5, 4},{6, 4},{6, 7},{2, 3} };
	cout << s->maxEnvelopes(envelopes);
	return 0;
}
*/
