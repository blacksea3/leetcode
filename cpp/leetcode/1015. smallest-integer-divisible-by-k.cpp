#include "public.h"

//4ms, 91.67%
//��ʽ: ���num%K = x ��ô(num%K)%K = x, ���Խ���num��С; ������num%K = x, ��(10*num % K) + 1= 10*x + 1

class Solution {
public:
	int smallestRepunitDivByK(int K) {
		if (K % 2 == 0 || K % 5 == 0) return -1;
		int cnt = 1, num = 1;
		while (num % K) {
			num = 10 * num + 1;
			num = num % K;
			++cnt;
		}
		return cnt;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->smallestRepunitDivByK(19927) << endl;
	cout << s->smallestRepunitDivByK(9) << endl;
	cout << s->smallestRepunitDivByK(3) << endl;
	cout << s->smallestRepunitDivByK(7) << endl;
	cout << s->smallestRepunitDivByK(11) << endl;
	cout << s->smallestRepunitDivByK(13) << endl;
	cout << s->smallestRepunitDivByK(17) << endl;
	cout << s->smallestRepunitDivByK(19) << endl;
	cout << s->smallestRepunitDivByK(21) << endl;
	cout << s->smallestRepunitDivByK(23) << endl;
	cout << s->smallestRepunitDivByK(19645) << endl;
	return 0;
}
