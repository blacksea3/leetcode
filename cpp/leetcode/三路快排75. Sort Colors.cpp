#include "public.h"

//4ms, 98.37%

//ÈýÂ·¿ìÅÅ(three way quick sort)
//the problem say that YOU should use a one-pass algorithm using only constant space

//then the idea will be:  first, record the already (int)0 loc+1 and the already (int)2 loc-1
//  Then you can traverse one time, when find 1, pass(this means add preloc);
//  when find 0, swap it with the already (int)0 loc+1(here don't need to move preloc)
//  when find 2, swap it with the already (int)2 loc-1(here don't need to move preloc)

// the traverse should be a while loop

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) return;

		int number_0loc = 0;   //next 0 loc
		int number_2loc = nsize - 1;  //next 2 loc

		int loc = 0;
		while (loc <= number_2loc)
		{
			while (nums[loc] != 1)
			{
				if (nums[loc] == 0)
					if (loc != number_0loc)
					{
						int temp = nums[number_0loc];
						nums[number_0loc] = 0;
						nums[loc] = temp;
						number_0loc++;
					}
					else break;
				else
				{
					if (loc != number_2loc)
					{
						int temp = nums[number_2loc];
						nums[number_2loc] = 2;
						nums[loc] = temp;
						number_2loc--;
					}
					else break;
				}
			}
			loc++;
		}
	}
};
