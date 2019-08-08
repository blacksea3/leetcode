#include "public.h"

//28ms, 79.65%
//拆分字符串并计数

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> um;

		for (auto& cp : cpdomains)
		{
			//获取数字
			int loc = 0;
			while (isdigit(cp[loc])) loc++;
			int times = stoi(cp.substr(0, loc));
			loc++;
			um[cp.substr(loc)] += times;
			//获取各个.的位置
			while (loc < cp.size() && isalpha(cp[loc])) loc++;
			if (loc != cp.size())
			{
				um[cp.substr(++loc)] += times;
			}
			while (loc < cp.size() && isalpha(cp[loc])) loc++;
			if (loc != cp.size())
			{
				um[cp.substr(++loc)] += times;
			}
		}

		//生成结果
		vector<string> res;
		for (auto& ium : um)
		{
			string temp = "";
			temp += to_string(ium.second);
			temp += " ";
			temp += ium.first;
			res.push_back(temp);
		}
		return res;
	}
};
