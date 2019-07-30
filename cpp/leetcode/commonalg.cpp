#include "public.h"

//Õ·×ªÏà³ı
int gcd(int x, int y)
{
	if (!y)
		return x;
	else
		return gcd(y, x%y);
}
