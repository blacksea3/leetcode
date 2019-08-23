#include "public.h"

//108ms, 67.78%
//先获取1-5随机数, 再获取1-6随机数以是否大于3决定是否再来一次1-5随机数
// The rand7() API is already defined for you.
/*这是假的rand7()函数*/
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
