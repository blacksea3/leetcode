#include "public.h"

//12ms, 91.70%
//¶ş·Ö²éÕÒ

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		vector<char>::iterator iter = upper_bound(letters.begin(), letters.end(), target);

		if (iter == letters.end()) return letters[0];
		else return *iter;
	}
};
