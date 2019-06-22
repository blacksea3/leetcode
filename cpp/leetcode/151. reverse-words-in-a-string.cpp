#include "public.h"

//simple solution 12ms, 90.58%
//״̬��,�ֶ�ȡ��ĸ�Ͷ�ȡ�ո�

class Solution {
public:
	string reverseWords(string s) {
		int loc = s.size() - 1;
		int wordend = 0;

		bool iswording = false;   //true:��ǰ���ڶ�ȡ����

		string res = "";

		while (loc >= 0)
		{
			if (iswording)
			{
				if (s[loc] == ' ')
				{
					res += s.substr(loc + 1, wordend - loc);
					res += " ";
					iswording = false;
				}
			}
			else
			{
				if (s[loc] != ' ')
				{
					iswording = true;
					wordend = loc;
				}
			}
			loc--;
		}
		if (iswording)  //������һ������
			res += s.substr(0, wordend + 1);
		else  //ȥ��ĩβ�ո�
			res.pop_back();
		return res;
	}
};