#include "public.h"

//8ms, 37.76%
//递归

class Solution {
private:
	pair<int, int> recu(string S, int start)
	{
		int prescore = 0;
		int preloc = start;
		bool hasinner = false;
		//读取到)或者末尾算作结束
		while (true)
		{
			if (S[preloc] == '(')
			{
				pair<int, int> temp = recu(S, preloc + 1);
				prescore += temp.first;
				preloc = temp.second;
				hasinner = true;
			}
			else
			{
				if (!hasinner) return { 1, preloc + 1 };
				else return { 2*prescore, preloc + 1 };
			}
		}
		return { -1,-1 }; //dump
	}

public:
	int scoreOfParentheses(string S) {
		int prescore = 0;
		int preloc = 0;
		//读取到)或者末尾算作结束
		while (preloc < S.size())
		{
			pair<int, int> temp = recu(S, preloc + 1);
			prescore += temp.first;
			preloc = temp.second;
		}
		return prescore;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->scoreOfParentheses("()()");
	cout << s->scoreOfParentheses("(()(())");
	cout << s->scoreOfParentheses("()");
	return 0;
}
*/
