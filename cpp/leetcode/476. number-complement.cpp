#include "public.h"

//4ms, 74.72%
//用全是1的数字减这个num

class Solution {
public:
	int findComplement(int num) {
		int counttotalbits = 0;
		int cpnum = num;

		while (num > 0)
		{
			counttotalbits++;
			num /= 2;
		}

		if (counttotalbits == 31) return INT_MAX - cpnum;
		else return (int)pow(2, counttotalbits) - cpnum - 1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->findComplement(5) << endl;
	cout << s->findComplement(3) << endl;
	cout << s->findComplement(10) << endl;
	return 0;
}
*/
