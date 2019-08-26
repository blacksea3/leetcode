#include "public.h"

//28ms, 25.06%
//模拟, 直接往自动去重得unordered_set插入已经访问得房间, 用BFS操作, 如果已经访问的房间等于总数那么OJBK, 如果当前房间为空, 那么返回false

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
