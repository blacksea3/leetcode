#include "public.h"

//
//找规律, 模拟
//最多O(n^2)

class Solution {
private:
	//返回向量(vx, vy)个数，若不能到则-1
	int isOnTheRoad(string command, int vx, int vy, int tarx, int tary)
	{
		//将tarx, tary减去vx 和 vy倍数 直至两个中刚好有一个即将<=0
		int multargetx = tarx / vx;
		int multargety = tary / vy;

		int mint = min(multargety, multargetx);
		int newtarx = tarx - vx * mint;
		int newtary = tary - vy * mint;

		return simIsOnTheRoad(command, newtarx, newtary) ? mint : -1;
	}

	bool simIsOnTheRoad(string command, int tarx, int tary)
	{
		int px = 0;
		int py = 0;

		for (auto& c : command)
		{
			if (c == 'R') px++;
			else py++;
			if ((px == tarx && (py == tary))) return true;
		}
		return false;
	}
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		//先按command模拟, 然后把obstacles转成这些障碍, (x, y)也转过去

		int vx = 0;
		int vy = 0;
		for (auto& c : command)
		{
			if (c == 'R') vx++;
			else vy++;
		}

		int res = isOnTheRoad(command, vx, vy, x, y);

		if (res == -1) return false;
		else
		{
			for (auto& ob : obstacles)
			{
				int temp = isOnTheRoad(command, vx, vy, ob[0], ob[1]);
				if (temp > res || temp == -1) continue;
				else
				{
					if (temp < res) return false;
					else
					{
						if (ob[0] > x || ob[1] > y) continue;
						else if (ob[0] == x && ob[1] == y) continue;
						else return false;
					}
				}
			}
			return true;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> obstacles = { {2,2} };
	cout << s->robot("URR", obstacles,3, 2) << endl;  //0


	vector<vector<int>> obstacles2 = {  };
	cout << s->robot("URR", obstacles2, 3, 2) << endl;  //1

	vector<vector<int>> obstacles3 = { {4,2} };
	cout << s->robot("URR", obstacles3, 3, 2) << endl; //1
	return 0;
}
*/
