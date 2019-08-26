#include "public.h"

/*40ms, 37.50%
//��һ˼·
//����һ��absval = A��ֵ - ��Ӧ����, Ȼ����һ��, ������
//���ȴ����0���ҵ���һ��>0����, ��ô����С�����ָ������ǵ�ǰ�÷�
//�����������һ����+A.size(), ��������vector, Ȼ����1��...
//O(nlogn) TLE

//����Ż�: ��vectorͳ�Ƹ���absval���ָ���, ��ʼ��K=0�ô�, Ȼ��ÿ�ε���vector�ڼ����ֵ(һ�ε���һ��), ��ͬʱ��ȥ����<=��ǰ-1*K�����ָ���
//��ΪO(n)
*/

class Solution {
public:
	int bestRotation(vector<int>& A) {
		int as = A.size();
		vector<int> cpAabs(as);

		for (int i = 0; i < as; ++i)
		{
			cpAabs[i] = A[i] - i;
		}

		vector<int> absval(3 * as);  //��Χ-2*as - as, ��С: 3*as, �±������ʵֵ+2*as

		for (int i = 0; i < as; ++i)
		{
			absval[A[i] - i + 2 * as]++;
		}

		//��ʼ����һ��res, <=0�ø���
		int maxres;
		int preres = 0;
		int resK = 0;
		for (int i = 0; i <= 2 * as; ++i)
		{
			preres += absval[i];
		}
		maxres = preres;

		//ѭ����������
		int preK = 0;
		while (preK < as - 1)
		{
			//����������(preK+1)����, ����A.size(), Ȼ�����absval, ��Ԥ��res
			if (cpAabs[preK] > -1 * (preK)) preres++;//����as֮��鿴ԭ�����Ƿ����, ����res���ȼ�һ
			absval[cpAabs[preK] + 2 * as]--;
			absval[cpAabs[preK] - as + 2 * as]++;
			preK++; //preK��һ, �޸���Ҫ�Ƚϵ�����
			//Ȼ������-1*(preK-1)ֵ���ڲ�������, ���ڶ�Ӧ��<=-1*preK����
			preres -= absval[-1 * (preK - 1) + 2 * as];
			//���½��
			if (preres > maxres)
			{
				maxres = preres;
				resK = preK;
			}
		}
		return resK;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 2,3,1,4,0 };
	//cout << s->bestRotation(A);
	vector<int> A = { 0,3,1,3,1 };
	cout << s->bestRotation(A);
	return 0;
}