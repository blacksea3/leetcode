#include "public.h"

//8ms, 53.44%
//ģ��

class Solution {
public:
	string toGoatLatin(string S) {
		//�ж�ÿ������, Ȼ�󰤸�����
		int index = 1;
		int startloc = 0;
		string res = "";
		while (startloc < S.size())
		{
			int temploc = startloc;
			//ͻ����ѯ
			while (temploc < S.size() && S[temploc] != ' ') temploc++;
			//��ȡȻ�����
			string tempstr = S.substr(startloc, temploc - startloc);
			if (tempstr[0] == 'a' || tempstr[0] == 'e' || tempstr[0] == 'i' || tempstr[0] == 'o' || tempstr[0] == 'u' ||
				tempstr[0] == 'A' || tempstr[0] == 'E' || tempstr[0] == 'I' || tempstr[0] == 'O' || tempstr[0] == 'U')
				tempstr += "ma";
			else
			{
				tempstr.push_back(tempstr[0]);
				tempstr.erase(tempstr.begin());
				tempstr += "ma";
			}
			for (int i = 1; i <= index; ++i) tempstr.push_back('a');
			res += tempstr;
			res.push_back(' ');
			index++;
			startloc = temploc + 1;
		}
		//ȥ��ĩβ�ո�
		res.pop_back();
		return res;
	}
};
