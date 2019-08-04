#include "public.h"

//4ms, 77.36%
//��չ��������η���, ����ֻ��Ҫ�����һ���ܹ�����ĵ�����: x%p==0, y%p==0, x=ap, y=aq;
//a��ʵ����q��p����С������

class Solution {
private:
	//շת���
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
