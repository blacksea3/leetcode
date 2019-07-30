#include "public.h"

//4ms, 88.89%
//两种情况需要添加: 如果左括号没了还来右括号则来一个添加一个左括号, 如果最后左括号有多的, 那么最后再添加右括号

class Solution {
public:
	int minAddToMakeValid(string S) {
		int leftcount = 0;
		int res = 0;

		for (auto& iis : S)
		{
			if (iis == ')')
			{
				if (leftcount == 0) res++;
				else leftcount--;
			}
			else leftcount++;
		}
		res += leftcount;
		return res;
	}
};
