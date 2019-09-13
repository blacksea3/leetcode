#include "public.h"

//4ms, 84.38%

//One traverse.
//DP problem: here an and an_ad1 are DP items

class Solution {
public:
	//problem ensure that s.size()>=1
	int numDecodings(string s) {
		//a(n) = a(n-1)(如果n-1字母不是0) + a(n-2)(如果n-1字母可以和n-2字母合并)
		//一旦a(n)=0, 立即返回0

		//a(n) = a(n-1)(if pre letter isn't '0') + a(n-2)(if old letter can combine with pre letter)
		//note that if one time a(n) == 0, just return 0

		//init and special input
		int slen = s.size();

		int an = (s[0] != '0') ? 1 : 0;
		int an_ad1 = 0;
		if (slen == 1) return an;
		if (an == 0) return 0;

		if (s[1] != '0')
		{
			if ((s[0] == '1') || ((s[0] == '2') && (s[1] <= '6'))) an_ad1 = 2;
			else an_ad1 = 1;
		}
		else
		{
			if ((s[0] != '2') && (s[0] != '1')) return 0;
			else an_ad1 = 1;
		}


		//main iterative loop
		for (int i = 2; i < slen; i++)
		{
			if (s[i] == '0')
			{
				if ((s[i - 1] != '2') && (s[i - 1] != '1')) return 0;
			}
			else
			{
				if ((s[i - 1] == '1') || ((s[i - 1] == '2') && (s[i] <= '6'))) an += an_ad1;
				else an = an_ad1;
			}
			swap(an, an_ad1);
		}

		return an_ad1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->numDecodings("8176");
	return 0;
}
*/