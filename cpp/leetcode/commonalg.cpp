#include "public.h"

//շת���
int gcd(int x, int y)
{
	if (!y)
		return x;
	else
		return gcd(y, x%y);
}
