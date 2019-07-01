#include "public.h"

//4ms, 92.57%
//ע�⵽����һ��Ԫ����int
//������չintֵ, ��ǿ�д��浱ǰֵ�͸���ֵ
//����: 1:δ�������ĵ�ǰ��ϸ��/��������Ȼ���Ļ�ϸ��
//      2:�����󼴽������Ļ�ϸ��
//      0:δ�������ĵ�ǰ��ϸ��/��������Ȼ������ϸ��
//      -1:�����󼴽��������ϸ��

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		if (!row) return;
		int col = board[0].size();
		if (!col) return;

		//��һ�ֱ���: ����״̬
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				int temp = 0;
				if (r > 0)
				{
					if ((c > 0) && (board[r - 1][c - 1] > 0)) temp++;
					if (board[r - 1][c] > 0) temp++;
					if ((c < col - 1) && (board[r - 1][c + 1] > 0)) temp++;
				}
				if ((c > 0) && (board[r][c - 1] > 0)) temp++;
				if ((c < col - 1) && (board[r][c + 1] > 0)) temp++;
				if (r < row - 1)
				{
					if ((c > 0) && (board[r + 1][c - 1] > 0)) temp++;
					if (board[r + 1][c] > 0) temp++;
					if ((c < col - 1) && (board[r + 1][c + 1] > 0)) temp++;
				}
				if ((board[r][c]) && ((temp < 2) || (temp > 3))) board[r][c] = 2;
				else if ((!board[r][c]) && (temp == 3)) board[r][c] = -1;
			}
		}

		//�ڶ��ֱ���, �ظ�״̬
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				if (board[r][c] == 2) board[r][c] = 0;
				else if (board[r][c] == -1) board[r][c] = 1;
			}
		}
	}
};
