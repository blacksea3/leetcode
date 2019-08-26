#include "public.h"

//100ms, 38.24%
//暴力感觉不会TLE

class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		//对初始位置进行暴力
		int res = 0;
		int ars = A.size();
		int acs = A[0].size();

		for (int star = -1 * ars + 1; star < ars; ++star)
		{
			for (int stac = -1 * acs + 1; stac < acs; ++stac)
			{
				//初始位置(star, stac)
				//然后计算行终点和列终点, 接下来暴力求解
				//分四种情况, 麻烦的一比
				int tempres = 0;
				if ((star < 0) && (stac < 0))
				{
					int arabs = -1 * star;
					int acabs = -1 * stac;
					for (int stbr = 0; stbr <= ars - 1 + star; ++stbr)
					{
						for (int stbc = 0; stbc <= acs - 1 + stac; ++stbc)
						{
							if ((A[stbr - star][stbc - stac] == 1) && (B[stbr][stbc] == 1)) tempres++;
						}
					}
				}
				else if ((star >= 0) && (stac >= 0))
				{
					for (int stbr = star; stbr < ars; ++stbr)
					{
						for (int stbc = stac; stbc < acs; ++stbc)
						{
							if ((A[stbr - star][stbc - stac] == 1) && (B[stbr][stbc] == 1)) tempres++;
						}
					}
				}
				else if ((star < 0) && (stac >= 0))
				{
					for (int stbr = 0; stbr <= ars - 1 + star; ++stbr)
					{
						for (int stbc = stac; stbc < acs; ++stbc)
						{
							if ((A[stbr - star][stbc - stac] == 1) && (B[stbr][stbc] == 1)) tempres++;
						}
					}
				}
				else
				{
					for (int stbr = star; stbr < ars; ++stbr)
					{
						for (int stbc = 0; stbc <= acs - 1 + stac; ++stbc)
						{
							if ((A[stbr - star][stbc - stac] == 1) && (B[stbr][stbc] == 1)) tempres++;
						}
					}
				}
				res = max(res, tempres);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> A = { {1,1,0},{0,1,0},{0,1,0} };
	vector<vector<int>> B = { {0,0,0},{0,1,1},{0,0,1} };
	cout << s->largestOverlap(A, B);
	return 0;
}
*/
