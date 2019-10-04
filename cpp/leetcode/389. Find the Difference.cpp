#include "public.h"

//4ms, 91.72%
//hashͳ�Ƴ��ִ���(ʵ������vector��)

class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> v(256, 0);
		for (auto& iis : s) v[iis]++;

		for (auto& iit : t)
		{
			if (v[iit] > 0) v[iit]--;
			else return iit;
		}
		return '.'; //dump
	}
};
