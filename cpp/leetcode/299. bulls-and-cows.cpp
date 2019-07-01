#include "public.h"

//4ms, 98.87%
//设置array来存储secret和guess的各个数字数量
//如果secret和guess位置一样数字也一样, 则这次遍历不计入数字数量

class Solution {
public:
	string getHint(string secret, string guess) {
		array<int, 10> s{ 0,0,0,0,0,0,0,0,0,0 };
		array<int, 10> g{ 0,0,0,0,0,0,0,0,0,0 };
		int A = 0;
		int B = 0;

		for (int i = 0; i < secret.size(); ++i)
		{
			if (secret[i] == guess[i]) A++;
			else
			{
				s[secret[i] - '0']++;
				g[guess[i] - '0']++;
			}
		}

		for (int i = 0; i < 10; ++i)
		{
			B += min(s[i], g[i]);
		}

		return to_string(A) + "A" + to_string(B) + "B";
	}
};
