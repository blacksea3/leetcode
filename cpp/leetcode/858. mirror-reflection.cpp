#include "public.h"

//4ms, 77.36%
//扩展这个正方形房间, 现在只需要求出第一个能够到达的点满足: x%p==0, y%p==0, x=ap, y=aq;
//a其实就是q和p的最小公倍数

class Solution {
private:
	//辗转相除
	int gcd(int x, int y)
	{
		if (!y)
			return x;
		else
			return gcd(y, x%y);
	}

public:
	int mirrorReflection(int p, int q) {
		int gc = gcd(p, q);
		int a = p / gc;

		if (a % 2 == 0) return 2;
		else
		{
			int y = a * q;
			if ((y / p) % 2 != 0) return 1;
			else return 0;
		}
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->mirrorReflection(3, 1);
	return 0;
}
