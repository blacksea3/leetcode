#include "public.h"

//8ms, 35.16%
//±©Á¦

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";

		vector<int> res;
		bool ispositive = true;
		if (num < 0)
		{
			ispositive = false;
			num *= -1;
		}

		while (num > 0)
		{
			res.insert(res.begin(), num % 7);
			num /= 7;
		}

		string resstr = "";
		if (!ispositive) resstr += "-";
		for (auto& r : res)
		{
			resstr += to_string(r);
		}
		return resstr;
	}
};
