#include "public.h"

//28ms, 83.56%
//用20位二进制表示是否当前组合被选取过

class Solution {
private:
	bitset<1 << 20> used, val;

	bool DFS(int maxChoosableInteger, int target, int mask)
	{
		if (used[mask]) return val[mask];
		else
		{
			for (int i = maxChoosableInteger; i >= 1; --i)
			{
				int cur = (1 << (i - 1));
				if ((mask & cur) == 0)
					if (i >= target || !DFS(maxChoosableInteger, target - i, mask | cur))
					{
						used[mask] = 1;
						val[mask] = 1;
						return true;
					}
			}
		}
		used[mask] = 1;
		val[mask] = 0;
		return false;
	}

public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger*(maxChoosableInteger + 1) / 2 < desiredTotal) return false;
		if (maxChoosableInteger > desiredTotal) return true;
		return DFS(maxChoosableInteger, desiredTotal, 0);
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->canIWin(10, 11);
	return 0;
}
