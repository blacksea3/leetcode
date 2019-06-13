#include "public.h"

//8ms, 96.90%

//set three number to store the biggest 3 nums!
//note: problem say nums.empty() == false!

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int bigbig = INT_MIN;
		int bigmedium = INT_MIN;
		int bigsmall = INT_MIN;

		int valid_big_nums = 0;

		for (auto num : nums)
		{
			switch(valid_big_nums)
			{
			case 0:
			{
				bigbig = num;
				valid_big_nums++;
				break;
			}
			case 1:
			{
				if (num != bigbig)
				{
					if (num > bigbig)
					{
						bigmedium = bigbig;
						bigbig = num;
					}
					else
					{
						bigmedium = num;
					}
					valid_big_nums++;
				}
				break;
			}
			case 2:
			{
				if (num > bigbig)
				{
					bigsmall = bigmedium;
					bigmedium = bigbig;
					bigbig = num;
					valid_big_nums++;
				}
				else if (num == bigbig)
				{
					;
				}
				else
				{
					if (num > bigmedium)
					{
						bigsmall = bigmedium;
						bigmedium = num;
						valid_big_nums++;
					}
					else if (num == bigmedium)
					{
						;
					}
					else
					{
						bigsmall = num;
						valid_big_nums++;
					}
				}
				break;
			}
			case 3:
			{
				if (num > bigbig)
				{
					bigsmall = bigmedium;
					bigmedium = bigbig;
					bigbig = num;
				}
				else if (num == bigbig)
				{
					;
				}
				else
				{
					if (num > bigmedium)
					{
						bigsmall = bigmedium;
						bigmedium = num;
					}
					else if (num == bigmedium)
					{
						;
					}
					else
					{
						if (num > bigsmall)
						{
							bigsmall = num;
						}
					}
				}
				break;
			}
			default:
				break;
			}
		}
		if (valid_big_nums == 3) return bigsmall;
		else return bigbig;
	}
};