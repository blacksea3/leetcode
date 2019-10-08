#include "public.h"

//68ms, 82.47%
//先按照map处理, 双map
//O(logn)

class AllOne {
private:
	map<string, int> msi;
	map<int, unordered_set<string>> mis;
public:
	/** Initialize your data structure here. */
	AllOne() {
		;
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (msi.find(key) == msi.end())
		{
			msi[key] = 1;
			mis[1].insert(key);
		}
		else
		{
			int temp = msi[key];
			mis[temp].erase(key);
			if (mis[temp].empty()) mis.erase(temp);
			mis[temp + 1].insert(key);
			msi[key]++;
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (msi.find(key) == msi.end())
		{
			;
		}
		else if (msi[key] == 1)
		{
			msi.erase(key);
			mis[1].erase(key);
			if (mis[1].empty()) mis.erase(1);
		}
		else
		{
			int temp = msi[key];
			mis[temp].erase(key);
			if (mis[temp].empty()) mis.erase(temp);
			mis[temp - 1].insert(key);
			msi[key]--;
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (msi.empty()) return "";
		else
		{
			return *(mis.rbegin()->second).begin();
		}
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (msi.empty()) return "";
		else
		{
			return *(mis.begin()->second).begin();
		}
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
