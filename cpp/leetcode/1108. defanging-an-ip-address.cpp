#include "public.h"

//0ms, 100%
//simple solution

class Solution {
public:
	string defangIPaddr(string address) {
		int asize = address.size();

		for (int i = 0; i < asize; ++i)
		{
			if (address[i] == '.')
			{
				address.insert(address.begin() + i, '[');
				address.insert(address.begin() + i + 2, ']');
				i += 2;
				asize += 2;
			}
		}
		return address;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->defangIPaddr("1.1.1.1");
	return 0;
}
*/