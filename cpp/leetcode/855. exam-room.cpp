#include "public.h"

//40ms, 100%
//链表, 我用vector模拟

class ExamRoom {
private:
	vector<int> v;
	int gblN;

public:
	ExamRoom(int N) {
		gblN = N;
	}

	int seat() {
		if (v.size() == 0)
		{
			v.push_back(0);
			return 0;
		}
		else
		{
			int insertv;
			int insertloc;
			int maxdis = INT_MIN;
			if (v[0] != 0)
			{
				insertloc = 0;
				insertv = 0;
				maxdis = v[0];
			}
			for (int i = 0; i < (int)v.size() - 1; ++i)
			{
				if ((v[i + 1] - v[i]) / 2 > maxdis)
				{
					maxdis = (v[i + 1] - v[i]) / 2;
					insertloc = i + 1;
					insertv = (v[i + 1] + v[i]) / 2;
				}
			}


			if ((v[v.size() - 1] != (gblN - 1)) && ((gblN - 1 - v[v.size() - 1]) > maxdis))
			{
				insertloc = v.size();
				insertv = gblN - 1;
				//maxdis = gblN - 1 - v[v.size() - 1];
			}

			if (insertloc == v.size()) v.push_back(insertv);
			else v.insert(v.begin() + insertloc, insertv);
			return insertv;
		}
	}

	void leave(int p) {
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == p)
			{
				v.erase(v.begin() + i);
				break;
			}
		}
	}
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main()
{
	ExamRoom* obj = new ExamRoom(10);
	cout << obj->seat();
	cout << obj->seat();
	cout << obj->seat();
	cout << obj->seat();
	obj->leave(4);
	cout << obj->seat();
	return 0;
}
