#include "public.h"

//16ms, 90.71%
//Ä£Äâ

class Solution {
public:
	bool judgeCircle(string moves) {
		int linePre = 0;
		int colPre = 0;

		for (auto& move : moves)
		{
			switch (move)
			{
			case 'R':
			{
				colPre++;
				break;
			}
			case 'L':
			{
				colPre--;
				break;
			}
			case 'U':
			{
				linePre++;
				break;
			}
			case 'D':
			{
				linePre--;
				break;
			}
			default:
			{
				break;
			}
			}
		}
		return (linePre == 0) && (colPre == 0);
	}
};
