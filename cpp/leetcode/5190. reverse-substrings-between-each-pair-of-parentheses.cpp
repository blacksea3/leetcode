#include "public.h"

//
//�ݹ�

class Solution {
private:
	//���������и�����
	//startloc�Ѿ�����������(������loc+1)
	//�����ڲ��ַ����Ͷ�Ӧ������loc+1
	pair<string, int> recu(string s, int startloc)
	{
		string res = "";
		int loc = startloc;
		while (loc < s.size())
		{
			if (s[loc] == '(')
			{
				pair<string, int> temp = recu(s, loc + 1);
				res += temp.first;
				loc = temp.second;
			}
			else if (s[loc] == ')')
			{
				reverse(res.begin(), res.end());
				return pair<string, int>{res, loc + 1};
			}
			else
			{
				res.push_back(s[loc]);
				loc++;
			}
		}
		//�����ϲ��ᵽ����
		return pair<string, int>{"!!!", -1};
	}

public:
	string reverseParentheses(string s) {
		string res = "";
		int loc = 0;
		while (loc < s.size())
		{
			if (s[loc] != '(')
			{
				res.push_back(s[loc]);
				loc++;
			}
			else
			{
				pair<string, int> temp = recu(s, loc + 1);
				res += temp.first;
				loc = temp.second;
			}
		}
		return res;
	}
};
