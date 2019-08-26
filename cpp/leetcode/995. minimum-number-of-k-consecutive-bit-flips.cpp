#include "public.h"

//180ms, 29.31%
//��ģ��
//ֱ�Ӵ�����ߵ�0��ʼ��
//����������, �в���K��0û�з�, ���군�� :)

//ģ���ʱ���һ������: ��ʾ�޸ĵ�������, ���������n��Ԫ��, ��ʾ�޸���n��, ͨ����ż���жϵ�ǰ�ǲ���1

class Solution {
public:
	int minKBitFlips(vector<int>& A, int K) {
		int loc = 0;
		int res = 0;
		queue<int> q;
		while (loc <= A.size() - 1)
		{
			while (!q.empty() && q.front() < loc) q.pop();

			if ((A[loc] + q.size()) % 2 == 0)
			{
				if (loc > A.size() - K) return -1;
				q.push(loc + K - 1);
				res++;
			}
			loc++;
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,1,0 };
	auto res = s->minKBitFlips(A, 2);
	return 0;
}
*/
