#include "public.h"

//4ms, 97.47%
//数学
//使用, use k = A*(n-1)! + B*(n-2)! + ...., 计算A, B, C...就行

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1) return "1";
		if (n == 2) return (k == 1) ? "12" : "21";
		//n:3   2=1*2+0*1

		//note 0<=n<=9
		vector<int> factorial = { 1,1,2,6,24,120,720,5040,40320 };
		vector<int> res(n - 1, 0);

		//k = A*(n-1)! + B*(n-2)! + ....
		int countloc = 0;
		for (int i = n - 1; i >= 2; i--)
		{
			res[countloc] = (k - 1) / factorial[i];
			k -= res[countloc] * factorial[i];
			countloc++;
		}
		res[countloc] = k - 1;

		string returns = "";
		vector<char> nums = { '1','2','3','4','5','6','7','8','9' };
		for (int i = 0; i < n - 1; i++)
		{
			returns += nums[res[i]];
			nums.erase(nums.begin() + res[i]);
		}
		returns += nums[0];

		return returns;
	}
};