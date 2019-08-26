#include "public.h"

//136ms, 10.00%
//����λ������, ͬʱ��¼������ʻ���յ�ĺ�ʱ, �����ǰ����target��Զ�ĳ���ʱ�, ��ô����һ������, ������һ������ǰ��ϲ�

class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		map<int, double> pos_time;
		multiset<double, greater<double>> ms;
		for (int i = 0; i < position.size(); ++i)
		{
			pos_time[position[i]] = (target - position[i]) / (double)speed[i];
			ms.insert((target - position[i]) / (double)speed[i]);
		}

		int res = 0;
		for (auto& p : pos_time)
		{
			if (ms.count(*ms.begin()) > 1) ms.erase(ms.find(p.second));
			else if (p.second == *ms.begin())
			{
				ms.erase(ms.begin());
				res++;
			}
			else
			{
				ms.erase(ms.find(p.second));
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> position = {2, 4};
	//vector<int> speed = {3, 2};
	//cout << s->carFleet(10, position, speed);
	//vector<int> position = { 4, 6 };
	//vector<int> speed = { 3, 2 };
	//cout << s->carFleet(10, position, speed);
	vector<int> position = { 0, 4, 2 };
	vector<int> speed = { 2, 1, 3 };
	cout << s->carFleet(10, position, speed);
	return 0;
}
*/
