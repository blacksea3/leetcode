#include "public.h"

//8ms, 47.56%
/*
//ģ��
//���صķ���,�����ǰƽ�����Ѿ���ʷ�ϴ��ڹ�,��ô���ǿ�����
//�����ǰƽ����Ϊ1���ǿ�����
//����ѭ��

class Solution {
private:
	int getsquaresum_202(int n)
	{
		int res = 0;
		while (n > 0)
		{
			res += (n % 10)*(n % 10);
			n /= 10;
		}
		return res;
	}

public:
	//������������
	bool isHappy(int n) {
		unordered_set<int> his;
		while (true)
		{
			int temp = getsquaresum_202(n);
			if (temp == 1) return true;
			else if (his.find(temp) == his.end()) his.insert(temp);
			else break;
			n = temp;
		}
		return false;
	}
};
*/

//0ms, 100%
//����ָ��, ����������ѭ��

class Solution {
private:
	int getSquareSum(int n)
	{
		int res = 0;
		while (n > 0)
		{
			res += (n % 10)*(n % 10);
			n /= 10;
		}
		return res;
	}
public:
	bool isHappy(int n) {
		int fa = getSquareSum(n);
		int sl = getSquareSum(n);
		sl = getSquareSum(sl);
		while (fa != sl)
		{
			fa = getSquareSum(fa);
			sl = getSquareSum(sl);
			sl = getSquareSum(sl);
		}
		return fa == 1;
	}
};
