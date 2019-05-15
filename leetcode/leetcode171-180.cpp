#include "include.h"

#ifdef LEETCODE_171_180
#include "public.h"
#include "leetcode.h"

int Solution::titleToNumber(string s)
{
	int res = 0;
	for (auto is : s)
	{
		res *= 26;
		res += is - 'A' + 1;
	}
	return res;
}

int Solution::trailingZeroes(int n)
{
	//识别5/5平方/5三次方的数量
	//你只需要搞清楚n/5 ; n/25....的值就可

	int iter_five = 5;
	int res = 0;
	while (n > iter_five)
	{
		res += n / iter_five;
		if (iter_five > 1000000000) break;  //防止溢出
		iter_five *= 5;
	}
	return res;
}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon)
{
	//dp[i][j]:从i,j到达右下角的最低初始健康指数

	//假设dungeon不为空
	int m = dungeon.size();     //row
	int n = dungeon[0].size();  //column

	vector<vector<int>> dp(m, vector<int>(n, 0));

	dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] > 0) ? 1 : -1 * dungeon[m - 1][n - 1] + 1;
	for (int i = m - 2; i >= 0; i--)
		dp[i][n - 1] = (dungeon[i][n - 1] >= dp[i + 1][n - 1]) ? 1 : (dp[i + 1][n - 1] - dungeon[i][n - 1]);
	for (int j = n - 2; j >= 0; j--)
		dp[m - 1][j] = (dungeon[m - 1][j] >= dp[m - 1][j + 1]) ? 1 : (dp[m - 1][j + 1] - dungeon[m - 1][j]);

	for (int i = m - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			dp[i][j] = min((dungeon[i][j] >= dp[i + 1][j]) ? 1 : (dp[i + 1][j] - dungeon[i][j]),
				(dungeon[i][j] >= dp[i][j + 1]) ? 1 : (dp[i][j + 1] - dungeon[i][j])
			);
		}
	}

	return dp[0][0];

}

bool Solution::cmpnum_179(int num1, int num2)
{
	//直接把num1拼到num2上面去吧
	//用string 比较!
	string s1 = to_string(num1) + to_string(num2);
	string s2 = to_string(num2) + to_string(num1);
	return s1 > s2 ? true : false;
}

string Solution::largestNumber(vector<int>& nums)
{
	//相当于给nums排序
	//考虑对两个数字单独比较 从最高位开始比较
	//然后用 O(n^2)方法吧
	//给个冒泡
	//这里是小的在前面
	for (int i = 0; i < nums.size() - 1; i++)
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (cmpnum_179(nums[i], nums[j]))
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}

	//倒过来遍历,生成string
	string res = "";
	for (int i = nums.size() - 1; i >= 0; i--)
		res += to_string(nums[i]);

	//有必要去除开头的0, FUCK
	//这仅仅会出现在全是0的情况......
	while (res.size() > 1)
		if (res[0] == '0')
			res.erase(res.begin());
		else
			break;

	return res;
}


#else
#endif
