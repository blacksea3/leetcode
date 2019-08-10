#include "public.h"

//
//暴力
//直接记录: 用户: 访问过的网站(此时要排序), 故按unordered_map<string, vector<pair<int, string>>> 记录
//然后暴力得到所有三连续网站: 用户名unordered_map<string, unordered_set<string>>

class Solution {
private:
	static bool msort(const pair<int, string>& v1, const pair<int, string>& v2)
	{
		if (v1.first < v2.first) return true;
		else if (v1.first > v2.first) return false;
		else return v1.second <= v2.second;
	}

public:
	vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
		unordered_map<string, vector<pair<int, string>>> umv;

		for (int i = 0; i < username.size(); ++i)
		{
			umv[username[i]].push_back(pair<int, string>{timestamp[i], website[i]});
		}

		for (auto& iumv : umv) sort(iumv.second.begin(), iumv.second.end(), msort);

		//生成三连续网站: 次数
		unordered_map<string, unordered_set<string>> umi;

		for (auto& iumv : umv)
		{
			int tempsize = iumv.second.size();
			for (int i = 0; i < tempsize - 2; ++i)
			{
				for (int j = i + 1; j < tempsize - 1; ++j)
				{
					for (int k = j + 1; k < tempsize; ++k)
					{
						string temps = iumv.second[i].second + " " + iumv.second[j].second + " " + iumv.second[k].second;
						umi[temps].insert(iumv.first);
					}
				}
			}
		}

		//找到出现次数最多的
		int resmax = 0;
		string ress = "";

		for (auto& iumi : umi)
		{
			if (iumi.second.size() > resmax)
			{
				resmax = iumi.second.size();
				ress = iumi.first;
			}
			else if (iumi.second.size() == resmax)
			{
				if (iumi.first < ress)
				{
					ress = iumi.first;
				}
			}
		}

		//拆分ress
		vector<string> res;
		int loc = 0;
		int lastrightloc = -1;
		while (loc < ress.size() && ress[loc] != ' ') loc++;
		res.push_back(ress.substr(lastrightloc + 1, loc - 1 - lastrightloc));
		lastrightloc = loc;
		loc++;
		while (loc < ress.size() && ress[loc] != ' ') loc++;
		res.push_back(ress.substr(lastrightloc + 1, loc - 1 - lastrightloc));
		lastrightloc = loc;
		loc++;
		while (loc < ress.size() && ress[loc] != ' ') loc++;
		res.push_back(ress.substr(lastrightloc + 1, loc - 1 - lastrightloc));
		lastrightloc = loc;

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> username = { "h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq" };
	vector<int> timestamp = { 527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930 };
	vector<string> website = { "hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw" };

	auto res = s->mostVisitedPattern(username, timestamp, website);
	return 0;
}
*/
