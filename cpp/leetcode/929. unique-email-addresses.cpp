#include "public.h"

//48ms, 50.94%
//处理字符串, 直接往unordered_set插入, 最后看size

class Solution {
private:
	string convert(string s)
	{
		int loc = 0;
		bool ispass = false;
		while (s[loc] != '@')
		{
			if (ispass)
			{
				s.erase(s.begin() + loc);
			}
			else if (s[loc] == '.')
			{
				s.erase(s.begin() + loc);
			}
			else if (s[loc] == '+')
			{
				s.erase(s.begin() + loc);
				ispass = true;
			}
			else loc++;
		}
		return s;
	}

public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> us;
		for (auto& e : emails)
		{
			us.insert(convert(e));
		}
		return us.size();
	}
};

