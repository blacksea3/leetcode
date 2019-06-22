#include "public.h"

//λ���㣬���ƻ������ڲ���, 12ms, 99.79%
//�Ż�����:��ACGT�ֱ�ת��0123,��ô������Ҫһ��20bit������������һ��10�ַ����ȵ�DNA
//Ȼ����bitset����, bitset<1 << 20> S, ���ĳ��λΪ1��ʾ���20bit�����Ѿ����ֹ�, ����൱��map����

class Solution {
public:
	int returnChar(char c) {
		switch (c) {
		case 'A':
			return 0;

		case 'C':
			return 1;

		case 'G':
			return 2;

		case 'T':
			return 3;

		}
		return 0;
	}
	vector<string> findRepeatedDnaSequences(string s) {
		int n = s.length();
		vector<string> res;
		if (n <= 10) return res;
		bitset<1 << 20>S1;
		bitset<1 << 20>S2;
		int val = 0;
		for (int i = 0; i < 10; ++i)
			val = (val << 2) | returnChar(s[i]);
		S1.set(val);
		int mask = (1 << 20) - 1;
		for (int i = 10; i < n; ++i) {
			val = ((val << 2)&mask) | returnChar(s[i]);
			if (S2[val])
				continue;
			if (S1[val]) {
				res.push_back(s.substr(i - 9, 10));
				S2.set(val);
			}
			else {
				S1.set(val);
			}
		}

		return res;
	}
};