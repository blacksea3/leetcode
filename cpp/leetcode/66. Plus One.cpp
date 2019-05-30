#include "public.h"

//4ms, 98.06%

//simple algorithm, use isCarry to record whether now need a carry
//note digits.size() will always > 0 as the problem say

//an amazing algorithm is that we can operate on digits itself!

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//traverse reversely
		bool isCarry = true;
		vector<int> res = {};

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i]++;
			if (digits[i] == 10) digits[i] = 0;
			else return digits;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};