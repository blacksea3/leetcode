#include "public.h"

//12ms, 77.08%
//��������Xʱֻ��Ҫ�ж����������Ƿ�ͬʱ����X, �ǵĻ����Ϊ�µ�ս��(�����Ͻǲ���), ����������������

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		if (board.size() == 0) return 0;
		int res = 0;

		//cols = 0���赥���ж�
		for (int row = 0; row < board.size(); ++row)
		{
			for (int col = 0; col < board[0].size(); ++col)
			{
				if ((board[row][col] == 'X') && ((row == 0) || ((row > 0) && (board[row - 1][col] == '.'))) && ((col == 0) || ((col > 0) && (board[row][col - 1] == '.')))) res++;
			}
		}
		return res;
	}
};


