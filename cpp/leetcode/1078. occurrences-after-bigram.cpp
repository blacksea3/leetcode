#include "public.h"

//ʵ���������python3д����, �ҾͲ���c++��

//44ms, 87.05%

/*
class Solution :
	def findOcurrences(self, text: str, first : str, second : str)->List[str] :
	strs = text.split(' ')
	res = []
	for i in range(len(strs) - 2) :
		if ((strs[i] == first) and (strs[i + 1] == second)) :
			res.append(strs[i + 2])
			return res
*/