//0ms, 100%
//数学, 牛顿迭代法

class Solution {
public:
	int mySqrt(int x) {
		//here problem ensure that x >= 0
		//f(r) = r^2 - x = 0

		//r(n+1) = r(n) - f(r(n))/f'(r(n)) => r(n+1) = r(n) - (r(n)*r(n) - x)/(2*r(n))
		//=> r(n+1) = (r(n)+x/r(n))/2

		if (x <= 1) return x;

		long r = x;
		long cpX = x;
		while (r > cpX / r)
			r = ((r + cpX / r) / 2);

		return (long)r;
	}
};
