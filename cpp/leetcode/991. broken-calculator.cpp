//0ms, 100%

//Greedy: from Y to X, make Y/2 as can as possible

class Solution {
public:
	int brokenCalc(int X, int Y) {
		int res = 0;

		while (X != Y)
		{
			if (Y < X)
			{
				res += (X - Y);
				break;
			}
			else if (Y % 2 == 0)
			{
				Y /= 2;
				res++;
			}
			else
			{
				Y = (Y + 1) / 2;
				res += 2;
			}
		}
		return res;
	}
};

