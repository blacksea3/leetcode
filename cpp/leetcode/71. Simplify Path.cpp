#include "public.h"

//8ms, 93.33%
//数组, 先当作栈处理, 然后再一轮遍历
//语言技巧: 使用stringstream sstr, 配合getline(sstr,tempStr,'//')分割字符串

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vs;
		stringstream sStr(path);
		string tempStr;
		while (getline(sStr, tempStr, '/'))
		{
			if (tempStr == ".") continue;
			else if (tempStr != "..")
			{
				if (!tempStr.empty()) vs.emplace_back(tempStr);
			}
			else if (!vs.empty()) vs.pop_back();
		}
		tempStr.clear();
		for (int i = 0; i < vs.size();)
		{
			tempStr.append("/" + vs[i++]);
		}
		return tempStr.empty() ? "/" : tempStr;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string res = s->simplifyPath("/...//b////c/d//././/..");
	return 0;
}
*/
