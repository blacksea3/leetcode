#include "public.h"

//������hashmap, 16ms, 71.80%

/*
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		//ά������ת����Ϳ���
		unordered_map<char, char> um;
		unordered_map<char, char> um_r;

		if (s.size() != t.size()) return false;
		for (int i = 0; i < s.size(); i++)
		{
			if (um.find(s[i]) == um.end())
			{
				if (um_r.find(t[i]) == um_r.end())
				{
					um[s[i]] = t[i];
					um_r[t[i]] = s[i];
				}
				else
				{
					return false;
				}
			}
			else if (um_r.find(t[i]) == um_r.end())
				return false;
			else
			{
				//ע����ӳ������
				if ((s[i] == t[i]) && (um[s[i]] != s[i])) return false;
				else if ((s[i] != t[i]) && (um[s[i]] == s[i])) return false;
				else continue;
			}
		}
		return true;
	}
};*/

//16ms, 71.80%
//����ʹ������˼·: �ж���ͬ�ַ�����ͬλ�þͺ��ˡ�
//�����˼��:����s��t, ��ͬ�ַ����״γ���λ��һ����һ�µ�!

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s.find(s[i]) != t.find(t[i]))
				return false;
		}
		return true;
	}
};
