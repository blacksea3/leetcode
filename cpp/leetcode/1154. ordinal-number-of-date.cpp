#include "public.h"

//�õ�pythonд, ������c++ string -> int ��ɶ�⺯��ת����

/*
class Solution:
	def isrunnian(self, n):
		if n%4==0 and n%100!=0:
			return True
		elif n%100==0 and n%400==0:
			return True
		else:
			return False

	def ordinalOfDate(self, date: str) -> int:
		year = int(date[0:4])
		v = [31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365]

		if self.isrunnian(year):
			good = 1
		else:
			good = 0

		month = int(date[5:7])
		day = int(date[8:10])

		if month == 1:
			return day
		elif month == 2:
			return day + v[0]
		else:
			res = day + v[month - 2] + good
			return res
*/