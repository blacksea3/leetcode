#include "public.h"

//248ms, 28.46%
//先用固定长度vector存储, 每个值val将会对应一个val/100的索引, 此数组内放入可变长度的vector, 存放val%100的值

class MyHashSet {
private:
	vector<vector<int>> stores;

public:
	/** Initialize your data structure here. */
	MyHashSet() {
		stores.resize(10000);
	}

	void add(int key) {
		if (!contains(key)) stores[key / 100].push_back(key % 100);
	}

	void remove(int key) {
		vector<int>::iterator iter = find(stores[key / 100].begin(), stores[key / 100].end(), key % 100);
		if (iter != stores[key / 100].end())
			stores[key / 100].erase(iter);
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		vector<int> targetVector = stores[key / 100];
		vector<int>::iterator iter = find(targetVector.begin(), targetVector.end(), key % 100);
		return iter != targetVector.end();
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/*
int main()
{
	MyHashSet* obj = new MyHashSet();
	obj->add(2);
	obj->add(2);
	obj->remove(2);
	return 0;
}
*/
