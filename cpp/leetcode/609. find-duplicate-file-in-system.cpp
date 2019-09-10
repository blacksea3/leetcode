#include "public.h"

//300ms, 7.46%
//unordered_map

class Solution {
private:
	//用ch分割raw, 变成一个string列表
	vector<string> mStringSplit(string raw, char ch)
	{
		int loc = 0;
		string s = "";
		vector<string> res;

		while (loc < raw.size())
		{
			if (raw[loc] == ch)
			{
				res.emplace_back(s);
				s = "";
			}
			else
			{
				s.push_back(raw[loc]);
			}
			loc++;
		}
		res.emplace_back(s);
		return res;
	}


public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> files;

		for (auto& path : paths)
		{
			//用空格切分
			vector<string> preString = mStringSplit(path, ' ');
			string preDir = preString[0] + "/";
			for (int index = 1; index < preString.size(); ++index)
			{
				int contentIndex = preString[index].find("(");
				files[preString[index].substr(contentIndex)].emplace_back(preDir + preString[index].substr(0, contentIndex));
			}
		}

		vector<vector<string>> res;
		for (auto& file : files)
		{
			if (file.second.size() > 1) res.emplace_back(file.second);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	auto res = s->findDuplicate(paths);
	return 0;
}
*/
