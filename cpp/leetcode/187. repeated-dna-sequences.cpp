#include "public.h"

//位运算，类似滑动窗口操作, 12ms, 99.79%
//优化操作:将ACGT分别转成0123,那么仅仅需要一个20bit的序列来储存一个10字符长度的DNA
//然后用bitset保存, bitset<1 << 20> S, 如果某个位为1表示这个20bit序列已经出现过, 这个相当于map功能

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