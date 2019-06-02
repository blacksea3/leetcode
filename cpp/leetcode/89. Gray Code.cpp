#include "public.h"

//4ms, 99.54%

//use iteration
// note that the graycode of n can be duplicated useing graycode of n-1

class Solution {
public:
	vector<int> grayCode(int n) {
		//special input
		if (n == 0) return vector<int> {0};
		if (n == 1) return vector<int> {0, 1};

		vector<int> pre = { 0,1 };
		vector<int> next;

		for (int i = 2; i <= n; i++)
		{
			next.clear();
			next.resize(pre.size() * 2);
			for (int j = 0; j < pre.size(); j++)
				next[j] = pre[j];
			int abs = 1 << (i - 1);
			for (int j = pre.size(); j < 2 * pre.size(); j++)
				next[j] = pre[2 * pre.size() - j - 1] + abs;
			swap(pre, next);
		}
		return pre;
	}
};