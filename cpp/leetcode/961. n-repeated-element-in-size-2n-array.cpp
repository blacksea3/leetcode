#include "public.h"

//
//simple solution

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		//就是返回重复的那个数字
		unordered_set<int> us;
		for (auto& a : A)
		{
			if (us.find(a) != us.end()) return a;
			else us.insert(a);
		}
		return -999; //dump
	}
};
