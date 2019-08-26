#include "public.h"

//
//建立vector<map<int, int>> v: 记录所有元素, 它的快照与它的值

/*
class SnapshotArray {
private:
	vector<map<int, int>> v;
	int presnaptime = -1;
	unordered_set<int> updateindexs;

public:
	SnapshotArray(int length) {
		v.resize(length);
		for (int i = 0; i < v.size(); ++i)
			v[i].insert(pair<int, int>{0, 0});
	}

	void set(int index, int val) {
		v[index][-1] = val;
		updateindexs.insert(index);
	}

	int snap() {
		presnaptime++;
		//update:
		for (auto up : updateindexs)
		{
			int temp = v[up][-1];
			v[up].erase(-1);
			v[up][presnaptime] = temp;
		}
		updateindexs.clear();
		return presnaptime;
	}

	int get(int index, int snap_id) {
		map<int, int> m = v[index];
		int v = 0;
		for (auto& im : m)
		{
			if (im.first <= snap_id)
			{
				v = im.second;
			}
			else
			{
				break;
			}
		}
		return v;
	}
};
*/
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

//
//近似暴力, 用map记录当前值, 用vector记录所有历史值

class SnapshotArray {
private:
	unordered_map<int, int> pre;
	vector<unordered_map<int, int>> total;
	int presnaptime = -1;

public:
	SnapshotArray(int length) {
		;
	}

	void set(int index, int val) {
		pre[index] = val;
	}

	int snap() {
		presnaptime++;
		//update:
		total.push_back(pre);
		return presnaptime;
	}

	int get(int index, int snap_id) {
		unordered_map<int, int> thismap = total[snap_id];
		if (thismap.find(index) == thismap.end()) return 0;
		else return thismap[index];
	}
};

/*
["SnapshotArray","snap","snap","set","snap","get","set","get","snap","get"]
[[1],[],[],[0,4],[],[0,1],[0,12],[0,1],[],[0,3]]
*/

/*
int main()
{
	SnapshotArray* obj = new SnapshotArray(1);
	cout << obj->snap() << endl;
	cout << obj->snap() << endl;
	obj->set(0, 4);
	cout << obj->snap() << endl;
	cout << obj->get(0, 1) << endl;
	obj->set(0, 12);
	cout << obj->get(0, 1) << endl;
	cout << obj->snap() << endl;
	cout << obj->get(0, 3) << endl;
	return 0;
}
*/
