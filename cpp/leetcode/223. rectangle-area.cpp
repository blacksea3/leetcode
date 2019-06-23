#include "public.h"

//8ms, 99.09%
//สýังฬโ

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int dupx = 0;
		int dupy = 0;

		if (A <= E)
		{
			if (C > G) dupx = (G - E);
			else if (C > E) dupx = (C - E);
		}
		else if (A < G)
		{
			if (C <= G) dupx = (C - A);
			else dupx = (G - A);
		}

		if (B <= F)
		{
			if (D > H) dupy = (H - F);
			else if (D > F) dupy = (D - F);
		}
		else if (B < H)
		{
			if (D <= H) dupy = (D - B);
			else dupy = (H - B);
		}
		else;
		return (C - A)*(D - B) - dupx * dupy + (G - E)*(H - F);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->computeArea(0, 0, 50, 40, 0, 0, 50, 40);
	return 0;
}*/
