#include "public.h"

//
//贪心两头找, 伪滑动窗口

class Solution {
public:
	int balancedString(string s) {
		int sSize = s.size();

		int target = sSize / 4;

		unordered_map<char, int> umleft;

		//初始化, 全部左侧
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
		//右侧也要加一段
		while ((rightIndex - 1) > leftIndex)
		{
			if (umleft[s[rightIndex - 1]] == target)
			{
				break;  //右边[rightIndex, sSize - 1]
			}
			else
			{
				umleft[s[rightIndex - 1]]++;
				rightIndex--;
			}
		}

		if (leftIndex > rightIndex) return 0;
		else //内部寻找
		{
			int res = rightIndex - leftIndex - 1;  //当前仅仅找到了[0,leftIndex]

			while (leftIndex >= 0)
			{
				//去掉一个leftIndex
				umleft[s[leftIndex]]--;
				leftIndex--;

				//右边找
				while ((rightIndex - 1) > leftIndex) //假的条件
				{
					if (umleft[s[rightIndex - 1]] == target)
					{
						break;  //右边[rightIndex, sSize - 1]
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
