#include "public.h"

//8ms, 31.25%
//tx, ty来回取模??

class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (sx <= tx && sy <= ty)
		{
			if (sx == tx && sy == ty) return true;
			else
			{
				if (tx > ty)
				{
					if ((tx%ty == sx%sy) && sy == ty) return true;
					else tx = tx % ty;
				}
				else
				{
					if ((ty%tx == sy%sx) && sx == tx) return true;
					else ty = ty % tx;
				}
			}
		}

		return false;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->reachingPoints(1, 1, 3, 5) << endl;
	cout << s->reachingPoints(1, 1, 2, 2) << endl;
	cout << s->reachingPoints(1, 1, 1, 1) << endl;
	return 0;
}
