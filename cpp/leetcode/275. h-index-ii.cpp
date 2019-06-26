#include "public.h"

//24ms, 89.17%
//复用274题, 直接用排序后操作

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int i = 0;
		int csize = citations.size();

		while ((i < citations.size()) && (citations[csize - i - 1] > i)) i++;
		return i;
	}
};
