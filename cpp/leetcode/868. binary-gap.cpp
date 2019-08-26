#include "public.h"

//4ms, 81.98%
//转二进制然后判断即可

class Solution {
public:
	int binaryGap(int N) {
		vector<int> b;
		while (N > 0)
		{
			b.push_back(N % 2);
			N /= 2;
		}

		int res = 0;
		int old = -1;

		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] == 1)
			{
				if (old == -1)
					old = i;
				else
				{
					res = max(res, i - old);
					old = i;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->binaryGap(22);
	return 0;
}
*/
