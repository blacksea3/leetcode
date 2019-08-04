#include "public.h"

//4ms, 97.97%
//����������е�һ�ַ���, ��Ϊtrue: 1:���ַ���һ�������ظ��ַ�, 2:���ַ���������һ��λ�ò�һ��, �������ַ��ǻ���һ����

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) return false;
		else if (A == B)
		{
			//�ж�
			if (A.size() > 26) return true;
			else
			{
				unordered_set<int> us;
				for (auto& a : A)
				{
					if (us.find(a) == us.end()) us.insert(a);
					else return true;
				}
				return false;
			}
		}
		else
		{
			//�𲽲�
			char cha = '-';
			char chb = '-';
			bool isswaped = false;
			for (int i = 0; i < A.size(); ++i)
			{
				if (A[i] == B[i]) continue;
				else if (cha == '-')
				{
					cha = A[i];
					chb = B[i];
				}
				else if (!isswaped)
				{
					if (A[i] == chb && B[i] == cha) isswaped = true;
					else return false;
				}
				else return false;
			}
			return isswaped;
		}
	}
};
