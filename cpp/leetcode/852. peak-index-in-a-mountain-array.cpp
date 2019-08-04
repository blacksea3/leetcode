#include "public.h"

//20ms, 63.75%
//simple solution, 找到第一个右节点<左节点的左节点

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (A[i] > A[i + 1]) return i;
		}
		return -999; //dump
	}
};
