#include "public.h"

//0ms, 100%

class Solution {
public:
	bool isRobotBounded(string instructions) {
		//������ǻص�ԭ����ô
		//ֻҪ�������ָ�򱱾���
		int dir = 0; //0�� 1�� 2�� 3��
		int x = 0;
		int y = 0;

		for (auto i : instructions)
		{
			if (i == 'G')
			{
				switch (dir)
				{
				case 0:
				{
					y += 1;
					break;
				}
				case 1:
				{
					x += 1;
					break;
				}
				case 2:
				{
					y -= 1;
					break;
				}
				case 3:
				{
					x -= 1;
					break;
				}
				}
			}
			else if (i == 'L')
			{
				dir = (dir == 0) ? 3 : dir - 1;
			}
			else
			{
				dir = (dir == 3) ? 0 : dir + 1;
			}
		}

		if ((x == 0) && (y == 0)) return true;
		else return (dir != 0);

	}
};

