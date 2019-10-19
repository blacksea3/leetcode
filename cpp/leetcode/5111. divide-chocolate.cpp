#include "public.h"

//
//极小化极大
//二分+贪心

class Solution {
public:
	int maximizeSweetness(vector<int>& sweetness, int K) {
		K++;

		int l = sweetness[0], r = 0;
		int n = sweetness.size();
		for (int i = 0; i < n; i++) {
			r += sweetness[i];
			if (l > sweetness[i]) {
				l = sweetness[i];
			}
		}

		int ans = -1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int sum = 0;
			int cnt = 1;
			for (int i = 0; i < n; i++) {
				if (sum >= mid)
				{
					cnt++;
					sum = sweetness[i];
				}
				else{
					sum += sweetness[i];
				}
			}
			if (cnt < K) {
				r = mid - 1;
			}
			else if (cnt > K){
				ans = max(ans, mid);
				l = mid + 1;
			}
			else
			{
				if (sum >= mid)
				{
					ans = max(ans, mid);
					l = mid + 1;
				}
				else
				{
					r--;
				}
			}
		}
		return ans;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> sweetness0 = { 90670,55382,95298,95795,73204,41464,18675,30104,47442,55307 };
	cout << s->maximizeSweetness(sweetness0, 6) << endl;

	vector<int> sweetness = { 1,2,3,4,5,6,7,8,9 };
	cout << s->maximizeSweetness(sweetness, 5) << endl;
	vector<int> sweetness2 = { 5,6,7,8,9,1,2,3,4 };
	cout << s->maximizeSweetness(sweetness2, 8) << endl;
	vector<int> sweetness3 = { 1,2,2,1,2,2,1,2,2 };
	cout << s->maximizeSweetness(sweetness3, 2) << endl;
	return 0;
}
*/
