
//4ms, 98.45%

//This is just Newton iteration

class Solution {
public:
	int mySqrt(int x) {
		//here problem ensure that x >= 0
		//f(r) = r^2 - x = 0

		//r(n+1) = r(n) - f(r(n))/f'(r(n)) => r(n+1) = r(n) - (r(n)*r(n) - x)/(2*r(n))
		//=> r(n+1) = (r(n)+x/r(n))/2

		if (x <= 1) return x;

		int r = x;
		while (r > x / r)
			r = (int)(((long)r + x / r) / 2);

		return r;
	}
};