#include "public.h"

//
//我是蠢比

/*
class Solution {
private:
	static bool msort(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.first < p2.first) return true;
		else if (p1.first > p2.first) return false;
		else return p1.second < p2.second;
	}

public:
	int longestSubsequence(vector<int>& arr, int difference) {
		if (difference < 0)
		{
			reverse(arr.begin(), arr.end());
			difference *= -1;
		}

		int aSize = arr.size();
		int res = 0;
		vector<vector<int>> umv(20001, vector<int>{}); //+10000

		for (int index = 0; index < aSize; ++index)
		{
			umv[arr[index] + 10000].emplace_back(index);
		}

		if (difference == 0)
		{
			for (auto& iumv : umv) res = max(res, (int)iumv.size());
			return res;
		}

		unordered_map<int, int> mods; //模结果和前一个数


		vector<bool> issearched(aSize, false);
		int startindex = 0;
		while (startindex < aSize)
		{
			int tsindex = startindex;
			//确定起始索引
			while (tsindex < aSize)
			{
				if (issearched[tsindex]) tsindex++;
			    else if ((mods.find(arr[tsindex] % difference) != mods.end()) && (arr[tsindex] >= mods[arr[tsindex] % difference]))
				{
					issearched[tsindex] = true;
					tsindex++;
				}
				else break;
			}

			if (tsindex == aSize) break;
			int lastSIndex = tsindex;   //当前起始坐标tsindex
			issearched[tsindex] = true;

			int beginV = arr[tsindex];
			int nextV = beginV + difference;
			int tempres = 1;

			mods[beginV%difference] = beginV; //记录当前数的模

			while (true)
			{
				if ((nextV > 10000) || (nextV < -10000)) break;
				if (umv[nextV + 10000].empty()) break;
				else
				{
					vector<int>::iterator iter = upper_bound(umv[nextV + 10000].begin(), umv[nextV + 10000].end(), tsindex);
					if (iter == umv[nextV + 10000].end()) break;
					else
					{
						nextV += difference;
						tempres++;
						tsindex = *iter;
						issearched[tsindex] = true;
					}
				}
			}
			res = max(res, tempres);
			startindex = lastSIndex + 1;
		}
		return res;
	}
};
*/

/*
int main()
{
	Solution* s = new Solution();
	
	vector<int> arr0 = { -10,21,3,25,-8,-14,-18,19,-11,6,11,-3,1,21,11,-15,1,0,-14,9,-20,3,27,-24,-12,-2,23 };
	cout << s->longestSubsequence(arr0, -3) << endl;

	vector<int> arr = { 1,2,3,4 };
	cout << s->longestSubsequence(arr, 1) << endl;
	vector<int> arr2 = { 1,3,5,7 };
	cout << s->longestSubsequence(arr2, 1) << endl;
	vector<int> arr3 = { 1,5,7,8,5,3,4,2,1 };
	cout << s->longestSubsequence(arr3, -2) << endl;

	return 0;
}
*/