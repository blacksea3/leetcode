#include "public.h"

//180ms, 69.59%
//认为使用频率指的是使用次数
//首先有unordered_map<int, int> um存储键值对
//然后加双向
//  一个是:map<int, deque<int>> countrev 键: 累计使用次数, 值:实际的键um.key
//    此处的实际的键:在deque中越靠前则越最近最少使用
//  另一个是:unordered_map<int, int> count 键:实际的键um.key, 值:此键使用的次数

class LFUCache {
private:
	unordered_map<int, int> um;
	map<int, deque<int>> countrev;
	unordered_map<int, int> count;
	int gblCap;
public:
	LFUCache(int capacity) {
		gblCap = capacity;
	}

	int get(int key) {
		if (um.find(key) == um.end()) return -1;
		else
		{
			int oldUseTime = count[key];
			deque<int>::iterator iter = find(countrev[oldUseTime].begin(), countrev[oldUseTime].end(), key);
			countrev[oldUseTime].erase(iter);
			if (countrev[oldUseTime].empty()) countrev.erase(oldUseTime);
			countrev[oldUseTime + 1].push_back(key);
			count[key]++;
			return um[key];
		}
	}

	void put(int key, int value) {
		if (um.find(key) != um.end()) //仅更新, 且此key使用次数+1
		{
			um[key] = value;
			int oldUseTime = count[key];
			deque<int>::iterator iter = find(countrev[oldUseTime].begin(), countrev[oldUseTime].end(), key);
			countrev[oldUseTime].erase(iter);
			if (countrev[oldUseTime].empty()) countrev.erase(oldUseTime);
			countrev[oldUseTime + 1].push_back(key);
			count[key]++;
		}
		else //考虑可能需要去除元素
		{
			if (gblCap == 0) return; //没有容量直接禁用
			else if (um.size() < gblCap) //不需要去除元素, 直接新增元素
			{
				um[key] = value;
				count[key] = 1;
				countrev[1].push_back(key);
			}
			else //需要去除元素, 新元素使用次数=1
			{
				map<int, deque<int>>::iterator iter = countrev.begin();
				int popV = iter->second.front();
				iter->second.pop_front();
				count.erase(popV);
				um.erase(popV);
				um[key] = value;
				count[key] = 1;
				countrev[1].push_back(key);
			}
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
int main()
{
	LFUCache* obj = new LFUCache(2);
	obj->put(2, 1);
	obj->put(1, 1);
	obj->put(2, 3);
	obj->put(4, 1);
	cout << obj->get(1) << endl;
	cout << obj->get(2) << endl;
	return 0;
}
*/
