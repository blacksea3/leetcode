#include "public.h"

//104ms, 46.60%
//暴力, 直接从N开始获取回文数, 然后判断是否素数

class Solution {
private:
	bool isprime(int x)
	{
		if (1 == x)
		{
			return false;
		}
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x%i == 0)
			{
				return false;
			}
		}
		return true;
	}


	//找到>N的下一个回文数
	int getnext(int N)
	{
		vector<int> ffnums = { 1,11,101,1001,10001,100001,1000001,10000001,100000001 };
		int cpN = N;
		vector<int> nums;
		while (cpN > 0)
		{
			nums.insert(nums.begin(), cpN % 10);
			cpN /= 10;
		}
		//获取前半段, 判读是否要加个1生成完整数
		if (nums.size() % 2)
		{
			string st = to_string(N);
			st = st.substr(0, nums.size() / 2 + 1);
			int prehalf = atoi(st.c_str());
			string rawhalf = st;
			for (int i = nums.size() / 2; i > 0; --i)
			{
				st.push_back(st[i-1]);
			}
			int n = atoi(st.c_str());
			if (n > N) return n;
			else
			{
				//重整nums
				prehalf++;
				string afst = to_string(prehalf);
				if (afst.size() != rawhalf.size())  //有了进位
				{
					return ffnums[nums.size()];
				}
				else
				{
					//奇数位
					for (int i = nums.size() / 2; i > 0; --i)
					{
						afst.push_back(afst[i - 1]);
					}
					int afn = atoi(afst.c_str());
					return afn;
				}
			}
		}
		else
		{
			string st = to_string(N);
			st = st.substr(0, nums.size() / 2);
			int prehalf = atoi(st.c_str());
			string rawhalf = st;
			for (int i = nums.size() / 2; i > 0; --i)
			{
				st.push_back(st[i-1]);
			}
			int n = atoi(st.c_str());
			if (n > N) return n;
			else
			{
				//重整nums
				prehalf++;
				string afst = to_string(prehalf);
				if (afst.size() != rawhalf.size())  //有了进位
				{
					return ffnums[nums.size()];
				}
				else
				{
					//偶数位
					for (int i = nums.size() / 2; i > 0; --i)
					{
						afst.push_back(afst[i-1]);
					}
					int afn = atoi(afst.c_str());
					return afn;
				}
			}
		}
	}

public:
	int primePalindrome(int N) {
		int pre = N - 1;
		while (true)
		{
			int next = getnext(pre);
			if (isprime(next)) return next;
			else pre = next;
		}
		return -999;  //dump
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->primePalindrome(6) << endl;
	cout << s->primePalindrome(8) << endl;
	cout << s->primePalindrome(13) << endl;
	return 0;
}
*/
