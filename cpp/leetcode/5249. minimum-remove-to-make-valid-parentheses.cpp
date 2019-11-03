#include "public.h"

//
//Ì°ÐÄ

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string newS = "";

		int left = 0;

		for (auto& iters : s)
		{
			if (iters == '(')
			{
				left++;
				newS.push_back(iters);
			}
			else if (iters == ')')
			{
				if (left > 0)
				{
					left--;
					newS.push_back(iters);
				}
				else continue;
			}
			else newS.push_back(iters);
		}

		string resS = "";
		int right = 0;

		for (int i = newS.size() - 1; i >= 0; --i)
		{
			char iters = newS[i];
			if (iters == '(')
			{
				if (right == 0) continue;
				else
				{
					right--;
					resS.push_back(iters);
				}
			}
			else if (iters == ')')
			{
				right++;
				resS.push_back(iters);
			}
			else resS.push_back(iters);
		}

		reverse(resS.begin(), resS.end());

		return resS;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->minRemoveToMakeValid("lee(t(c)o)de)") << endl;
	cout << s->minRemoveToMakeValid("a)b(c)d") << endl;
	cout << s->minRemoveToMakeValid("))((") << endl;
	cout << s->minRemoveToMakeValid("(a(b(c)d)") << endl;
	cout << s->minRemoveToMakeValid("())()(((") << endl;
	
	return 0;
}
*/
