#include "public.h"

//4ms, 70.80%
//�ӵ�λ����λѰ�ҵ�һ����λn<�ٽ���λ��Ԫ��, Ȼ��ֵ>��λn�ĵ�λ�е���Сֵ�ҳ�������Ե�,
//�������Ե�λ�ǴӸ�λ����λ��������

class Solution {
public:
	int nextGreaterElement(int n) {
		vector<int> vals;

		while (n > 0)
		{
			vals.insert(vals.begin(), n % 10);
			n /= 10;
		}

		//Ѱ��
		bool isFind = false;
		int index;
		for (index = (int)vals.size() - 2; index >= 0; --index)
		{
			if (vals[index] < vals[index + 1])
			{
				isFind = true;
				break;
			}
		}

		if (!isFind) return -1;
		else
		{
			//index: ������һ����λ: ֵ���ٽ��ĵ�λС
			int swapIndex = -1;
			int minVal = INT_MAX;
			for (int iterIndex = index + 1; iterIndex < vals.size(); ++iterIndex)
			{
				if (vals[iterIndex] > vals[index] && vals[iterIndex] < minVal)
				{
					swapIndex = iterIndex;
					minVal = vals[iterIndex];
				}
			}
			//����λ��
			swap(vals[swapIndex], vals[index]);
			//����
			sort(vals.begin() + index + 1, vals.end(), less<int>());
			//���ɽ��
			long long res = 0;

			for (int iterIndex = 0; iterIndex < vals.size(); ++iterIndex)
			{
				res *= 10;
				res += vals[iterIndex];
			}
			return (res <= INT_MAX) ? (int)res : -1;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->nextGreaterElement(12);
	return 0;
}
*/
