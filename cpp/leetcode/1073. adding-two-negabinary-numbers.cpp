#include "public.h"

//32ms, 17.58%
//负二进制, 数学

class Solution {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		//special input
		if ((arr1.size() == 1) && (arr1[0] == 0)) return arr2;
		if ((arr2.size() == 1) && (arr2[0] == 0)) return arr1;

		//traverse reversely

		int l1 = arr1.size() - 1;
		int l2 = arr2.size() - 1;
		int minuscarry = 0;
		int poscarry = 0;

		vector<int> res = {};

		while (l1 >= 0 || l2 >= 0 || minuscarry || poscarry)
		{
			int pre1 = (l1 >= 0) ? arr1[l1] : 0;
			int pre2 = (l2 >= 0) ? arr2[l2] : 0;

			if ((minuscarry) && ((pre1 + pre2) == 0))
			{
				int sum = 1;
				poscarry = 1;
				res.insert(res.begin(), sum);
				l1--;
				l2--;
				minuscarry = 0;
			}
			else
			{
				int sum;
				if (minuscarry)
				{
					sum = (pre1 + pre2 - minuscarry) % 2;
					minuscarry = (pre1 + pre2 - minuscarry) / 2;
					poscarry = 0;
					res.insert(res.begin(), sum);
					l1--;
					l2--;
				}
				else if (poscarry)
				{
					sum = (pre1 + pre2 + poscarry) % 2;
					minuscarry = (pre1 + pre2 + poscarry) / 2;
					poscarry = 0;
					res.insert(res.begin(), sum);
					l1--;
					l2--;
				}
				else
				{
					sum = (pre1 + pre2) % 2;
					minuscarry = (pre1 + pre2) / 2;
					res.insert(res.begin(), sum);
					l1--;
					l2--;
				}
			}
		}

		while (res.size() >= 2)
		{
			if (res[0] == 0) res.erase(res.begin());
			else break;
		}

		return res;
	}
};
