#include "public.h"

//76ms, 87.52%
//一个unordered_map, 一个vector, 这个vector仅仅在尾部进行操作/随机访问

//using std::default_random_engine;
//using std::uniform_int_distribution;

class RandomizedSet {
private:
	unordered_map<int, int> um;
	vector<int> v;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (um.find(val) == um.end())
		{
			um.insert(pair<int, int>{val, v.size()});
			v.push_back(val);
			return true;
		}
		else return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (um.find(val) != um.end())
		{
			int val_loc = um[val];
			v[val_loc] = v[v.size() - 1];
			um[v[val_loc]] = val_loc;
			um.erase(val);
			v.pop_back();
			return true;
		}
		else return false;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int temp = rand() % v.size();
		return v[temp];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
int main()
{
	RandomizedSet* obj = new RandomizedSet();
	bool param_1 = obj->insert(1);
	bool param_2 = obj->insert(10);
	bool param_3 = obj->insert(20);
	bool param_4 = obj->insert(30);
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	return 0;
}
*/
