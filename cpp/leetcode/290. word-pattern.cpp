#include "public.h"

//4ms, 92.76%
//����unordered_map�洢�໥��Ӧ��ϵ, һ��ͬʱ����pattern��str, һ�߸�������map�����ж�

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int pl = 0;
		int sl = 0;
		unordered_map<char, string> um;
		unordered_map<string, char> umr;
		while ((pl < pattern.size()) && (sl < str.size()))
		{
			int len = 0;
			char ch = pattern[pl];
			while (((sl + len) < str.size()) && (str[sl + len] != ' ')) ++len;
			string pres = str.substr(sl, len);
			if (um.find(ch) == um.end()) um[ch] = pres;
			else if (um[ch] == pres);
			else return false;
			if (umr.find(pres) == umr.end()) umr[pres] = ch;
			else if (umr[pres] == ch);
			else return false;
			sl = sl + len + 1;
			pl++;
		}
		if ((pl == pattern.size()) && (sl == str.size() + 1)) return true;
		else return false;

	}
};
