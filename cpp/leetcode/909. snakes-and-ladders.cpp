#include "public.h"

//68ms, 5.56%
//BFS搜索, 直到搜到终点
//如果下一个目的地以前走过了那么就不去

class Solution {
private:
	//数字转位置
	vector<int> convert(int raw, int cols)
	{
		raw--;
		vector<int> res(2, 0);
		res[0] = cols - 1 - raw / cols;
		if (cols % 2 == 0)
		{
			if (res[0] % 2 == 0)
			{
				res[1] = cols - raw % cols - 1;
			}
			else
			{
				res[1] = raw % cols;
			}
		}
		else
		{
			if (res[0] % 2 != 0)
			{
				res[1] = cols - raw % cols - 1;
			}
			else
			{
				res[1] = raw % cols;
			}
		}
		return res;
	}

	//位置转数字
	int reconvert(vector<int> v, int cols)
	{
		int r = v[0];
		int c = v[1];
		if (cols % 2 == 0)
		{
			if (r % 2)
			{
				return (cols - r - 1)*cols + c + 1;
			}
			else
			{
				return (cols - r - 1)*cols + (cols - 1 - c) + 1;
			}
		}
		else
		{
			if (!(r % 2))
			{
				return (cols - r - 1)*cols + c + 1;
			}
			else
			{
				return (cols - r - 1)*cols + (cols - 1 - c) + 1;
			}
		}

	}


	//当前位置加1/2/3/4/5/6
	//这里可能会超出行, 但是不要紧, 因为如果超出行, 必然有之前的位置直接指向终点, 直接BFS就结束了
	vector<vector<int>> getnext(int o, int cols)
	{
		vector<vector<int>> res;
		for (int i = 1; i <= 6; ++i)
			res.push_back(convert(o + i, cols));

		return res;
	}

	int res = 0;
	bool isend = false;
	vector<int> BFS(const vector<vector<int>>& board, vector<bool>& searched, vector<int> old)
	{
		res++;
		for (auto& o : old)
		{
			searched[o] = true;
		}
		//研究接下来的多个落脚点
		vector<int> inext;
		for (auto& o : old)
		{
			vector<vector<int>> rawnexts = getnext(o, (int)board[0].size());
			//更改这些值
			for (int i = 0; i < rawnexts.size(); ++i)
			{
				int r = rawnexts[i][0];
				int c = rawnexts[i][1];
				if (r < 0) continue;
				else
				{
					if (board[r][c] == -1)
					{
						int tem = reconvert({ r, c }, (int)board[0].size());
						if (tem == searched.size())
						{
							isend = true;
							return {};
						}
						if (find(inext.begin(), inext.end(), tem) == inext.end() && !searched[tem])
						{
							inext.push_back(tem);
						}
					}
					else
					{
						int tem = board[r][c];
						if (tem == searched.size())
						{
							isend = true;
							return {};
						}
						if (find(inext.begin(), inext.end(), board[r][c]) == inext.end() && !searched[tem])
						{
							inext.push_back(board[r][c]);
						}
					}
				}
			}
		}
		return inext;
	}

public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int sb = board.size();
		vector<bool> searched(sb*sb, false);
		vector<int> o = { 1 };
		while (isend == false)
		{
			if (o.empty()) return -1;
			o = BFS(board, searched, o);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> board1 = { {-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1} };
	//cout <<  s->snakesAndLadders(board1);

	//vector<vector<int>> board2 = { {-1,-1,-1},{-1,9,8},{-1,8,9} };
	//cout << s->snakesAndLadders(board2);

	vector<vector<int>> board3 = { {-1,-1,-1,99,-1,-1,84,-1,-1,98,-1,-1,-1,70,37,-1},{-1,-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,197},{-1,-1,-1,-1,-1,181,-1,-1,-1,-1,-1,-1,170,-1,-1,66},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,152,-1,-1,-1,-1,-1},{214,157,-1,-1,-1,-1,-1,-1,-1,-1,-1,159,-1,-1,-1,123},{56,-1,-1,129,80,-1,93,-1,118,-1,-1,-1,-1,-1,-1,-1},{-1,-1,116,-1,-1,-1,-1,132,-1,-1,189,-1,-1,219,-1,-1},{-1,-1,230,-1,-1,-1,-1,161,217,-1,-1,-1,72,-1,-1,216},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,94},{-1,-1,-1,-1,186,87,-1,33,120,-1,-1,-1,-1,-1,3,130},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,72,129,-1},{99,-1,-1,-1,152,-1,-1,-1,-1,-1,182,228,-1,-1,-1,-1},{256,-1,-1,-1,-1,146,-1,109,-1,-1,-1,-1,37,-1,162,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,34,96,-1,-1,-1,-1,83,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,207,-1,65,148,-1,95,-1,35,-1,-1} };
	cout << s->snakesAndLadders(board3);

	return 0;
}
*/
