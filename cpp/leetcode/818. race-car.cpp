#include "public.h"

//8ms, 78.05%
//����dp
//�ο�
//https://blog.csdn.net/lemonmillie/article/details/88926645
//������Ǹպõ�λ��, ��ô�ͷ�Ϊ����ʻ�㹻�����뵫��������ǰt, Ȼ��ö�ٷ��ؾ���, �������ǿ��Ը���ʣ��Ӧ����ʻ����ó��˴�dp��ֵ
//�ֻ���, ���ǿ�������ʻ����t�ľ���, Ȼ�����ǿ��Ը���Ӧ�õķ�����ʻ����ó��˴�dp��ֵ
//����Ŀ�ı߽�����ʵ����̫������

class Solution {
public:
	int dp[10001];

	int racecar(int t) {
		if (dp[t] > 0) return dp[t];
		int n = floor(log2(t)) + 1, res;
		if (1 << n == t + 1) dp[t] = n;
		else {
			dp[t] = racecar((1 << n) - 1 - t) + n + 1;
			for (int m = 0; m < n - 1; ++m)
				dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
		}
		return dp[t];
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->racecar(7) << endl;
	//cout << s->racecar(3) << endl;
	//cout << s->racecar(6) << endl;
	//cout << s->racecar(5) << endl;
	return 0;
}
