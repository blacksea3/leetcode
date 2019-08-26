#include "public.h"

//4ms, 78.57%
//先查看X和O的个数, 必须满足:X==O或X==O+1, 不符合则false
//再查看是否O与X同时出现三连
//再查看O或X是否出现不相交三联
//都不符合则为true

//注意如果X三连则X数量应==O+1
//O三联则O数量应==X

class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int numx = 0;
		int numo = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (board[i][j] == 'X') numx++;
				if (board[i][j] == 'O') numo++;
			}

		if (!(numx == numo || numx == (numo + 1))) return false;

		unordered_set<int> locx;
		unordered_set<int> loco;

		//行
		for (int i = 0; i < 3; ++i)
		{
			if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
			{
				locx.insert(10 * i + 0);
				locx.insert(10 * i + 1);
				locx.insert(10 * i + 2);
			}
			if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
			{
				loco.insert(10 * i + 0);
				loco.insert(10 * i + 1);
				loco.insert(10 * i + 2);
			}
		}

		//列
		for (int i = 0; i < 3; ++i)
		{
			if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
			{
				locx.insert(10 * 0 + i);
				locx.insert(10 * 1 + i);
				locx.insert(10 * 2 + i);
			}
			if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
			{
				loco.insert(10 * 0 + i);
				loco.insert(10 * 1 + i);
				loco.insert(10 * 2 + i);
			}
		}

		//对角线
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		{
			locx.insert(10 * 0 + 0);
			locx.insert(10 * 1 + 1);
			locx.insert(10 * 2 + 2);
		}
		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		{
			loco.insert(10 * 0 + 0);
			loco.insert(10 * 1 + 1);
			loco.insert(10 * 2 + 2);
		}
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		{
			locx.insert(10 * 0 + 2);
			locx.insert(10 * 1 + 1);
			locx.insert(10 * 2 + 0);
		}
		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		{
			loco.insert(10 * 0 + 2);
			loco.insert(10 * 1 + 1);
			loco.insert(10 * 2 + 0);
		}

		if (!locx.empty() && !loco.empty()) return false;
		else if (!locx.empty())
		{
			if (numx != (numo + 1)) return false;

			if (locx.size() == 3) return true;
			else if (locx.size() == 5) return true;
			else return false;
		}
		else if (!loco.empty())
		{
			if (numo != (numx)) return false;

			if (loco.size() == 3) return true;
			else if (loco.size() == 5) return true;
			else return false;
		}
		else return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<string> board = { "XXX","OOX","OOX" };
	vector<string> board = { "XOX","OXO","XOX" };
	cout << s->validTicTacToe(board);
	return 0;
}
*/
