#include "public.h"

//0ms, 100%
//模拟

class Solution {
public:
	string maskPII(string S) {
		//判断S是啥
		if (S.find("@") != S.npos)
		{
			//邮箱
			int preloc = 0;
			int midloc;
			while (preloc < S.size())
			{
				if (S[preloc] == '@') midloc = preloc;
				else
				{
					if (S[preloc] <= 'Z' && S[preloc] >= 'A') S[preloc] = S[preloc] - 'A' + 'a';
				}
				preloc++;
			}
			S = S.substr(0, 1) + "*****" + S.substr(midloc - 1);
			return S;
		}
		else
		{
			//数数字个数
			int len = 0;
			string last;
			int preloc = S.size() - 1;
			while (preloc >= 0)
			{
				if (isdigit(S[preloc]))
				{
					len++;
					if (len <= 4) last.insert(last.begin(), S[preloc]);
				}
				preloc--;
			}
			if (len == 10) return "***-***-" + last;
			else
			{
				string returnstr = "+";
				for (int i = 11; i <= len; ++i)
				{
					returnstr.push_back('*');
				}
				returnstr += "-***-***-";
				returnstr += last;
				return returnstr;
			}
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//auto res = s->maskPII("LeetCode@LeetCode.com");
	auto res = s->maskPII("1(234)567-890");
	
	return 0;
}
*/
