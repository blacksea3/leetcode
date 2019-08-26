#include "public.h"

//24ms, 57.76%
//Ä£Äâ

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		unordered_map<int, int> um;

		for (auto& b : bills)
		{
			if (b == 5) um[5]++;
			else if (b == 10)
			{
				if (um[5] > 0)
				{
					um[5]--;
					um[10]++;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (um[10] > 0)
				{
					if (um[5] > 0)
					{
						um[10]--;
						um[5]--;
					}
					else return false;
				}
				else
				{
					if (um[5] > 3) um[5] -= 3;
					else return false;
				}
			}
		}
		return true;
	}
};
