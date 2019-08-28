#include "public.h"

//120ms, 66.03%
//��������
//�ö�����λ�洢�����Ƿ�ʹ��

class Solution {
private:
	int res = 0;
	int gblN;

	//����
	void recu(int used, int index)
	{
		if (index > gblN)
		{
			res++;
		}
		else
		{
			for (int i = 1; i <= gblN; ++i)
			{
				if ((used&(1 << (i - 1))) == 0)
				{
					if (i%index == 0 || index % i == 0)
					{
						recu(used | (1 << (i - 1)), index + 1);
					}
				}
			}
		}
	}

public:
	int countArrangement(int N) {
		gblN = N;
		recu(0, 1);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->countArrangement(2);
	return 0;
}
