#include "public.h"

class Solution {
public:
	int game(vector<int>& guess, vector<int>& answer) {
		int res = 0;
		if (guess[0] == answer[0]) res++;
		if (guess[1] == answer[1]) res++;
		if (guess[2] == answer[2]) res++;
		return res;
	}
};
