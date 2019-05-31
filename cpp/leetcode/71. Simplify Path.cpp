#include "public.h"

//12ms, 95.06%

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vs = {};

		if (path.size() == 1) return path;  //only a '/'

		string prestr = "";
		int loc = 1;
		while (loc < path.size())
		{
			if (path[loc] == '/')
			{
				if (prestr != "")
				{
					vs.push_back(prestr);
					prestr = "";
				}
			}
			else
			{
				if (path[loc] != '.')
				{
					prestr += path[loc];
				}
				else //note that if has ., there must only have one or two '.' for special infomation,
					//otherwise this is a regular path!
				{
					if (loc < path.size() - 2)
						if (path[loc + 1] == '/') loc += 1;
						else if (path[loc + 1] == '.')
						{
							if (path[loc + 2] == '/')
							{
								if (!vs.empty()) vs.pop_back();
								loc += 2;
							}
							else
							{
								prestr += "..";
								prestr += path[loc + 2];
								loc += 2;
							}
						}
						else
						{
							prestr += ".";
							prestr += path[loc + 1];
							loc += 1;
						}
					else if (loc == path.size() - 2)
						if (path[loc + 1] == '/') loc += 1;
						else if (path[loc + 1] == '.')
						{
							if (!vs.empty()) vs.pop_back();
							loc += 2;
						}
						else
						{
							prestr += ".";
							prestr += path[loc + 1];
							loc += 1;
						}
					else
					{
						loc += 1;
					}
				}
			}
			++loc;
		}
		if (prestr != "") vs.push_back(prestr);

		if (vs.empty()) return "/";
		else
		{
			string returns = "";
			for (auto avs:vs)
				returns += "/" + avs;
			return returns;
		}
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->simplifyPath("/...//b////c/d//././/..");
	return 0;
}