#include "public.h"

//12ms, 82.97%
//Í³¼Æ´ÊÆµ

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
					string s = to_string(oldlen);
					for (auto& is:s)
					{
						chars[writeloc] = is;
						oldlen /= 10;
						writeloc++;
					}
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
			chars[writeloc] = oldchar;
			writeloc++;
		}
		else
		{
			chars[writeloc] = oldchar;
			writeloc++;
			string s = to_string(oldlen);
			for (auto& is : s)
			{
				chars[writeloc] = is;
				oldlen /= 10;
				writeloc++;
			}
		}
		return writeloc;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<char> v = { 'a', 'a', 'a', 'a', 'a', 'b'};
	auto res = s->compress(v);
	return 0;
}
*/
