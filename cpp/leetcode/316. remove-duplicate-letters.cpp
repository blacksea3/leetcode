#include "public.h"

//8ms, 85.43%
//ά��һ��vector
//���vector�в����ڵ�ǰֵ, �����vector��������ֵ, ��ǰֵС��vectorĩβֵ, ��vectorĩβֵ���ַ���֮�󻹴���, ��ȥ��vectorĩβֵ, Ȼ���ٴ���ͬloc�ж�;  ֱ��while�ж��˳�, ��ǰloc+1
//���vector�д��ڵ�ǰֵ, ��ǰloc+1

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<char> res;

		//�Ȼ�ȡÿ���ַ���s�е������ֵ�λ��
		vector<int> lastindex(26, -1);
		for (int i = s.size() - 1; i >= 0; --i)
			if (lastindex[s[i] - 'a'] == -1) lastindex[s[i] - 'a'] = i;

		for (int loc = 0; loc < s.size(); ++loc)
		{
			if (find(res.begin(), res.end(), s[loc]) != res.end()) continue;
			else
			{
				while (!res.empty() && res[res.size() - 1] > s[loc] && loc < lastindex[res[res.size() - 1] - 'a'])
					res.pop_back();
			}
			res.push_back(s[loc]);
		}
		string sres = "";
		for (int i = 0; i < res.size(); ++i)
			sres += res[i];
		return sres;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->removeDuplicateLetters("bcabc");
	return 0;
}
