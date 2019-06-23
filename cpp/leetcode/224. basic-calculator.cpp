#include "public.h"

//stack, 16ms, 93.63%

class Solution {
public:
	int calculate(string s) {
		stack<int> stnum;
		stack<bool> stsign;  //+: true, -: false

		int res = 0;
		int preval = 0;
		bool presign = true;
		bool lastis_sign = false;

		for (auto& iis : s)
		{
			if (iis == ' ') continue;
			else if (iis == '(')
			{
				stnum.push(res);
				stsign.push(presign);
				res = 0;
				presign = true;
			}
			else if (isdigit(iis))
			{
				preval = preval * 10 + (iis - '0');
				lastis_sign = false;
			}
			else if (iis == '+')
			{
				if (!lastis_sign)
				{
					if (presign) res += preval;
					else res -= preval;
					presign = true;
					preval = 0;
					lastis_sign = true;
				}
			}
			else if (iis == '-')
			{
				if (!lastis_sign)
				{
					if (presign) res += preval;
					else res -= preval;
					presign = false;
					preval = 0;
					lastis_sign = true;
				}
				else presign = !presign;
			}
			else
			{
				if (presign) res += preval;
				else res -= preval;
				presign = stsign.top();
				stsign.pop();
				if (presign) res = stnum.top() + res;
				else res = stnum.top() - res;
				stnum.pop();
				preval = 0;
				presign = false;
			}
		}
		if (presign) res += preval;
		else res -= preval;
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->calculate("(1+(4+5+2)-3)+(6+8)") << endl;
	cout << s->calculate("2147483647") << endl;
	return 0;
}
