#include "public.h"

//20ms, 46.26%
//��ͳ��������Ҫȥ���������ź�������, Ȼ��ݹ����

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
			//ֱ�Ӷ�����ǰ������, ���ڵݹ�
			if ((s[index] == '(' && left_rem > 0) || (s[index] == ')' && right_rem > 0))
			{
				recurse(s, index + 1, left_count, right_count, left_rem - (s[index] == '('),
					right_rem - (s[index] == ')'), expr);
			}

			//��¼��ǰ����
			expr.push_back(s[index]);
			//���ǵ�ǰ������, ���ڵݹ�
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
			//�������������㵱ǰ��������������������
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
