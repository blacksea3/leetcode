#include "public.h"

//
//±©Á¦

class Solution {
public:
	int smallestCommonElement(vector<vector<int>>& mat) {
		for (auto& num : mat[0])
		{
			bool isfind = true;
			for (int index = 1; index < mat.size(); ++index)
			{
				if (!binary_search(mat[index].begin(), mat[index].end(), num))
				{
					isfind = false;
					break;
				}
			}
			if (isfind) return num;
		}
		return -1;
	}
};
