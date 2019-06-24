#include "public.h"

//状态机, 12ms, 97.54%

class Solution {
public:
	int calculate(string s) {
		//扫一遍s
		int preval_1 = 0;
		char presign = 0;          //0: +, 1: -, 2:*, 3:/
		int preval_2 = 0;
		int history_val = 0;
		bool history_sign = true;  //+: true, -:false

		for (auto& iis : s)
		{
			if (iis == ' ') continue;
			else if (isdigit(iis))
			{
				preval_2 = preval_2 * 10 + (iis - '0');
			}
			else if ((iis == '+') || (iis == '-'))
			{
				switch (presign)
				{
				case 0:
				{
					if (history_sign) history_val += preval_1;
					else history_val -= preval_1;
					history_sign = true;
					preval_1 = preval_2;
					preval_2 = 0;
					break;
				}
				case 1:
				{
					if (history_sign) history_val += preval_1;
					else history_val -= preval_1;
					history_sign = false;
					preval_1 = preval_2;
					preval_2 = 0;
					break;
				}
				case 2:
				{
					preval_1 *= preval_2;
					preval_2 = 0;
					break;
				}
				case 3:
				{
					preval_1 /= preval_2;
					preval_2 = 0;
					break;
				}
				default:
					break;
				}
				presign = (iis == '+') ? 0 : 1;
			}
			else
			{
				switch (presign)
				{
				case 0:
				{
					if (history_sign) history_val += preval_1;
					else history_val -= preval_1;
					history_sign = true;
					preval_1 = preval_2;
					preval_2 = 0;
					break;
				}
				case 1:
				{
					if (history_sign) history_val += preval_1;
					else history_val -= preval_1;
					history_sign = false;
					preval_1 = preval_2;
					preval_2 = 0;
					break;
				}
				case 2:
				{
					preval_1 *= preval_2;
					preval_2 = 0;
					break;
				}
				case 3:
				{
					preval_1 /= preval_2;
					preval_2 = 0;
					break;
				}
				default:
					break;
				}
				presign = (iis == '*') ? 2 : 3;
			}
		}

		//最后再算一遍
		switch (presign)
		{
		case 0:
		{
			if (history_sign) preval_1 += preval_2;
			else preval_1 -= preval_2;
			break;
		}
		case 1:
		{
			if (history_sign) preval_1 -= preval_2;
			else preval_1 += preval_2;
			break;
		}
		case 2:
		{
			preval_1 *= preval_2;
			break;
		}
		case 3:
		{
			preval_1 /= preval_2;
			break;
		}
		default:
			break;
		}
		if (history_sign) return history_val + preval_1;
		else return history_val - preval_1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->calculate("282-1*2*13-30-2*2*2/2-95/5*2+55+804+3024");
	cout << s->calculate("1-1+1");
	return 0;
}
*/