#include "public.h"

//4ms, 77.09%
//±©Á¦

class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size()) return false;
		if (A == "" && B == "") return true;

		for (int i = 0; i < A.size(); ++i)
		{
			if (A == (B.substr(i) + B.substr(0, i))) return true;
		}
		return false;
	}
};
