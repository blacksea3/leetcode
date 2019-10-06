#include "public.h"

//
//dp×´Ì¬ÍÆµ¼
//

class Solution {
public:
	int countVowelPermutation(int n) {
		long long a, e, i, o, u;
		a = 1;
		e = 1;
		i = 1;
		o = 1;
		u = 1;
		long long MOD = 1000000007;

		for (int time = 1; time < n; ++time)
		{
			long long ta, te, ti, to, tu;
			ta = e + i + u;
			te = a + i;
			ti = e + o;
			to = i;
			tu = i + o;

			ta %= MOD;
			te %= MOD;
			ti %= MOD;
			to %= MOD;
			tu %= MOD;

			a = ta;
			e = te;
			i = ti;
			o = to;
			u = tu;
		}

		long long res = a + e + i + o + u;
		res %= MOD;
		return res;
	}
};

/*
int main()
{
	Solution * s = new Solution();
	cout << s->countVowelPermutation(2) << endl;
	cout << s->countVowelPermutation(5) << endl;
	return 0;
}
*/
