#include "public.h"

//4ms, 74.49%
//��5����������
//ԭ���е���Ŀ����������: ��5�ĺܴ�η���ʼ, �����125��ʼ, K/125=2, ��ô��2(125��250���е�����5), Ȼ��/25, ��x(���Ƕ��еڶ���5), ...�������� 

//���ڷ�����: ע�⵽�𰸽�������5����0
//���K�ܱ�ʾ�� K = a1 + a1/5 + a1/25 + a1/125... ��ô����Ϊ5, ����Ϊ0
//˼·��
//��������¼ÿһ�����ӿ��0����: 1, (5+1), (5+1)*5+1...
//  1, 6, 31, 156, 781, 3906, 19531, 97656, 
//Ȼ��K��μ�����Ӧ��, ͨ��ȡģ�ж��Ƿ����

class Solution {
public:
	int preimageSizeFZF(int K) {
		vector<long long> specials;

		long long start = 0;
		for (int i = 0; ; ++i)
		{
			start *= 5;
			start++;
			if (start > 1000000000) break;
			specials.push_back(start);
		}

		//��specials[maxloc]��ʼ��
		int cpK = K;
		int maxloc = specials.size() - 1;
		while (cpK > 0 && maxloc >= 0)
		{
			while (cpK > specials[maxloc])
			{
				cpK -= specials[maxloc];
			}
			if (cpK%specials[maxloc] >= (specials[maxloc] - maxloc))
			{
				return 0;
			}
			else
			{
				maxloc--;
			}
		}

		return 5;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->preimageSizeFZF(5) << endl;
	cout << s->preimageSizeFZF(3) << endl;
	return 0;
}
*/
