#include "public.h"

//156ms, 39.02%
//首先将技能全部二进制表示
//由于技能最多16个, 故采用暴力dp, dp[i]:技能树为i时的人员们,
//初始化dp[0] = 0, dp[其他]=全部人员, 然后遍历people, 对所有的dp进行一轮更新: 如果增加了当前人之后技能变了, 且此技能树消耗人员数<已记录的, 那么更新
//最后返回dp[全技能]
//dp最大65536

class Solution {
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		vector<int> total;
		for (int i = 0; i < people.size(); ++i) total.push_back(i);
		vector<vector<int>> dp(1 << req_skills.size(), total);
		dp[0] = {};

		unordered_map<string, int> convert;
		for (int i = 0; i < req_skills.size(); ++i)
		{
			convert[req_skills[i]] = 1 << i;
		}

		for (int j = 0; j < people.size(); ++j)
		{
			int temp = 0;
			for (auto& sk : people[j])
			{
				temp |= convert[sk];
			}

			for (int i = 0; i < dp.size(); ++i)
			{
				if ((i | temp) > i && dp[i | temp].size() > dp[i].size() + 1)
				{
					vector<int> mid = dp[i];
					mid.push_back(j);
					dp[i | temp] = mid;
				}
			}
		}
		return dp[(1 << req_skills.size()) - 1];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> req_skills = { "java","nodejs","reactjs" };
	vector<vector<string>> people = { {"java"},{"nodejs"},{"nodejs","reactjs"} };
	auto res = s->smallestSufficientTeam(req_skills, people);
	return 0;
}
*/
