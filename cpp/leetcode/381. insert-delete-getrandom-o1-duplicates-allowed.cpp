#include "public.h"

//164ms, 19.42%

//一个unordered_multimap, 一个vector, 这个vector仅仅在尾部进行操作/随机访问

//using std::default_random_engine;
//using std::uniform_int_distribution;

class RandomizedCollection {
private:
	unordered_multimap<int, int> um;
	vector<int> v;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (um.find(val) == um.end())
		{
			um.insert(pair<int, int>{val, v.size()});
			v.push_back(val);
			return true;
		}
		else
		{
			um.insert(pair<int, int>{val, v.size()});
			v.push_back(val);
			return false;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		unordered_multimap<int, int>::iterator iter = um.find(val);
		if (iter != um.end())
		{
			int val_loc = iter->second;
			v[val_loc] = v[v.size() - 1];
			//这里应当精准找键值对, 理论上一定能够找到
			for (unordered_multimap<int, int>::iterator iter2 = um.begin(); iter2 != um.end(); ++iter2)
			{
				if (iter2->first == v[val_loc] && iter2->second == v.size() - 1)
				{
					iter2->second = val_loc;
					break;
				}
			}

			//unordered_multimap<int, int>::iterator iter2 = um.find(v[val_loc]);
			//iter2->second = val_loc;
			um.erase(iter);   //应当erase迭代器!
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
	RandomizedCollection* obj = new RandomizedCollection();
	bool param_1 = obj->insert(10);
	bool param_2 = obj->insert(10);
	bool param_3 = obj->insert(20);
	bool param_4 = obj->insert(20);
	bool param_5 = obj->insert(30);
	bool param_6 = obj->insert(30);
	obj->remove(10);
	obj->remove(10);
	obj->remove(30);
	obj->remove(30);
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	return 0;
}
*/
