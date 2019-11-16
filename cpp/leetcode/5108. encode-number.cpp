#include "public.h"

//数学题

class Solution {
public:
	string encode(int num) {
		int stlen = log(num + 1) / log(2);

		int remain = num - (pow(2, stlen) - 1);

		//求remain的stlen位二进制表示

		string res;
		for (int i = 0; i < stlen; ++i)
		{
			res += "0";
		}

		int precount = 0;
		while (remain > 0)
		{
			if (remain % 2)
			{
				res[precount] = '1';
			}
			remain /= 2;
			precount++;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->encode(0) << endl;
	cout << s->encode(2) << endl;
	cout << s->encode(6) << endl;
	cout << s->encode(23) << endl;
	cout << s->encode(107) << endl;
}
*/
