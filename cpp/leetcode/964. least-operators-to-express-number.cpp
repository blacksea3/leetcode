#include "public.h"

//
//���൱����1,x,x*x,x*x*x...�ļӼ�����target, �ҼӼ���������
//ò���Ǹ���ѧ��

//�����x�Ķ��ٴη��������ɱ�target�������, ��������η���������С��

class Solution {
public:
	int leastOpsExpressTarget(int x, int target) {
		vector<int> r;

		while (target > 0)
		{
			r.push_back(target%x);
			target /= x;
		}

		int res = 0;

		for (int i = 1; i < r.size(); ++i)
		{
			if (r[i] <= x / 2) res += 2* r[i];
			else res += 2*(x - r[i]);
		}

		if (r[0] * 2 > (1 + x - r[0])) res += 1 + x - r[0];
		else res += r[0] * 2;
		return res - 1;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->leastOpsExpressTarget(3, 19);
	return 0;
}
