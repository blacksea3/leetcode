#include "public.h"

//8ms, 95.18%

//I think there only exists brute force algorithm to solve this problem

class Solution {
public:
	string countAndSay(int n) {
		//need an iteration
		string laststr = "1";
		for (int i = 1; i < n; i++)
		{
			string prestr = "";
			char oldchar = laststr[0];
			int charnums = 0;
			for (auto prech:laststr)
			{
				if (prech != oldchar)
				{
					string s1 = "";
					s1 += oldchar;
					prestr += to_string(charnums) + s1;
					oldchar = prech;
					charnums = 1;
				}
				else charnums++;
			}
			string s1;
			s1 += oldchar;
			prestr += to_string(charnums) + s1;
			laststr = prestr;
		}
		return laststr;
	}
};
