#include "public.h"

//12ms, 93.14%

//��������ô˼�����ӵ�:���ҳ���̵��ַ���
//Ȼ����ֲ��ұȽ�: �ȱȽ�ǰһ���,���������,�ȽϺ�һ���е�ǰһ��,����Ƚ�ǰһ���е�ǰһ��
//����ʵ����Ҳ�����ظ��Ƚ�,(����)�������������O(logn)��ʱ�临�Ӷ�

//�Ҳ鿴�������Լ���ʱ�͵��㷨,����:1��ֱ�ӱ������� 
//2���������:���ǵ���������:һ���ַ�������ӵ�й����ַ���ǰ׺+�Լ����ַ�����,
//  ��ô�����ַ�������С�ַ����Ĺ����ַ���ǰ׺һ�������е��ַ���ǰ׺:
//  ����:ɾ�������ַ���ǰ׺֮��,����ַ�������С�ַ����ĵ�һ����ĸһ��ӵ�м���Ĳ��,���������ͬ��ô���д�С
//  ��������ַ�������С�ַ������ַ���Ҳӵ����ͬ�ĵ�һ����ĸ,����ɾ�������ַ���ǰ׺ì��
//  ��������������ŵ��Ǽ��󽵵��˴��볤��

class Solution {
private:
	string max_element_m(vector<string>& strs)
	{
		string res = strs[0];
		for (int i = 1; i < strs.size(); i++)
			res = (res < strs[i]) ? strs[i] : res;
		return res;
	}

	string min_element_m(vector<string>& strs)
	{
		string res = strs[0];
		for (int i = 1; i < strs.size(); i++)
			res = (res > strs[i]) ? strs[i] : res;
		return res;
	}

	string mismatch_m(string s1, string s2)
	{
		int smallsize = min(s1.size(), s2.size());
		int loc = 0;
		while ((loc < smallsize) && (s1[loc] == s2[loc])) ++loc;
		return s1.substr(0, loc);
	}

public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		string maxstr = max_element_m(strs);
		string minstr = min_element_m(strs);
		return mismatch_m(maxstr, minstr);

		//�Ҳ�֪�����FUCK C++��mismatch�����Ǹ�ɶ��
		//����:mismatch(Ԫ��1��ʼָ��,Ԫ��1����ָ��,Ԫ��2��ʼָ��) ����Ԫ��1����Ӧ��<=Ԫ��2,�������ҵ�VS2017���汨��?!
		// �ĸ�bitch��Ƶ�
		//�⵼�����޷�ʹ�ÿ�,FUCCCCCCKKKK
		/*
		auto maxstr = max_element(strs.begin(), strs.end());
		auto minstr = min_element(strs.begin(), strs.end());
		auto misloc = mismatch(maxstr->begin(), maxstr->end(), minstr->begin());
		return string(maxstr->begin(), misloc.first);
		*/
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> strs = { "flower", "flop" };
	string res = s->longestCommonPrefix(strs);
	delete s;
	return 0;
}
