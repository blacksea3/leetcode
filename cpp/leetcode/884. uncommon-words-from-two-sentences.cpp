#include "public.h"

/*44ms, 94.97%
#python3Ð´ÆðÀ´¿ì

class Solution:
	def uncommonFromSentences(self, A: str, B: str) -> List[str]:
		lista = A.split(' ')
		listb = B.split(' ')

		dicta = {}
		dictb = {}

		for i in lista:
			if i not in dicta:
				dicta[i] = 1
			else:
				dicta[i] += 1

		for i in listb:
			if i not in dictb:
				dictb[i] = 1
			else:
				dictb[i] += 1

		res = []

		for key, value in dicta.items():
			if value == 1 and key not in dictb:
				res.append(key)

		for key, value in dictb.items():
			if value == 1 and key not in dicta:
				res.append(key)
		return res

*/
