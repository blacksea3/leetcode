#include "include.h"

#ifdef LEETCODE_181_190
#include "public.h"
#include "leetcode.h"

string Solution::extract_40_bits_187(long long num)
{
	string res;
	for (int i = 0; i < 10; i++)
	{
		num >>= 4;
		char temp = num & 0x0000000f;
		if (temp == 0x01)
			res.insert(res.begin(), 'A');
		else if (temp == 0x03)
			res.insert(res.begin(), 'C');
		else if (temp == 0x07)
			res.insert(res.begin(), 'G');
		else
			res.insert(res.begin(), 'T');
	}
	//这么操作下来long的第20至60位存放了有效二进制
	return res;
}

long long  Solution::generate_40_bits_187(string s)
{
	long long  res1 = 0;
	for (auto is : s)
	{
		res1 |= (((is & 0x10) >> 1) + (is & 0x07));
		res1 <<= 4;
	}
	//这么操作下来long的第20至60位存放了有效二进制
	return res1;
}


vector<string> Solution::findRepeatedDnaSequences(string s)
{
	//滑动窗口,位运算
	//A 0x41; C 0x43; G 0x47; T 0x54;
	//A 01000001 C 01000011 G 01000111 T 01010100

	//取第4/6/7/8位,然后一个滑动窗口对应一个40位唯一二进制
	//移动滑动窗口时同时移动这个二进制
	//40位需要一个long

	int ssize = s.size();
	if (ssize <= 10) return vector<string> {};

	//init
	unordered_set<long long > his;
	his.insert(generate_40_bits_187(s.substr(0, 10)));
	vector<string> res;

	for (int i = 1; i <= ssize - 10; i++)
	{
		long long ltemp = generate_40_bits_187(s.substr(i, 10));
		if (his.find(ltemp) != his.end())
		{
			string stemp = extract_40_bits_187(ltemp);
			vector<string>::iterator itea = find(res.begin(), res.end(), stemp);
			if (itea == res.end())
				res.push_back(stemp);
		}	
		else
			his.insert(ltemp);
	}
	return res;
}

int Solution::maxProfit(int k, vector<int>& prices)
{
	//弄一个巨大的dp
	//dp[i][j]
	// 0 <= i < prices.size()
	// 0 <= j <= 2*k,  j为偶数:表示目前未持仓, j为奇数表示目前持仓, (j+1)/2 表示包括当前,已进行的买卖轮数
	//例如: j = 1与2 表示当前是第一轮买卖
	// k如果=0 ,返回0

	//注意上述的做法内存会爆
	//仅需要保存某一天的利润就可以了
	//因此不需要i这个维度

	//注意k,有效的k不可能比prices.size() - 1还要大
	//另外注意,k >= prices.size()/2时,采用贪心方法,可以节省时间,否则时间会爆
	//这是因为,只要这样无论股价如何变化,只需要低买高卖就可以了

	if (k == 0) return 0;
	if (prices.size() == 1) return 0;

	//操作k
	if (k >= prices.size() / 2)
	{
		int res = 0;
		int old = INT_MAX;
		for (auto price : prices)
		{
			if (price > old) res += price - old;
			old = price;
		}
		return res;
	}
	else
	{
		vector<int> dp(2 * k + 1, 0);

		//可能前几天有非法情况,这实际上不要紧:)  (就是统计买卖轮数错掉,但是利润没有错噢)
		for (int j = 0; j < k; j++)
			dp[2 * j + 1] = -1 * prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			for (int j = 0; j < k; j++)
			{
				dp[2 * j + 1] = max(dp[2 * j] - prices[i], dp[2 * j + 1]);
				dp[2 * j + 2] = max(dp[2 * j + 1] + prices[i], dp[2 * j + 2]);
			}
		}

		//目前未持仓的最大值
		int res = 0;
		for (int j = 0; j <= k; j++)
			res = max(dp[2 * j], res);

		return res;
	}
}

void Solution::rotate(vector<int>& nums, int k)
{
	if (nums.size() == 0) return;  //dump

	//先得知有效的移动次数
	k = k % nums.size();
	if (k == 0) return;  //不需要旋转

	//用评论的方法,时间复杂度O(n)
	//反转前半部分,后半部分,全部,  复杂度可以认为是O(2*n) = O(n)

	reverse(nums.begin(), nums.begin() + nums.size() - k);
	reverse(nums.begin() + nums.size() - k, nums.end());
	reverse(nums.begin(), nums.end());

}

uint32_t Solution::reverseBits(uint32_t n)
{
	//朴素的位运算

	uint32_t res = 0;
	for (int i = 0; i < 32; i++)
	{
		res <<= 1;
		if (n & 0x00000001)
			res |= 0x00000001;
		n >>= 1;
	}
	return res;
}

#else
#endif
