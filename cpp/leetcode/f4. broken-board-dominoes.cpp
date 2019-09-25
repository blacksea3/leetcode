#include "public.h"

//
//按行填充, 贪婪, 半回溯

class Solution {
private:
	int realres = 0;

	//输入上一行填充状态和当前行障碍物, obstacles true是填充了
	//返回当前行填充状态, true填充了, false未填充(有多种); 以及现在额外填充了几组
	pair<vector<vector<bool>>, int> fill_line(vector<bool> lastline, vector<bool> obstacles)
	{
		vector<bool> pre = obstacles;
		int count = 0;
		int totalcol = lastline.size();

		for (int col = 0; col < totalcol; ++col)
		{
			if ((!lastline[col]) && (!pre[col]))
			{
				count++;
				pre[col] = true;
			}
		}

		//再填充
		int preempty = 0;
		vector<vector<bool>> nextline;
		nextline.emplace_back(pre);
		for (int col = 0; col < totalcol; ++col)
		{
			if (pre[col])
			{
				if (preempty == 0) continue;
				else
				{
					//给所有nextline都操作一番
					if (preempty % 2 == 0)
					{
						for (auto& n : nextline)
						{
							for (int leftcol = col - preempty; leftcol < col; ++leftcol)
							{
								n[leftcol] = true;
							}
						}
						count += preempty / 2;
					}
					else
					{
						vector<vector<bool>> tempnextline;
						//翻多倍
						int tempcount = preempty / 2;
						for (auto& n : nextline)
						{
							for (int i = 0; i <= tempcount; ++i)
							{
								vector<bool> tempn = n;
								int fillc = 0;
								bool isemptyed = false;
								for (int leftcol = col - preempty; leftcol < col; ++leftcol)
								{
									if (!isemptyed && (fillc % 2 == 0) && (fillc / 2 == i))
									{
										isemptyed = true;
										continue;
									}
									else
									{
										fillc++;
										tempn[leftcol] = true;
									}
								}
								tempnextline.emplace_back(tempn);
							}
						}
						nextline = tempnextline;
						count += preempty / 2;
					}
					preempty = 0;
				}
			}
			else
			{
				preempty++;
			}
		}

		if (preempty == 0) return pair<vector<vector<bool>>, int>{nextline, count};
		else
		{
			//给所有nextline都操作一番
			if (preempty % 2 == 0)
			{
				for (auto& n : nextline)
				{
					for (int leftcol = totalcol - preempty; leftcol < totalcol; ++leftcol)
					{
						n[leftcol] = true;
					}
				}
				count += preempty / 2;
			}
			else
			{
				vector<vector<bool>> tempnextline;
				//翻多倍
				int tempcount = preempty / 2;
				for (auto& n : nextline)
				{
					for (int i = 0; i <= tempcount; ++i)
					{
						vector<bool> tempn = n;
						int fillc = 0;
						bool isemptyed = false;
						for (int leftcol = totalcol - preempty; leftcol < totalcol; ++leftcol)
						{
							if (!isemptyed && (fillc % 2 == 0) && (fillc / 2 == i))
							{
								isemptyed = true;
								continue;
							}
							else
							{
								fillc++;
								tempn[leftcol] = true;
							}
						}
						tempnextline.emplace_back(tempn);
					}
				}
				nextline = tempnextline;
				count += preempty / 2;
			}
			preempty = 0;
			return pair<vector<vector<bool>>, int>{nextline, count};
		}
	}

	void DFS(int lastres, int line, vector<bool> lastline, vector<vector<bool>>& ob)
	{
		if (line == ob.size())
		{
			realres = max(realres, lastres);
		}
		else
		{
			pair<vector<vector<bool>>, int> temp = fill_line(lastline, ob[line]);
			//lastres += temp.second;
			for (auto& nextl : temp.first)
			{
				DFS(lastres + temp.second, line + 1, nextl, ob);
			}
		}
	}

public:
	int domino(int n, int m, vector<vector<int>>& broken) {
		int res = 0;
		realres = 0;

		vector<vector<bool>> ob(n, vector<bool>(m, false));

		for (auto& iterob : broken)
		{
			ob[iterob[0]][iterob[1]] = true;
		}

		vector<bool> dumpline(m, true);
		DFS(0, 0, dumpline, ob);

		return realres;
	}
};

int main()
{
	Solution* s = new Solution();
	
	/*
	vector<vector<int>> broken = { {1, 0}, {1,1} };
	cout << s->domino(2,3, broken) << endl; //2

	vector<vector<int>> broken2 = {  };
	cout << s->domino(3, 3, broken2) << endl; //4

	vector<vector<int>> broken3 = {  };
	cout << s->domino(8, 3, broken3) << endl; //12
	
	vector<vector<int>> broken4 = {  };
	cout << s->domino(8, 7, broken4) << endl; //28

	vector<vector<int>> broken5 = {  };
	cout << s->domino(8, 8, broken5) << endl; //32
	

	vector<vector<int>> broken6 = { {0, 1}, {0,0} };
	cout << s->domino(2, 8, broken6) << endl; //7

	vector<vector<int>> broken7 = { {0, 2}, {0,3} };
	cout << s->domino(2, 8, broken7) << endl; //7

	*/

	vector<vector<int>> broken8 = { {0, 3}, {1, 5} };
	cout << s->domino(2, 7, broken8) << endl; //6


	return 0;
}

