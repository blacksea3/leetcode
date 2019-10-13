#include "public.h"

//180ms, 69.59%
//��Ϊʹ��Ƶ��ָ����ʹ�ô���
//������unordered_map<int, int> um�洢��ֵ��
//Ȼ���˫��
//  һ����:map<int, deque<int>> countrev ��: �ۼ�ʹ�ô���, ֵ:ʵ�ʵļ�um.key
//    �˴���ʵ�ʵļ�:��deque��Խ��ǰ��Խ�������ʹ��
//  ��һ����:unordered_map<int, int> count ��:ʵ�ʵļ�um.key, ֵ:�˼�ʹ�õĴ���

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
		if (um.find(key) != um.end()) //������, �Ҵ�keyʹ�ô���+1
		{
			um[key] = value;
			int oldUseTime = count[key];
			deque<int>::iterator iter = find(countrev[oldUseTime].begin(), countrev[oldUseTime].end(), key);
			countrev[oldUseTime].erase(iter);
			if (countrev[oldUseTime].empty()) countrev.erase(oldUseTime);
			countrev[oldUseTime + 1].push_back(key);
			count[key]++;
		}
		else //���ǿ�����Ҫȥ��Ԫ��
		{
			if (gblCap == 0) return; //û������ֱ�ӽ���
			else if (um.size() < gblCap) //����Ҫȥ��Ԫ��, ֱ������Ԫ��
			{
				um[key] = value;
				count[key] = 1;
				countrev[1].push_back(key);
			}
			else //��Ҫȥ��Ԫ��, ��Ԫ��ʹ�ô���=1
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
