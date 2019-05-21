#include "public.h"

//24ms, 97.29%

//һ��ѭ��
//��ͷ��ʼ�ж�,�����ǰֵ<��һ��ֵ˵���������
//���ǵ�:����IV�����������=V-I,��˿�����������ɽ�����д

class Solution {
public:
	int romanToInt(string s) {
		//��������Ϸ�
		unordered_map<char, int> um = { {'I',1}, {'V', 5}, {'X', 10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int returnres = 0;
		int i; //ѭ���õ�,��ѭ������Ҳ��Ҫ��
		for ( i = 0; i < s.size() - 1;)
		{
			if (um[s[i]] < um[s[i + 1]])
			{
				returnres += (um[s[i + 1]] - um[s[i]]);
				i += 2;
			}
			else
			{
				returnres += um[s[i]];
				++i;
			}
		}
		returnres += um[s[i]];
		return returnres;
	}
};
