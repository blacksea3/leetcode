#include "public.h"

//0ms, 100%
//ʮ����, int���ĸ�λΪ��, ��λΪ����

class Solution {
private:
	int n;

	//����: prefix: ��ǰ׺: ���Ӹ�������ǰ�ڵ�(��ǰ���ڵ�)��ֵ
	//�����Ե�ǰ���ڵ�Ϊ����ʮ�����Ľڵ�����
	//һ������´���������1/11/111...��
	int getNumOfNodes(int prefix)
	{
		int count = 0;
		for (long long cur = prefix, next = prefix + 1; cur <= this->n; cur *= 10, next *= 10)
			count += min(next, (long long)this->n + 1) - cur;
		return count;
	}

public:
	int findKthNumber(int n, int k) {
		this->n = n;
		int p = 1;
		int prefix = 1;
		while (p < k)
		{
			int count = getNumOfNodes(prefix);
			if ((p + count) > k)   //�ֵ����k�����ڵ�ǰǰ׺��
			{
				prefix *= 10;
				p++;
			}
			else //�ֵ����k�������ڵ�ǰǰ׺��, ��Ӧ�����ӵ�ǰǰ׺
			{
				prefix++;
				p += count;
			}
		}
		return prefix;
	}
};
