#include "public.h"

//
//只要有两个数互质就可以
// 如果不互质, 可以把他们弄到只剩下最大公因数
//半暴力

class Solution {
private:
	int gcd(int x, int y)
	{
		if (!y)
			return x;
		else
			return gcd(y, x%y);
	}

public:
	bool isGoodArray(vector<int>& nums) {
		if (nums.size() == 1) return false;
		else
		{
			int pre = nums[0];
			for (int i = 1; i < nums.size(); ++i)
			{
				int temp = gcd(pre, nums[i]);
				if (temp == 1) return true;
				else
				{
					pre = temp;
				}
			}
			return false;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> v = { 3,6 };
	cout << s->isGoodArray(v) << endl;
	vector<int> v2 = { 6,10,15 };
	cout << s->isGoodArray(v2) << endl;
	vector<int> v3 = { 29,6,10 };
	cout << s->isGoodArray(v3) << endl;
	vector<int> v4 = { 12,5,7,23 };
	cout << s->isGoodArray(v4) << endl;
	return 0;
}
*/
