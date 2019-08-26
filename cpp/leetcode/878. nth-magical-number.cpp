#include "public.h"

//8ms, 36.73%
//����: ����X%A==0����X%B==0��ôX+AB����С������һ��==0
//����С������Ϊ��׼, ��ÿ�� n*��С��������-n+1��С������֮��, �������ֵ��������λ����һ����

class Solution {
private:
	//շת���
	int gcd(int x, int y)
	{
		if (!y)
			return x;
		else
			return gcd(y, x%y);
	}

public:
	int nthMagicalNumber(int N, int A, int B) {
		vector<int> onetimevals;
		int max_pubmul = gcd(A, B);
		long long min_pubsam = A * B / max_pubmul;

		int loc1 = 1;
		int loc2 = 1;
		int preval = 0;

		while (preval < min_pubsam)
		{
			int va1 = loc1 * A;
			int va2 = loc2 * B;
			if (va1 < va2)
			{
				preval = va1;
				loc1++;
			}
			else if (va1 > va2)
			{
				preval = va2;
				loc2++;
			}
			else
			{
				preval = va1;
				loc1++;
				loc2++;
			}
			onetimevals.push_back(preval);
		}

		long long multimes = N / onetimevals.size();
		long long remain = N % onetimevals.size();

		long long res = (remain != 0) ? multimes * min_pubsam + onetimevals[remain-1] : multimes * min_pubsam;
		res %= 1000000007;
		return (int)res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->nthMagicalNumber(1, 2, 3) << endl;
	cout << s->nthMagicalNumber(4, 2, 3) << endl;
	cout << s->nthMagicalNumber(5, 2, 4) << endl;
	cout << s->nthMagicalNumber(3, 6, 4) << endl;
	cout << s->nthMagicalNumber(1000000000, 40000, 40000) << endl;
	return 0;
}
