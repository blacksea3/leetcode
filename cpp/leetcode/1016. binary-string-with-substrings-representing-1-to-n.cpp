#include "public.h"

//4ms, 93.39%
//������Ӵ���������...

class Solution {
private:
	//Ĭ��������
	string dec2bin(int decVal)
	{
		string value = "";
		while (decVal > 0)
		{
			if (decVal % 2)
				value = '1' + value;
			else
				value = '0' + value;
			decVal = decVal / 2;
		}
		return value;
	}

public:
	bool queryString(string S, int N) {
		if (N >= 2048) return false; //����������������1024��ͬ���ĳ���, ��ͬ���ݵĶ������ַ���, �ⲻ������S�г���
		else
		{
			//ֱ�ӱ���
			for (int i = 1; i <= N; ++i)
				if (S.find(dec2bin(i)) == S.npos) return false;
			return true;
		}
	}
};