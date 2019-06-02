#include "public.h"

class Solution {
private:
	int howmany_addtional_one(int num, int start, int end, int prestartnums, int preendnums, int full, bool isneglect_prestartnums)
	{
		if (start == end)
			if (start == num) return preendnums;
			else return 0;
		else if (start < end)
		{
			if ((start < num) && (num < end))
				return full;
			else if (start == num)
				return isneglect_prestartnums ? 0 : prestartnums;
			else if (num == end)
				return preendnums;
			else return 0;
		}
		else
		{
			if ((start < num) || (num < end))
				return full;
			else if (start == num)
				return isneglect_prestartnums ? 0 : prestartnums;
			else if (num == end)
				return preendnums;
			else return 0;
		}
	}

public:
	int digitsCount(int d, int low, int high) {
		//here for exm: 8 in  26 -- 69,    69-26 / 10 = 4,   then has 4 ge 8 in last loc, then since 6-9 is consistent, add another 8

		int res = 0;
		int delta = high - low;

		int mul = 1;
		int prestartnums = 1;
		int preendnums = 1;

		bool isneglect_prestartnums = false;

		while (delta > 0)
		{
			delta = high - low;
			res += mul * (delta  / 10);
			if (isneglect_prestartnums && (delta >= 10)) res -= mul;

			res += howmany_addtional_one(d, low % 10, high % 10, prestartnums, preendnums, mul, isneglect_prestartnums);
			delta /= 10;
			prestartnums += (9 - (low % 10)) * mul;   //19 - 49   1
			preendnums += high % 10 * mul;
			low /= 10;
			high /= 10;
			mul *= 10;
			if (low == 0 && d == 0) isneglect_prestartnums = true;
		}

		if (d == 1) res += howmany_addtional_one(d, low % 10, high % 10, prestartnums, preendnums, mul, isneglect_prestartnums);

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->digitsCount(0,1080,2160) << endl;    //339
	cout << s->digitsCount(1,1,10) << endl;         //2
	cout << s->digitsCount(0,1,20) << endl;         //2
	cout << s->digitsCount(3, 100, 250) << endl;    //35
    cout << s->digitsCount(1, 1, 13) << endl;       //6
	cout << s->digitsCount(0, 5000, 10000) << endl;  //1504
	cout << s->digitsCount(1, 625, 1250) << endl;  //473
	
	cout << s->digitsCount(0, 1, 200) << endl; //
	cout << s->digitsCount(0, 1, 200000000) << endl; //148888897

	cout << s->digitsCount(1, 1, 200) << endl;       //140? 
	cout << s->digitsCount(1, 1, 200000000) << endl; //2600000000

	return 0;
}