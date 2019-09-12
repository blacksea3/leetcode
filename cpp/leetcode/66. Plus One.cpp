#include "public.h"

//4ms, 88.90%
//模拟, 按要求加1, 注意进位标记, 直接原位操作digits
//注意: 如果digits大小将加一, 表示除最高位外其它位都是0, 那么可以不用开头insert
//改用push_back + 开头0改成1

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool isCarry = true;

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (++digits[i] == 10) digits[i] = 0;
			else return digits;
		}
		digits.emplace_back(0);
		digits[0] = 1;
		return digits;
	}
};
