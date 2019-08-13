#include "public.h"

//8ms, 41.28%
//É¨Ãè¾ÍÐÐÀ²

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool firstcapital = (word[0] <= 'Z' & word[0] >= 'A') ? true : false;

		bool isfind_nocapital = false;
		bool isfind_capital = false;

		for (int loc = 1; loc < word.size(); ++loc)
		{
			if (word[loc] <= 'Z' && word[loc] >= 'A') isfind_capital = true;
			else isfind_nocapital = true;
		}

		if (firstcapital)
			return (!isfind_nocapital || !isfind_capital);
		else
			return (!isfind_capital);
	}
};
