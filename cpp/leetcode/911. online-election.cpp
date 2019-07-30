#include "public.h"

//456ms, 51.72%
//在线生成数据

class TopVotedCandidate {
private:
	unordered_map<int, int> um;
	vector<int> res;
	vector<int> cptimes;

public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		res.resize(times.size());
		cptimes.resize(times.size());
		for (int i = 0; i < times.size(); ++i)
		{
			cptimes[times.size() - i - 1] = -1 * times[i];
		}
		int premax = 0;
		int oldp = 0;
		for (int i = 0; i < persons.size(); i++)
		{
			int p = persons[i];
			um[p]++;
			if (um[p] >= premax)
			{
				oldp = p;
				premax = um[p];
			}
			res[i] = oldp;
		}
	}

	int q(int t) {
		//二分查找
		//目标:想要找最大的cptimes<t的
		//那么都乘以-1, 想要找最小的cptimes > t的 ojbk
		vector<int>::iterator iter = lower_bound(cptimes.begin(), cptimes.end(), -1*t);
		int fuckabs = (iter - cptimes.begin());
		
		int abs = (int)cptimes.size() - 1 - (iter - cptimes.begin());
		return res[abs];
	}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main()
{
	/*
	vector<int> persons = { 0,1,1,0,0,1,0 };
	vector<int> times = { 0,5,10,15,20,25,30 };
	TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
	cout << obj->q(3);
	cout << obj->q(12);
	cout << obj->q(25);
	cout << obj->q(15);
	cout << obj->q(24);
	cout << obj->q(8);
	*/

	vector<int> persons = { 0, 1, 0, 1, 1 };
	vector<int> times = { 24, 29, 31, 76, 81 };
	TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
	cout << obj->q(28);
	cout << obj->q(24);
	cout << obj->q(29);
	cout << obj->q(77);
	cout << obj->q(30);
	cout << obj->q(25);
	cout << obj->q(76);
	cout << obj->q(75);
	cout << obj->q(81);
	cout << obj->q(80);
	return 0;
}
