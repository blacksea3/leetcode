#include "public.h"

class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		vector<int> res;
		while (label > 1)
		{
			res.insert(res.begin(), label);
			label /= 2;
		}
		res.insert(res.begin(), 1);

		if (res.size() % 2)
		{
			for (int i = 1; i < res.size(); i += 2)
			{
				res[i] = (int)pow(2, i + 1) - 1 + (int)pow(2, i) - res[i];
			}
		}
		else
		{
			for (int i = 0; i < res.size(); i += 2)
			{
				res[i] = (int)pow(2, i + 1) - 1 + (int)pow(2, i) - res[i];
			}
		}
		return res;
	}

private:
	//outerfun:0 |, 1: &, 2:!
	pair<bool, int> recu_pB(const string& expression, int startloc, int outerfun)
	{
		bool isfirstres = true;
		bool waitlet = false;
		bool res;


		while (startloc < expression.size())
		{
			if (isfirstres)
			{
				if (expression[startloc] == 't')
				{
					res = true;
					startloc++; //maybe , or )
				}
				else if (expression[startloc] == 'f')
				{
					res = false;
					startloc++; //maybe , or )
				}
				else if (expression[startloc] == '|')
				{
					pair<bool, int> temp = recu_pB(expression, startloc + 2, 0);
					res = temp.first;
					startloc = temp.second; //maybe , or )
				}
				else if (expression[startloc] == '&')
				{
					pair<bool, int> temp = recu_pB(expression, startloc + 2, 1);
					res = temp.first;
					startloc = temp.second; //maybe , or )
				}
				else
				{
					pair<bool, int> temp = recu_pB(expression, startloc + 2, 2);
					res = temp.first;
					startloc = temp.second; //maybe , or )
				}
				isfirstres = false;
				waitlet = false;
			}
			else
			{
				if (!waitlet)
				{
					if (expression[startloc] == ',')
					{
						startloc++;
						waitlet = true;
					}
					else
					{
						pair<bool, int> returns;
						if (outerfun == 2)
						{
							returns.first = !res;
							returns.second = startloc + 1;
						}
						else
						{
							returns.first = res;
							returns.second = startloc + 1;
						}
						return returns;
					}
				}
				else
				{
					if (expression[startloc] == 't')
					{
						if (outerfun == 0)
						{
							res = true;
							startloc++;
						}
						else
						{
							res = res;
							startloc++;
						}
					}
					else if (expression[startloc] == 'f')
					{
						if (outerfun == 0)
						{
							res = res;
							startloc++;
						}
						else
						{
							res = false;
							startloc++;
						}
					}
					else
					{
						bool innerval;
						if (expression[startloc] == '|')
						{
							pair<bool, int> temp = recu_pB(expression, startloc + 2, 0);
							innerval = temp.first;
							startloc = temp.second; //maybe , or )
						}
						else if (expression[startloc] == '&')
						{
							pair<bool, int> temp = recu_pB(expression, startloc + 2, 1);
							innerval = temp.first;
							startloc = temp.second; //maybe , or )
						}
						else
						{
							pair<bool, int> temp = recu_pB(expression, startloc + 2, 2);
							innerval = temp.first;
							startloc = temp.second; //maybe , or )
						}
						if (outerfun == 0)
						{
							res = res || innerval;
						}
						else
						{
							res = res && innerval;
						}
					}
					waitlet = false;
				}
			}
		}

		pair<bool, int> returns;
		if (outerfun == 2)
		{
			returns.first = !res;
			returns.second = startloc + 1;
		}
		else
		{
			returns.first = res;
			returns.second = startloc + 1;
		}
		return returns;
	}

public:
	bool parseBoolExpr(string expression) {
		return !(recu_pB(expression, 0, 2).first);
	}



public:
	vector<int> distributeCandies(int candies, int num_people) {
		double timemax = (-1 + sqrt(1 + 8 * (long)candies)) / 2;
		double timemin = (-3 + sqrt(1 + 8 * (long)candies)) / 2;

		vector<int> res(num_people, 0);

		if ((int)timemax == timemax)
		{
			//公共部分
			int x = timemax / num_people;

			for (int i = 0; i < num_people; ++i)
			{
				res[i] = (x - 1)*x / 2 * num_people + x * (i + 1);
			}

			int remain = candies - (x*x*num_people*num_people + x * num_people) / 2;

			//私有部分
			for (int i = 0; remain > 0; ++i)
			{
				if (i == res.size())
				{
					i = 0;
					x++;
				}
				res[i] += x * num_people + i + 1;
				remain -= (x * num_people + i + 1);
			}
		}
		else
		{
			//公共部分
			int x = (int)timemin / num_people;

			for (int i = 0; i < num_people; ++i)
			{
				res[i] = (x - 1)*x / 2 * num_people + x * (i + 1);
			}

			int remain = candies - (x*x*num_people*num_people + x * num_people) / 2;

			//私有部分
			for (int i = 0; remain > 0; ++i)
			{
				if (i == res.size())
				{
					i = 0;
					x++;
				}
				res[i] += min(x * num_people + i + 1, remain);
				remain -= min(x * num_people + i + 1, remain);
			}
		}
		return res;
	}

//超出时间限制
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		//如果比当前高，考虑当前和新建

		vector<vector<int>> res;  //记录: 历史高度，当前高度，当前使用长度

		res.push_back({ 0, books[0][1], books[0][0] });

		for (int i = 1; i < books.size(); ++i)
		{
			int rsize = res.size();
			for (int j = 0; j < rsize; ++j)
			{
				if ((shelf_width - res[j][2]) < books[i][0])
				{
					res[j][0] = res[j][0] + res[j][1];
					res[j][1] = books[i][1];
					res[j][2] = books[i][0];
				}
				else
				{
					if (res[j][1] < books[i][1])
					{
						vector<int> temp(3, 0);
						temp[0] = res[j][0] + res[j][1];
						temp[1] = books[i][1];
						temp[2] = books[i][0];
						res.push_back(temp);
						res[j][1] = books[i][1];
						res[j][2] += books[i][0];
					}
					else
					{
						res[j][2] += books[i][0];
					}
				}
			}
		}

		int minres = INT_MAX;
		for (auto& v : res)
		{
			minres = min(minres, v[0] + v[1]);
		}
		return minres;
	}


};

int main()
{
	Solution* s = new Solution();
	//vector<int> res = s->distributeCandies(10, 3);
	//vector<int> res = s->distributeCandies(80, 4);
	//vector<int> res = s->distributeCandies(1000000000, 1000);
		
	vector<vector<int>> sh = { {1, 1},{2, 3},{2, 3},{1, 1},{1, 1},{1, 1},{1, 2} };
	cout << s->minHeightShelves(sh, 4);
	return 0;
}