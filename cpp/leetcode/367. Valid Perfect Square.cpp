//binary search

//0ms, 100%

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 0) return false;
		int left = 1;
		int right = num;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if ((num%mid == 0) && (num / mid == mid)) return true;
			else if (float(num) / mid > mid) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};