#include "public.h"

//
//̰����ͷ��, α��������

class Solution {
public:
	int balancedString(string s) {
		int sSize = s.size();

		int target = sSize / 4;

		unordered_map<char, int> umleft;

		//��ʼ��, ȫ�����
		int leftIndex = 0;
		int rightIndex = sSize;

		while (leftIndex <= rightIndex)
		{
			if (umleft[s[leftIndex]] == target)
			{
				leftIndex--;
				break;
			}
			else
			{
				umleft[s[leftIndex]]++;
				leftIndex++;
			}
		}
		//�Ҳ�ҲҪ��һ��
		while ((rightIndex - 1) > leftIndex)
		{
			if (umleft[s[rightIndex - 1]] == target)
			{
				break;  //�ұ�[rightIndex, sSize - 1]
			}
			else
			{
				umleft[s[rightIndex - 1]]++;
				rightIndex--;
			}
		}

		if (leftIndex > rightIndex) return 0;
		else //�ڲ�Ѱ��
		{
			int res = rightIndex - leftIndex - 1;  //��ǰ�����ҵ���[0,leftIndex]

			while (leftIndex >= 0)
			{
				//ȥ��һ��leftIndex
				umleft[s[leftIndex]]--;
				leftIndex--;

				//�ұ���
				while ((rightIndex - 1) > leftIndex) //�ٵ�����
				{
					if (umleft[s[rightIndex - 1]] == target)
					{
						break;  //�ұ�[rightIndex, sSize - 1]
					}
					else
					{
						umleft[s[rightIndex - 1]]++;
						rightIndex--;
					}
				}
				res = min(res, rightIndex - leftIndex - 1);
			}
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->balancedString("RWQWRQEQQWQWQQRWRRRWEEEWQWREWQWRRQQWRQREQWRWRQREWRRWREEQERRERRRQEERRWQRQQQEQ") << endl;  //11

	cout << s->balancedString("QWER") << endl; //0
	cout << s->balancedString("QQQW") << endl; //2
	cout << s->balancedString("QQQQ") << endl; //3
	return 0;
}
*/
