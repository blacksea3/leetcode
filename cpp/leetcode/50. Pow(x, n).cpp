//4ms, 97.69%

//binary search(divide and conquer)

class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		bool sign = (n >= 0);

		while (n != 0)
		{
			if (n % 2 != 0)
				res *= x;
			x *= x;
			n /= 2;
		}

		return (sign) ? res : 1 / res;
	}
};