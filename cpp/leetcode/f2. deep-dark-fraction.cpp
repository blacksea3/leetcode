#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	vector<int> fraction(vector<int>& cont) {
		int son;
		int mon;

		mon = cont[cont.size() - 1];
		son = 1;

		for (int index = (int)cont.size() - 2; index >= 0; --index)
		{
			son += mon * cont[index];
			swap(son, mon);
		}

		return vector<int>{son, mon};
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> count = { 3,2,0,2 };
	auto res = s->fraction(count);
	return 0;
}
*/
