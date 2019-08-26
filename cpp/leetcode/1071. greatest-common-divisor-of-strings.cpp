#include "public.h"

//44ms, 91.21%
//python3写起来方便
//从大到小判断str1与str2的公因子长度字符串是否相等, 是否可以乘以各自倍数生成父字符串
/*
class Solution:
	def gcdOfStrings(self, str1: str, str2: str) -> str:
		l1 = len(str1)
		l2 = len(str2)

		for i in range(min(l1,l2),0,-1):
			if (l1%i == 0) and (l2%i == 0):
				if (str1 == str1[0:i]*(l1//i)) and (str2 == str1[0:i]*(l2//i)):
					return str1[0:i]

		return ""
*/
