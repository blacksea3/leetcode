#include "public.h"

//4ms, 70.91%
//Ä£Äâ

class Solution {
public:
	string toLowerCase(string str) {
		for (auto& iter_str : str)
		{
			if ('A' <= iter_str && iter_str <= 'Z')
			{
				iter_str = iter_str - 'A' + 'a';
			}
		}
		return str;
	}
};
