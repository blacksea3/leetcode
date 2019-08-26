#include "public.h"

//0ms, 100%
//混合dp, 此处dp是函数
//dp[i, target]: 目标是target, 这里的 i 表示我们正在考虑使用 x^i 来改变目标值，使原本的 target 将会变成一个新的且能被 x^i 整除的目标值。
//真正的dp函数实现是: 逐次上升: 从最底层i=0开始
//注意最底层i=0时, 实现1需要加两个x相除的值
//而递归时, 上层实现1(即实现x的某个正整数次方)只需要加x某个次方就行

class Solution {
private:
	unordered_map<string, int> um;
	int gblx;

	int dp(int i, int target)
	{
		string code = "" + to_string(i) + "#" + to_string(target);
		if (um.find(code) != um.end()) return um[code];

		int res;
		if (target == 0) res = 0;
		else if (target == 1) res = cost(i);
		else if (i >= 36) res = target + 1;     //这里是为了强行停止递归: 注意到绝对不可能用x的巨大次方, 会有上限
		else
		{
			int t = target / gblx;
			int r = target % gblx;
			res = min(r * cost(i) + dp(i + 1, t), (gblx - r) * cost(i) + dp(i + 1, t + 1));  //这里的t+1其实就是t加gblx的某个次方, 这里相当于降维处理
		}

		um[code] = res;
		return res;
	}

	int cost(int x)
	{
		return (x > 0) ? x : 2;
	}

public:
	int leastOpsExpressTarget(int x, int target) {
		gblx = x;
		return dp(0, target) - 1;
	}
};

