#include "public.h"

//8ms, 53.44%
//模拟

class Solution {
public:
	string toGoatLatin(string S) {
		//判断每个单词, 然后挨个计算
		int index = 1;
		int startloc = 0;
		string res = "";
		while (startloc < S.size())
		{
			int temploc = startloc;
			//突进查询
			while (temploc < S.size() && S[temploc] != ' ') temploc++;
			//截取然后操作
			string tempstr = S.substr(startloc, temploc - startloc);
			if (tempstr[0] == 'a' || tempstr[0] == 'e' || tempstr[0] == 'i' || tempstr[0] == 'o' || tempstr[0] == 'u' ||
				tempstr[0] == 'A' || tempstr[0] == 'E' || tempstr[0] == 'I' || tempstr[0] == 'O' || tempstr[0] == 'U')
				tempstr += "ma";
			else
			{
				tempstr.push_back(tempstr[0]);
				tempstr.erase(tempstr.begin());
				tempstr += "ma";
			}
			for (int i = 1; i <= index; ++i) tempstr.push_back('a');
			res += tempstr;
			res.push_back(' ');
			index++;
			startloc = temploc + 1;
		}
		//去除末尾空格
		res.pop_back();
		return res;
	}
};
