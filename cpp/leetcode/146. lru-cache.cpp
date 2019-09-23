#include "public.h"

//132ms, 97.82%
//字典和双向链表

class LRUCache {
private:
	//放一个字典记录键:pair(值,链表位置)
	unordered_map<int, pair<int, list<int>::iterator>> LRUpair;
	//放一个双向链表记录:链表值(头部的链表是最少使用的)
	list<int> record;
	int prelen = 0;
	int i_capacity = 0;
public:
	LRUCache(int capacity) {
		//要求是O(1)时间
		prelen = 0;
		i_capacity = capacity;
	}

	int get(int key) {
		if (LRUpair.find(key) != LRUpair.end())
		{
			int value = LRUpair[key].first;
			record.erase(LRUpair[key].second);
			record.push_front(key);
			LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
			return value;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		//如果存在
		if (get(key) != -1)
		{
			record.erase(LRUpair[key].second);
			record.push_front(key);
			LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
		}
		else
		{
			if (prelen < i_capacity)
			{
				prelen++;
				record.push_front(key);
				LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
			}
			else
			{
				LRUpair.erase(LRUpair.find(record.back()));
				record.pop_back();
				record.push_front(key);
				LRUpair[key] = pair<int, list<int>::iterator>{ value, record.begin() };
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */