#include "public.h"

//0ms, 100%
//����unordered_map�洢�໥��Ӧ��ϵ, һ��ͬʱ����pattern��str, һ�߸�������map�����ж�

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int pl = 0;
		int sl = 0;
		int pSize = pattern.size();
		int sSize = str.size();
		unordered_map<char, string> um;
		unordered_map<string, char> umr;
		while ((pl < pSize) && (sl < sSize))
		{
			int len = 0;
			char ch = pattern[pl];
			while (((sl + len) < str.size()) && (str[sl + len] != ' ')) ++len;
			string pres = str.substr(sl, len);

			if (um.find(ch) == um.end()) um[ch] = pres;
			else if (um[ch] != pres) return false;
			if (umr.find(pres) == umr.end()) umr[pres] = ch;
			else if (umr[pres] != ch) return false;

			sl = sl + len + 1;
			pl++;
		}
		if ((pl == pSize) && (sl == sSize + 1)) return true;
		else return false;
	}
};
