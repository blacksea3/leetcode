#include "public.h"

//0ms, 100%
//���dp, �˴�dp�Ǻ���
//dp[i, target]: Ŀ����target, ����� i ��ʾ�������ڿ���ʹ�� x^i ���ı�Ŀ��ֵ��ʹԭ���� target ������һ���µ����ܱ� x^i ������Ŀ��ֵ��
//������dp����ʵ����: �������: ����ײ�i=0��ʼ
//ע����ײ�i=0ʱ, ʵ��1��Ҫ������x�����ֵ
//���ݹ�ʱ, �ϲ�ʵ��1(��ʵ��x��ĳ���������η�)ֻ��Ҫ��xĳ���η�����

class Solution {
private:
	unordered_map<string, int> um;
	int gblx;

	int dp(int i, int target)
	{
		string code = "" + to_string(i) + "#" + to_string(target);
		if (um.find(code) != um.end()) return um[code];

		int res;
		if (target == 0) res = 0;
		else if (target == 1) res = cost(i);
		else if (i >= 36) res = target + 1;     //������Ϊ��ǿ��ֹͣ�ݹ�: ע�⵽���Բ�������x�ľ޴�η�, ��������
		else
		{
			int t = target / gblx;
			int r = target % gblx;
			res = min(r * cost(i) + dp(i + 1, t), (gblx - r) * cost(i) + dp(i + 1, t + 1));  //�����t+1��ʵ����t��gblx��ĳ���η�, �����൱�ڽ�ά����
		}

		um[code] = res;
		return res;
	}

	int cost(int x)
	{
		return (x > 0) ? x : 2;
	}

public:
	int leastOpsExpressTarget(int x, int target) {
		gblx = x;
		return dp(0, target) - 1;
	}
};

