#include "public.h"

//36ms, 93.40%
//����, �����ҵ�ֵһ�������ֵ����Сֵ֮��, Ȼ���������ÿһ�б��м�ֵ������ֵĸ���

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int lo = matrix[0][0], hi = matrix.back().back();
		
		while (lo < hi)
		{
			int mid = lo + (hi - lo >> 1);
			int count = 0;
			// O(n)
			for (auto& m:matrix) 
			{
				// O(logn)
				// <= mid ��Ԫ�ظ���
				count += upper_bound(m.begin(), m.end(), mid) - m.begin();
			}
			if (k <= count) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
};
