#include "public.h"

//136ms, 83.45%
//模拟
//统计obstacles, 然后每次到终点时看一下是不是障碍物即可
//一步一步挪过去

class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		unordered_map<int, set<int>> um;

		for (auto& o : obstacles)
			um[o[1]].insert(o[0]);


		//模拟
		int res = 0;
		int predir = 0; //0:北, 1东, 2南, 3西    
		int loc = 0;
		int prer = 0;
		int prec = 0;
		while (loc < commands.size())
		{
			if (commands[loc] == -1)
			{
				predir += ((predir == 3) ? -3 : 1);
			}
			else if (commands[loc] == -2)
			{
				predir -= ((predir == 0) ? -3 : 1);
			}
			else
			{
				int c = commands[loc];
				while (c--)
				{

					//查找是否有障碍物
					switch (predir)
					{
					case 0:
					{
						prer++;
						if (um[prer].count(prec) == 1) prer--;
						break;
					}
					case 1:
					{
						prec++;
						if (um[prer].count(prec) == 1) prec--;
						break;
					}
					case 2:
					{
						prer--;
						if (um[prer].count(prec) == 1) prer++;
						break;
					}
					case 3:
					{
						prec--;
						if (um[prer].count(prec) == 1) prec++;
						break;
					}
					default:
					{
						break;
					}
					}
				}
			}
			res = max(res, prer*prer + prec * prec);
			loc++;
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> commands = { 4,-1,4,-2,4 }; 
	vector<vector<int>> obstacles = { {2,4} };
	//vector<int> commands = { -2,8,3,7,-1 };
	//vector<vector<int>> obstacles = { {-4,-1},{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3} };
	cout << s->robotSim(commands, obstacles);
	return 0;
}
