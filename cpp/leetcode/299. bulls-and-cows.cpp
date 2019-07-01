#include "public.h"

//4ms, 98.87%
//����array���洢secret��guess�ĸ�����������
//���secret��guessλ��һ������Ҳһ��, ����α�����������������

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
