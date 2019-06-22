#include "public.h"

//188ms, 56.36%

class LRUCache {
private:
	//��һ���ֵ��¼��:pair(ֵ,����λ��)
	unordered_map<int, pair<int, list<int>::iterator>> LRUpair;
	//��һ��˫�������¼:����ֵ(ͷ��������������ʹ�õ�)
	list<int> record;
	int prelen = 0;
	int i_capacity = 0;
public:
	LRUCache(int capacity) {
		//Ҫ����O(1)ʱ��
		prelen = 0;
		i_capacity = capacity;
	}

	int get(int key) {
		if (LRUpair.find(key) != LRUpair.end())
		{
			list<int>::iterator loc = LRUpair[key].second;
			int value = LRUpair[key].first;
			record.erase(loc);
			record.push_front(key);
			LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
			return value;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		//�������
		if (get(key) != -1)
		{
			list<int>::iterator loc = LRUpair[key].second;
			record.erase(loc);
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