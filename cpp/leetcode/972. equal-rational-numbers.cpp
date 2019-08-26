#include "public.h"

//60ms, 41.38%
//数学
//问题转换: 例如0.(12) = 0 + 12/100 + 12/10000...
//对于以下情况 x.xxxx(yyyyyy...) 括号长度为n, 括号内是r, 那么此值等于x.xxxx + r*p/(1-p), p=10^(-n)
//只需要把这些数字加起来, 然后强制转成最简分数即可

//分数类
//命名原则: p:分母, s:分子
//这题用c++写简直是反人类, python3有现成的Fraction库

/*
from fractions import Fraction

class Solution(object):
	def isRationalEqual(self, S, T):
		def convert(S):
			if '.' not in S:
				return Fraction(int(S), 1)
			i = S.index('.')
			ans = Fraction(int(S[:i]), 1)
			S = S[i+1:]
			if '(' not in S:
				if S:
					ans += Fraction(int(S), 10 ** len(S))
				return ans

			i = S.index('(')
			if i:
				ans += Fraction(int(S[:i]), 10 ** i)
			S = S[i+1:-1]
			j = len(S)
			ans += Fraction(int(S), 10**i * (10**j - 1))
			return ans

		return convert(S) == convert(T)

作者：LeetCode
链接：https://leetcode-cn.com/problems/two-sum/solution/xiang-deng-de-you-li-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
