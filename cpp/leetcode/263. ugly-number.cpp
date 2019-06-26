#include "public.h"

//0ms, 100%
//simple solution

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;

		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		return (num == 1);
	}
};
