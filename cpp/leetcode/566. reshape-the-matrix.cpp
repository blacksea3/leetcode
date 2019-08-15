#include "public.h"

//44ms, 97.04%
//���ж���ģ��

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int oldr = nums.size();
		int oldc = nums[0].size();

		if (oldr*oldc != r * c) return nums;
		else
		{
			int prer = 0;
			int prec = 0;
			vector<vector<int>> res(r, vector<int>(c));

			for (int iter_r = 0; iter_r < r; ++iter_r)
			{
				for (int iter_c = 0; iter_c < c; ++iter_c)
				{
					res[iter_r][iter_c] = nums[prer][prec++];
					if (prec == oldc)
					{
						prec = 0;
						prer++;  //�����ж�prerԽ��, ��Ϊ��Խ���˴˴���ѭ����Ȼ�����һ��, Ȼ��͵���res, ��Ӱ����
					}
				}
			}
			return res;
		}
	}
};
