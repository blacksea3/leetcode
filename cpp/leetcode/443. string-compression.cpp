#include "public.h"

//16ms, 61.64%
//Ä£Äâ

class Solution {
public:
	int compress(vector<char>& chars) {
		char oldchar = chars[0];
		int oldlen = 1;
		int writeloc = 0;

		for (int loc = 1; loc < chars.size(); ++loc)
		{
			if (chars[loc] != oldchar)
			{
				if (oldlen == 1)
				{
					chars[writeloc] = oldchar;
					writeloc++;
				}
				else
				{
					chars[writeloc] = oldchar;
					writeloc++;
					vector<char> realnumchars;
					while (oldlen > 0)
					{
						realnumchars.insert(realnumchars.begin(), oldlen % 10);
						oldlen /= 10;
					}
					for (int preloc = writeloc; preloc < writeloc + realnumchars.size(); ++preloc)
					{
						chars[preloc] = realnumchars[preloc - writeloc] + '0';
					}
					writeloc += realnumchars.size();
				}
				oldchar = chars[loc];
				oldlen = 1;
			}
			else
			{
				oldlen++;
			}
		}

		if (oldlen == 1)
		{
			writeloc++;
		}
		else
		{
			writeloc++;
			vector<char> realnumchars;
			while (oldlen > 0)
			{
				realnumchars.insert(realnumchars.begin(), oldlen % 10);
				oldlen /= 10;
			}
			for (int preloc = writeloc; preloc < writeloc + realnumchars.size(); ++preloc)
			{
				chars[preloc] = realnumchars[preloc - writeloc] + '0';
			}
			writeloc += realnumchars.size();
		}

		return writeloc;
	}
};
