#include "public.h"

//28ms, 25.06%
//ģ��, ֱ�����Զ�ȥ�ص�unordered_set�����Ѿ����ʵ÷���, ��BFS����, ����Ѿ����ʵķ������������ôOJBK, �����ǰ����Ϊ��, ��ô����false

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int N = rooms.size();
		unordered_set<int> visited_rooms;

		unordered_set<int> pre;
		pre.insert(0);
		while (visited_rooms.size() < N)
		{
			if (pre.empty()) return false;
			unordered_set<int> next;
			for (auto& thispre : pre)
			{
				visited_rooms.insert(thispre);
				for (auto& thisnext : rooms[thispre])
				{
					if (visited_rooms.find(thisnext) == visited_rooms.end())
					{
						if (next.find(thisnext) == next.end()) next.insert(thisnext);
					}
				}
			}
			pre = next;
		}
		return true;
	}
};
