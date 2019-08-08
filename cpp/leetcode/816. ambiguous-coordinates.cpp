#include "public.h"

//24ms, 65.22%
//双重循环切割S, 然后对左右结果进行笛卡尔积运算

class Solution {
private:
	vector<string> genstr(string pre)
	{
		if (pre.size() == 1) return { pre };
		else if (pre[0] == '0' && pre[pre.size() - 1] == '0') return {};
		else if (pre[0] == '0')
		{
			string s = "0.";
			s += pre.substr(1);
			return { s };
		}
		else if (pre[pre.size() - 1] == '0') return { pre };
		else
		{
			vector<string> re;
			re.push_back(pre);
			for (int pointloc = 1; pointloc < pre.size(); ++pointloc)
			{
				re.push_back(pre.substr(0, pointloc) + "." + pre.substr(pointloc));
			}
			return re;
		}
	}

public:
	vector<string> ambiguousCoordinates(string S) {
		vector<string> res;
		S.pop_back();
		S.erase(S.begin());

		for (int i = 1; i < S.size(); ++i)
		{
			vector<string> left = genstr(S.substr(0, i));
			vector<string> right = genstr(S.substr(i));

			for (auto& l : left)
			{
				for (auto& r : right)
				{
					string temp = "(";
					temp += l;
					temp += ", ";
					temp += r;
					temp += ")";
					res.push_back(temp);
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->ambiguousCoordinates("(00001)");
	return 0;
}
*/
