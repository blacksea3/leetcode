#include "public.h"

//60ms, 92.82%

//һ��unordered_multimap, һ��vector, ���vector������β�����в���/�������
//vector��unordered_multimap�ĵ�����

class RandomizedCollection {
private:
	unordered_multimap<int, int> um;
	vector<unordered_multimap<int, int>::iterator> v;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		auto ret = um.find(val) == um.end();
		auto it = um.insert(make_pair(val, int(v.size())));
		v.emplace_back(it);
		return ret;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {   //����: um{1:0, 2:1, 3:2}, v:[um.1, um.2, um.3], ������ͼɾ��2
		auto find = um.find(val);                //find = um.2
		if (find == um.end()) return false;
		int idx = find->second;                  //idx = 1(��ɾ���±�)
		v.back()->second = idx; //update hash table     //um[3] = 1, ��um��ָ��v���һ�����ֵļ��޸�v�±�
		swap(v[idx], v.back());                      //����v�е�ǰ�±��Ӧɾ���±�����
		um.erase(find);
		v.erase(v.end() - 1);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int temp = rand() % v.size();
		return v[temp]->first;
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
