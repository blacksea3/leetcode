#include "public.h"

//956ms, 16.13%
//����һ��unordered_map<key, deque<int>>, ��Ҫά�ִ�deque��������
//����һ��unordered_map<int, string> ʱ�����Ӧvalue

class TimeMap {
public:
	unordered_map<string, deque<int>> data;
	unordered_map<int, string> val;

	/** Initialize your data structure here. */
	TimeMap() {
		;
	}

	void set(string key, string value, int timestamp) {
		//ע���ҵ�timestamp��-1����, ��ʹ��upper_bound�ܹ���
		if (data.find(key) == data.end())
		{
			data[key].push_front(-1 * timestamp);
			val[-1 * timestamp] = value;
		}
		else
		{
			data[key].push_front(-1 * timestamp);
			val[-1 * timestamp] = value;
		}
	}

	string get(string key, int timestamp) {
		//ע���ҵ�timestamp��-1����, ��ʹ��upper_bound�ܹ���
		if (data.find(key) == data.end()) return "";
		else
		{
			deque<int>::iterator iter = lower_bound(data[key].begin(), data[key].end(), -1 * timestamp);
			if (iter == data[key].end()) return "";
			else return val[*iter];
		}
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/*
int main()
{
	TimeMap* obj = new TimeMap();
	obj->set("foo", "bar", 1);
	string param_2 = obj->get("foo", 2);
	return 0;
}
*/
