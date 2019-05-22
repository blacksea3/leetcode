#include "public.h"

//4ms 99.38%

//use BackTracking

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res = {};
		string pre = "";
		int leftnum = 0;
		int rightnum = 0;
		bool isneedrecall = false;

		while (true)
		{
			if (isneedrecall)
			{
				while (true)
				{
					//judge: there has a () combination ?
					pre.pop_back();
					rightnum--;
					if (pre[pre.size() - 1] == ')') break;
					else
					{
						pre.pop_back();
						leftnum--;
					}
					if (pre.empty()) goto end;
				}

				while (pre[pre.size() - 1] == ')') //remove unexpected ), until (
				{
					pre.pop_back();
					rightnum--;
				}
				pre[pre.size() - 1] = ')';
				rightnum++;
				leftnum--;
				isneedrecall = false;
			}
			else
			{
				if (leftnum < n)
				{
					pre += "(";
					leftnum++;
				}
				else
				{
					if (rightnum < n)
					{
						pre += ")";
						rightnum++;
					}
					else
					{
						res.push_back(pre);
						isneedrecall = true;
					}
				}
			}
		}
	end:
		return res;
	}
};