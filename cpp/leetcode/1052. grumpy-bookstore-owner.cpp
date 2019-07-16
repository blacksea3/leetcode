#include "public.h"

//72ms, 36.26%
//滑动窗口, 用长度为X的滑动窗口盖住一段使得grumpy = 0, 暴力, 每个位置都求一下顾客满意数量

class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		//silder window

		//sum all satisfied customer (if X == 0)

		int res = 0;
		for (int i = 0; i < customers.size(); i++)
			if (grumpy[i] == 0) res += customers[i];

		//init silder window
		int startloc = 0;
		int maxaddcus = 0;
		int preaddcus = 0;
		int endloc = startloc + X - 1;

		for (int i = 0; i <= endloc; i++)
			if (grumpy[i] == 1) preaddcus += customers[i];
		maxaddcus = preaddcus;

		//main silder window
		while (endloc < customers.size() - 1)
		{
			int abscus = 0;
			if (grumpy[startloc] == 1) abscus -= customers[startloc];
			if (grumpy[endloc + 1] == 1) abscus += customers[endloc + 1];
			preaddcus += abscus;
			maxaddcus = max(maxaddcus, preaddcus);
			startloc++;
			endloc++;
		}

		return res + maxaddcus;
	}
};
