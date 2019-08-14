#include "public.h"

//8ms, 44.48%
//Ä£Äâ

class Solution {
public:
	bool checkRecord(string s) {
		bool isabsent = false;
		bool islate = false;
		bool islateagain = false;

		for (auto& iis : s)
		{
			if (iis == 'A')
			{
				if (!isabsent) isabsent = true;
				else return false;
				islate = false;
			}
			else if (iis == 'L')
			{
				if (!islate)
				{
					islate = true;
					islateagain = false;
				}
				else
				{
					if (islateagain) return false;
					else islateagain = true;
				}
			}
			else
			{
				islate = false;
			}
		}
		return true;
	}
};
