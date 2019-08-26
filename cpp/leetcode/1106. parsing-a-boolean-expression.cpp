#include "public.h"

//12ms, 79.50%
//easy solution, but code is difficult
//DFS, recursive

class Solution {
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
};
