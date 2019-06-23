#include "public.h"

//ģ��, 4ms, 96.12%

class Solution {
private:
	//������������
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
		//���صķ���,�����ǰƽ�����Ѿ���ʷ�ϴ��ڹ�,��ô���ǿ�����
		//�����ǰƽ����Ϊ1���ǿ�����
		//����ѭ��
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

