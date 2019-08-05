#include "public.h"

//24ms, 91.33%
//ģ��, ״̬�л�

class Solution {
public:
	int longestMountain(vector<int>& A) {
		if (A.empty()) return 0;

		int state = 0;  //0:�ȴ��ҵ���ʼ��, 1:�ȴ��ҵ�ת�۵�, 2:�ȴ��ҵ��յ�
		int startpoint = 0;
		int res = 0;

		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (state == 0)
			{
				if (A[i] < A[i + 1])
				{
					state = 1;
					startpoint = i;
				}
				else
				{
					continue;
				}
			}
			else if (state == 1)
			{
				if (A[i] < A[i + 1]) continue;
				else if (A[i] > A[i + 1])
				{
					state = 2;
				}
				else
				{
					state = 0;
				}
			}
			else
			{
				if (A[i] > A[i + 1]) continue;
				else
				{
					res = max(res, i - startpoint + 1);
					if (A[i] < A[i + 1])
					{
						state = 1;
						startpoint = i;
					}
					else
					{
						state = 0;
					}
				}
			}
		}
		if (state == 2) res = max(res, (int)A.size() - startpoint);

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 875,884,239,731,723,685 };
	cout << s->longestMountain(A);
	return 0;
}
*/
