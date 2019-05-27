#include "public.h"

//8ms, 93.92%

//use an unordered_map to store infos of s

class Solution {
public:
	char findTheDifference(string s, string t) {
		unordered_map<char, int> um;
		for (auto iis : s) um[iis]++;

		for (auto iit : t)
		{
			if (um[iit] > 0) um[iit]--;
			else return iit;
		}
		return '.'; //dump
	}
};
