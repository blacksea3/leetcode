#include "public.h"

//12ms, 94.25%
//simple solution
//考虑到题目说仅仅包好小写字母, 所以可以使用数组, 如果有unicode再用哈希表

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())  return false;

		array<int, 256> arrays{ 0 };
		array<int, 256> arrayt{ 0 };

		for (auto cs : s) arrays[cs]++;
		for (auto ct : t) arrayt[ct]++;

		for (char i = 'a'; i <= 'z'; ++i)
			if (arrays[i] != arrayt[i]) return false;

		return true;
	}
};
