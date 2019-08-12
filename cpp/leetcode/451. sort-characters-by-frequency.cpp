#include "public.h"

//20ms, 78.42%
//统计词频, 然后生成就行

class Solution {
private:
	static bool msort(const pair<int, char>& p1, const pair<int, char>& p2)
	{
		if (p1.first > p2.first) return true;
		else if (p1.first < p2.first) return false;
		else return p1.second >= p2.second;
	}

public:
	string frequencySort(string s) {
		unordered_map<char, int> umcounter;
		for (auto& iis : s) umcounter[iis]++;

		vector<pair<int, char>> vcounter;
		for (auto& iter_umcounter:umcounter) vcounter.push_back(pair<int, char>{iter_umcounter.second, iter_umcounter.first});
		sort(vcounter.begin(), vcounter.end(), msort);

		string res = "";

		for (auto& iter_vcounter : vcounter)
		{
			for (int i = 0; i < iter_vcounter.first; ++i)
			{
				res.push_back(iter_vcounter.second);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->frequencySort("aabc");
	return 0;
}
*/
