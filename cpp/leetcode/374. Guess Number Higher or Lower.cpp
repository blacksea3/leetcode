// binary search

//0ms, 100%

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int left = 1;
		int right = n;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int res = guess(mid);
			if (res < 0) right = mid - 1;
			else if (res > 0) left = mid + 1;
			else return mid;
		}
		return -999;  //dump
	}
};

//dump function
int guess(int num)
{
	return 0;
}
