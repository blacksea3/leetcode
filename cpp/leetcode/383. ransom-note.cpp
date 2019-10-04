#include "public.h"

//20ms, 91.18%
//hash(实际用数组代替), 统计字符出现次数

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> v(256, 0);
		for (auto& m : magazine) v[m]++;

		for (auto& r : ransomNote)
		{
			if (v[r] > 0) v[r]--;
			else return false;
		}
		return true;
	}
};
