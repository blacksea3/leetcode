#include "public.h"

//0ms, 100%
//������ַ���һ���Ǿ���-1, �����ǳ����ַ����ĳ���

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) return -1;
		else return max(a.size(), b.size());
	}
};
