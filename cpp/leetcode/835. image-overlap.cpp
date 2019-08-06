#include "public.h"

//100ms, 38.24%
//�����о�����TLE

class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		//�Գ�ʼλ�ý��б���
		int res = 0;
		int ars = A.size();
		int acs = A[0].size();

		for (int star = -1 * ars + 1; star < ars; ++star)
		{
			for (int stac = -1 * acs + 1; stac < acs; ++stac)
			{
				//��ʼλ��(star, stac)
				//Ȼ��������յ�����յ�, �������������
				//���������, �鷳��һ��
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
