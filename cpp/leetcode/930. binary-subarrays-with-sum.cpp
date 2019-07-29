#include "public.h"

//32ms, 83.61%
//��queue��¼ÿ��1֮ǰ��0������
//����¼������0֮��, ��һ����1ʱ/��ĩβʱ, ����0�������������, ����ڷ�֮ǰ����size==S, ��ôres += ������*��ǰ0����, Ȼ�����pop(), ��push��ǰ0����
//S=0��������

class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		if (S > 0)
		{
			queue<int> q;
			int loc = 0;
			int prezeros = 0;
			int res = 0;
			while (true)
			{
				if (loc == A.size())
				{
					if (q.size() == S)
					{
						res += (q.front() + 1)*(prezeros + 1);
					}
					return res;
				}
				else if (A[loc] == 0) prezeros++;
				else
				{
					if (q.size() == S)
					{
						res += (q.front() + 1)*(prezeros + 1);
						q.pop();
						q.push(prezeros);
					}
					else
					{
						q.push(prezeros);
					}
					prezeros = 0;
				}
				loc++;
			}
			return -999;
		}
		else  //��������, ��0�ĸ����Ϳ���
		{
			vector<int> v;
			int prezeros = 0;
			int res = 0;
			for (int i = 0; i < A.size(); ++i)
			{
				if (A[i] == 1)
				{
					res += (prezeros + 1)*prezeros / 2;
					prezeros = 0;
				}
				else prezeros++;
			}
			res += (prezeros + 1)*prezeros / 2;
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 0,0,0,0,1 };
	cout << s->numSubarraysWithSum(A, 2);
	return 0;
}
*/
