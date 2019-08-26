#include "public.h"

//12ms, 53.45%
//√∞≈›≈≈–Ú

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int loc1 = 0;
		int loc2 = 0;

		while (loc1 < arr1.size() && loc2 < arr2.size())
		{
			for (int i = loc1; i < arr1.size(); ++i)
			{
				if (arr1[i] == arr2[loc2])
				{
					if (i != loc1) swap(arr1[i], arr1[loc1]);
					loc1++;
				}
			}
			loc2++;
		}

		if (loc1 != arr1.size())  //ªπ”– £”‡µƒ
		{
			sort(arr1.begin() + loc1, arr1.end());
		}
		return arr1;
	}
};
