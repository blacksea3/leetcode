#include "public.h"

//
//�ҹ���:
//���ȰѾ��ΰ��ձ߳�sideLength�ֵ�, ������ʣ�¶���
//�ֵ���ÿ��������ʹ��maxOnes��1
//ʣ�µ����þ���
//ע��ʹ�õ�1���λ����һ����

class Solution {
public:
	int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
		int lineNum = height / sideLength;
		int lineRem = height % sideLength;
		int colNum = width / sideLength;
		int colRem = width % sideLength;

		int res = lineNum * colNum*maxOnes;

		//����ʣ��ͼ��: �ұ�: colRem*sideLength, ����:lineRem*sideLength, ���½�:colRem*lineRem
		//Ѱ��һ�����Ĺ���ͼ��

		if (maxOnes <= colRem * lineRem)
		{
			res += (lineNum + colNum + 1)*maxOnes;
		}
		else
		{
			//ѡ��
			res += colRem * lineRem;
			if (lineNum > colNum)
			{
				//�ȷ�����
				if (maxOnes <= colRem * sideLength)
				{
					res += lineNum * (maxOnes);
					res += colNum * colRem * lineRem;
				}
				else
				{
					//����Ҳ�ܷŵ�����
					if (maxOnes <= lineRem * sideLength + colRem * sideLength - colRem * lineRem)
					{
						res += lineNum * colRem * sideLength;
						res += colNum * (maxOnes - colRem * sideLength + colRem * lineRem);
					}
					//���ܷ���
					else
					{
						res += lineNum * colRem * sideLength;
						res += colNum * lineRem* sideLength;
					}
				}
			}
			else
			{
				//�ȷ�����
				if (maxOnes <= lineRem * sideLength)
				{
					res += colNum * (maxOnes);
					res += lineNum * colRem * lineRem;
				}
				else
				{
					//����Ҳ�ܷŵ�����
					if (maxOnes <= lineRem * sideLength + colRem * sideLength - colRem * lineRem)
					{
						res += colNum * lineRem * sideLength;
						res += lineNum * (maxOnes - lineRem * sideLength + colRem * lineRem);
					}
					//���ܷ���
					else
					{
						res += colNum * lineRem * sideLength;
						res += lineNum * colRem * sideLength;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->maximumNumberOfOnes(74, 52, 10, 77) << endl;
	cout << s->maximumNumberOfOnes(10, 10, 4, 5) << endl;
	cout << s->maximumNumberOfOnes(3,3,2,2) << endl;
	return 0;
}
