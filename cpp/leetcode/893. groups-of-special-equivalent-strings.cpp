#include "public.h"

//36ms, 22.81%
//���ַ������������Ĵ���: ������λ��ż��λ�ĸ����ַ�����, ת��Ϊһ������ֵ, ��Ϊ��Ƿ���set
//���set�ĳ���

class Solution {
private:
	string convert(const string& s)
	{
		//����λ
		vector<int> odd(26, 0);
		vector<int> even(26, 0);

		for (int i = 0; i < s.size(); i += 2)
		{
			odd[s[i] - 'a']++;
		}
		for (int i = 1; i < s.size(); i += 2)
		{
			even[s[i] - 'a']++;
		}

		string res;

		for (int i = 0; i < 26; ++i)
		{
			if (odd[i] > 0)
			{
				res += to_string(odd[i]);
				res.push_back(i + 'a');
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if (even[i] > 0)
			{
				res += to_string(even[i]);
				res.push_back(i + 'a');
			}
		}
		return res;
	}


public:
	int numSpecialEquivGroups(vector<string>& A) {
		set<string> s;
		for (auto& a : A)
		{
			s.insert(convert(a));
		}
		return s.size();
	}
};
