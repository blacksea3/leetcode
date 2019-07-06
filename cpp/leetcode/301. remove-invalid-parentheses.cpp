#include "public.h"

//20ms, 46.26%
//先统计最少需要去掉的左括号和右括号, 然后递归回溯

class Solution {
private:
	unordered_set<string> res;
	void recurse(const string& s, int index, int left_count, int right_count,
		int left_rem, int right_rem, string expr)
	{
		if (index == s.size())
		{
			if (left_rem == 0 && right_rem == 0)
				res.insert(expr);
		}
		else
		{
			//直接丢弃当前的括号, 向内递归
			if ((s[index] == '(' && left_rem > 0) || (s[index] == ')' && right_rem > 0))
			{
				recurse(s, index + 1, left_count, right_count, left_rem - (s[index] == '('),
					right_rem - (s[index] == ')'), expr);
			}

			//记录当前内容
			expr.push_back(s[index]);
			//考虑当前的括号, 向内递归
			if (s[index] != '(' && s[index] != ')')
			{
				recurse(s, index + 1, left_count, right_count, left_rem, right_rem,
					expr);
			}
			else if (s[index] == '(')
			{
				recurse(s, index + 1, left_count + 1, right_count, left_rem, right_rem,
					expr);
			}
			//加右括号需满足当前左括号数量大于右括号
			else if (s[index] == ')' && left_count > right_count)
			{
				recurse(s, index + 1, left_count, right_count + 1, left_rem
					, right_rem, expr);
			}
			expr.pop_back();
		}
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		int left = 0;
		int right = 0;
		for (const auto& iis : s)
			if (iis == '(') left++;
			else if (iis == ')')
				if (left == 0) right++;
				else left--;

		recurse(s, 0, 0, 0, left, right, "");
		vector<string> returnres(res.begin(), res.end());
		return returnres;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> res = s->removeInvalidParentheses("(a)())()");
	return 0;
}
*/
