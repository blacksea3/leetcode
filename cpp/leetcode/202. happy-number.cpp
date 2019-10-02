#include "public.h"

//8ms, 47.56%
/*
//模拟
//朴素的方法,如果当前平方和已经历史上存在过,那么不是快乐数
//如果当前平方和为1则是快乐数
//否则循环

class Solution {
private:
	int getsquaresum_202(int n)
	{
		int res = 0;
		while (n > 0)
		{
			res += (n % 10)*(n % 10);
			n /= 10;
		}
		return res;
	}

public:
	//输入是正整数
	bool isHappy(int n) {
		unordered_set<int> his;
		while (true)
		{
			int temp = getsquaresum_202(n);
			if (temp == 1) return true;
			else if (his.find(temp) == his.end()) his.insert(temp);
			else break;
			n = temp;
		}
		return false;
	}
};
*/

//0ms, 100%
//快慢指针, 类似链表找循环

class Solution {
private:
	int getSquareSum(int n)
	{
		int res = 0;
		while (n > 0)
		{
			res += (n % 10)*(n % 10);
			n /= 10;
		}
		return res;
	}
public:
	bool isHappy(int n) {
		int fa = getSquareSum(n);
		int sl = getSquareSum(n);
		sl = getSquareSum(sl);
		while (fa != sl)
		{
			fa = getSquareSum(fa);
			sl = getSquareSum(sl);
			sl = getSquareSum(sl);
		}
		return fa == 1;
	}
};
