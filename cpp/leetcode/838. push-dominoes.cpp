#include "public.h"

//20ms, 98.95%
//对每一组RL对, 判断其长度, 然后向中间延申, O(2n)
//状态机

class Solution {
public:
	string pushDominoes(string dominoes) {
		bool waitR = true;

		int loc = 0;
		int lastL = -1;
		int lastR = -999; //dump

		while (loc < dominoes.size())
		{
			if (waitR)
			{
				if (dominoes[loc] == 'R')
				{
					waitR = false;
					lastR = loc;
				}
				else if (dominoes[loc] == '.')
				{
					;
				}
				else
				{
					//填充L
					for (int j = lastL + 1; j < loc; ++j)
					{
						dominoes[j] = 'L';
					}
					lastL = loc;
				}
			}
			else
			{
				if (dominoes[loc] == 'R')
				{
					//填充R
					for (int j = lastR + 1; j < loc; ++j)
					{
						dominoes[j] = 'R';
					}
					lastR = loc;
				}
				else if (dominoes[loc] == '.')
				{
					;
				}
				else
				{
					//填充R-L
					for (int lef = lastR + 1, rig = loc - 1; lef < rig; ++lef, --rig)
					{
						dominoes[lef] = 'R';
						dominoes[rig] = 'L';
					}
					lastL = loc;
					waitR = true;
				}
			}
			loc++;
		}

		if (!waitR)
		{
			for (int j = lastR + 1; j < dominoes.size(); ++j)
			{
				dominoes[j] = 'R';
			}
		}
		return dominoes;
	}
};
