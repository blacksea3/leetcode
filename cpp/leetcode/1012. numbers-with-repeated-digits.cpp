#include "public.h"

//8ms, 71.19%
//倒过来, 计算没有任何1位重复的数字个数

class Solution {
private:
	//计算n!
	int muls(int n)
	{
		int res = 1;
		for (int i = 1; i <= n; ++i)
		{
			res *= i;
		}
		return res;
	}

	//计算A(a,b), a <= b;
	int fac(int a, int b)
	{
		return muls(b) / muls(b - a);
	}

public:
	int numDupDigitsAtMostN(int N) {
		int cpN = N;
		int l = 0;
		vector<int> nums;
		while (N > 0)
		{
			l++;
			nums.insert(nums.begin(), N % 10);
			N /= 10;
		}

		//计算位数小于l的非重复数字个数
		int nodup = 0;

		for (int i = 1; i < nums.size(); ++i)
		{
			nodup += 9 * fac(i - 1, 9);
		}

		//计算第0位至第i位是否有重复数
		unordered_set<int> temp_outer;
		vector<bool> hasdup(nums.size(), true);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (find(temp_outer.begin(), temp_outer.end(), nums[i]) == temp_outer.end())
			{
				temp_outer.insert(nums[i]);
				hasdup[i] = false;
			}
			else break;
		}


		//计算l位, 小于等于N的重复数字个数, 加到nodup上
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && hasdup[i-1]) //如果第0至第i位有重复数, 则break
				break;

			int first = nums[i];  //第i位还能放多少种数字
			if (i == 0) first--;
			if (i == nums.size() - 1) first++;

			unordered_set<int> temp;
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					if (find(temp.begin(), temp.end(), nums[j]) == temp.end())
					{
						first--;
						temp.insert(nums[j]);
					}
				}
				else if (nums[j] == nums[i] && i == nums.size() - 1)
				{
					if (find(temp.begin(), temp.end(), nums[j]) == temp.end())
					{
						first--;
						temp.insert(nums[j]);
					}
				}
			}

			int rem = 10;         //后面的位还能放多少种数字
			unordered_set<int> pn;
			for (int j = 0; j < i; ++j)
			{
				if (find(pn.begin(), pn.end(), nums[j]) == pn.end())
				{
					pn.insert(nums[j]);
					rem--;
				}
			}
			rem--;  //减掉第i位的
    		nodup += first * fac(nums.size() - 1 - i, rem); //nums.size() - 1 - i: 还有多少位
		}

		return cpN - nodup;
	}
};

int main()
{
	Solution* s = new Solution();
	//cout << s->numDupDigitsAtMostN(20) << endl;
	//cout << s->numDupDigitsAtMostN(100) << endl;
	//cout << s->numDupDigitsAtMostN(1000) << endl;
	cout << s->numDupDigitsAtMostN(110) << endl;
	return 0;
}
