#include "public.h"

//208ms, 69.77%
//先用固定长度vector存储, 每个值val将会对应一个val/100的索引, 此数组内放入可变长度的vector, 存放val的值
//注: 此处的值是一个键值对

class MyHashMap {
private:
	vector<vector<pair<int, int>>> stores;

public:
	/** Initialize your data structure here. */
	MyHashMap() {
		stores.resize(10000);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		vector<pair<int, int>>::iterator iter;
		for (iter = stores[key / 100].begin(); iter != stores[key / 100].end(); ++iter)
		{
			if (iter->first == key)
			{
				break;
			}
		}
		if (iter != stores[key / 100].end())
			iter->second = value;
		else
			stores[key / 100].push_back(pair<int, int>{key, value});
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		vector<pair<int, int>>::iterator iter;
		for (iter = stores[key / 100].begin(); iter != stores[key / 100].end(); ++iter)
		{
			if (iter->first == key)
			{
				return iter->second;
			}
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		vector<pair<int, int>>::iterator iter;
		for (iter = stores[key / 100].begin(); iter != stores[key / 100].end(); ++iter)
		{
			if (iter->first == key)
			{
				stores[key / 100].erase(iter);
				break;
			}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
