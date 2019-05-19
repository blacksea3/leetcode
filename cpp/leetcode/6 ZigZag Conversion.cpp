#include "public.h"

//20ms 97.21%

//�½�һ��vector������е��ַ���
//Ȼ�󰴹����ȡs����
//ע���е��ƶ�����:�ϻ�����
//ע���������:ֻ��һ��

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> group_s(numRows);
		bool downdir = true;
		int line = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			group_s[line] += s[i];
			if (line == 0) downdir = true;
			if (line == (numRows - 1)) downdir = false;

			if (downdir) ++line;
			else --line;
		}

		string returns;
		for (auto& str:group_s)
			returns += str;
		return returns;
	}
};

