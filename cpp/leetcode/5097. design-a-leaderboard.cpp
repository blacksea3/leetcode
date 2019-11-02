#include "public.h"

//
//±©Á¦

class Leaderboard {
private:
	unordered_map<int, int> um;
	multiset<int, greater<int>> ms;

public:
	Leaderboard() {
		;
	}

	void addScore(int playerId, int score) {
		if (um.find(playerId) == um.end())
		{
			um[playerId] = score;
			ms.insert(score);
		}
		else
		{
			ms.erase(ms.find(um[playerId]));
			um[playerId] += score;
			ms.insert(um[playerId]);
		}
	}

	int top(int K) {
		int res = 0;
		multiset<int, greater<int>>::iterator iter = ms.begin();
		for (int i = 0; i < K; ++i)
		{
			res += *(iter);
			iter++;
		}
		return res;
	}

	void reset(int playerId) {
		ms.erase(ms.find(um[playerId]));
		um.erase(playerId);
	}
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

/*
int main()
{
	Leaderboard* obj = new Leaderboard();
	obj->addScore(1, 73);
	cout << obj->top(1) << endl;
	obj->reset(1);
}
*/
