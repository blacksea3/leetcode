#include "public.h"

//动态规划
//对单独一个人操作

class Solution {
public:
	int numberOfWays(int num_people) {
		vector<long long> memory(1);
		memory[0] = 1;

		for (int i = 4; i <= num_people; i += 2)
		{
			long long pre = 0;
			//st = 0;
			for (int en = 1; en < i; en += 2)
			{
				if (en == 1 || en == i - 1)
				{
					pre += memory.back();
				}
				else
				{
					pre += memory[en / 2 - 1] * memory[(i - en) / 2 - 1];
					pre %= 1000000007;
				}
			}
			memory.push_back(pre % 1000000007);
		}
		return memory.back() % 1000000007;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->numberOfWays(140) << endl;
	cout << s->numberOfWays(2) << endl;
	cout << s->numberOfWays(4) << endl;
	cout << s->numberOfWays(6) << endl;
	cout << s->numberOfWays(8) << endl;
	return 0;
}

*/