#include "public.h"

//44ms, 91.21%
//python3д��������
//�Ӵ�С�ж�str1��str2�Ĺ����ӳ����ַ����Ƿ����, �Ƿ���Գ��Ը��Ա������ɸ��ַ���
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
