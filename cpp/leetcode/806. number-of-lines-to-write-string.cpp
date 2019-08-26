#include "public.h"

//8ms, 45.21%
//Ä£Äâ

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int oldline = 0;
		int oldwidth = 0;

		for (auto& iis : S)
		{
			if (oldwidth + widths[iis - 'a'] > 100)
			{
				oldline++;
				oldwidth = widths[iis - 'a'];
			}
			else oldwidth += widths[iis - 'a'];
		}

		return { oldline + 1, oldwidth };
	}
};
