#include "public.h"

//4ms, 86.36%
//���ĸ������ƶ�

class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		//��ȡ��λ��
		int r, c;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				if (board[i][j] == 'R')
				{
					r = i;
					c = j;
					break;
				}

		//����������
		int res = 0;
		int cpr = r;
		int cpc = c;
		while (cpr > 0)
		{
			if (board[cpr - 1][cpc] == 'B') break;
			else if (board[cpr - 1][cpc] == 'p')
			{
				res++;
				break;
			}
			cpr--;
		}

		cpr = r;
		cpc = c;
		while (cpc > 0)
		{
			if (board[cpr][cpc - 1] == 'B') break;
			else if (board[cpr][cpc - 1] == 'p')
			{
				res++;
				break;
			}
			cpc--;
		}

		cpr = r;
		cpc = c;
		while (cpr < 7)
		{
			if (board[cpr + 1][cpc] == 'B') break;
			else if (board[cpr + 1][cpc] == 'p')
			{
				res++;
				break;
			}
			cpr++;
		}

		cpr = r;
		cpc = c;
		while (cpc < 7)
		{
			if (board[cpr][cpc + 1] == 'B') break;
			else if (board[cpr][cpc + 1] == 'p')
			{
				res++;
				break;
			}
			cpc++;
		}

		return res;
	}
};

