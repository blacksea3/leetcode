#include "public.h"

//108ms, 67.78%
//�Ȼ�ȡ1-5�����, �ٻ�ȡ1-6��������Ƿ����3�����Ƿ�����һ��1-5�����
// The rand7() API is already defined for you.
/*���Ǽٵ�rand7()����*/
int rand7()
{
	return 1;
}
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {
		int firstNum = 10;
		while (firstNum > 5) firstNum = rand7();

		int secondNum = 7;
		while (secondNum > 6) secondNum = rand7();

		if (secondNum > 3)
		{
			return firstNum + 5;
		}
		else
		{
			return firstNum;
		}
	}
};
