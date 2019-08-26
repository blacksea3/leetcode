#include "public.h"

//40ms, 28.75%
//̰��
//���������ķ�Χ: ����num.size() = 5, k=2, ���һ������loc���������ķ�Χ��0,1,2,3
//�����������ķ�Χ������������loc: num[loc+1] < num[loc], ��������, ��ɾ�����������ķ�Χ������loc

class Solution {
public:
	string removeKdigits(string num, int k) {

		//̰��
		//ע�⵽nums.size() >= k
		//������O(n^2)

		while (k > 0)
		{
			//Ѱ��
			int loc;
			for (loc = 0; loc <= num.size() - k - 1; ++loc)
			{
				if (num[loc + 1] < num[loc]) break;
			}

			//ɾȥ
			num.erase(num.begin() + loc);
			k--;
		}

		int begin = 0;
		while (begin < num.size() && num[begin] == '0') begin++;
		return num.substr(begin) == "" ? "0" : num.substr(begin);
	}
};
