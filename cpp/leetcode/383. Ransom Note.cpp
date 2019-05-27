#include "public.h"

//36ms, 71.48%

//use an unordered_map to store all chars in magezine, then traverse ransomNote,
// at the same time operate the unordered_map

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> um;
		for (auto m : magazine) um[m]++;

		for (auto r : ransomNote)
		{
			if (um[r] > 0) um[r]--;
			else return false;
		}
		return true;
	}
};
