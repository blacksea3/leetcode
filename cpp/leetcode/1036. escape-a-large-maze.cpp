#include "public.h"

//856ms, 42.27%
//获取blocked数量s, 然后可以得出结论:这些blocked最多包住(s-1)*s/2 (斜过来包)
//现在: 分别从source和targetj进行BFS如果搜到超过(s-1)*s/2的点说明一定没有包住
//如果都没有被包住或者直接互相连通(BFS时搜到了另一个), 那么返回true, 否则返回false

class Solution {
public:
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		int bs = blocked.size();
		int maxblock = bs * (bs - 1) / 2;

		unordered_map<int, unordered_set<int>> ums; //记录: 行:列 block坐标

		for (auto& b : blocked) ums[b[0]].insert(b[1]);

		//from source
		vector<pair<int, int>> pre;
		unordered_map<int, unordered_set<int>> searched; //记录: 行:列 已搜索坐标
		pre.push_back({ source[0], source[1] });
		int empty = 0;

		while (empty <= maxblock && !pre.empty())
		{
			vector<pair<int, int>> next;
			unordered_map<int, unordered_set<int>> nodup_next;
			for (auto& p : pre)
			{
				empty++;
				int r = p.first;
				int c = p.second;
				if (r == target[0] && c == target[1]) return true; //起点直接找到了终点:)
				searched[r].insert(c);
				if (r > 0 && (nodup_next.find(r - 1) == nodup_next.end() || nodup_next[r - 1].find(c) == nodup_next[r - 1].end()) && (searched.find(r - 1) == searched.end() || searched[r - 1].find(c) == searched[r - 1].end()) && (ums.find(r - 1) == ums.end() || ums[r - 1].find(c) == ums[r - 1].end()))
				{
					nodup_next[r - 1].insert(c);
					next.push_back({ r - 1, c });
				}
				if (c > 0 && (nodup_next.find(r) == nodup_next.end() || nodup_next[r].find(c - 1) == nodup_next[r].end()) && (searched.find(r) == searched.end() || searched[r].find(c - 1) == searched[r].end()) && (ums.find(r) == ums.end() || ums[r].find(c - 1) == ums[r].end()))
				{
					nodup_next[r].insert(c - 1);
					next.push_back({ r, c - 1 });
				}
				if (r < 999999 && (nodup_next.find(r + 1) == nodup_next.end() || nodup_next[r + 1].find(c) == nodup_next[r + 1].end()) && (searched.find(r + 1) == searched.end() || searched[r + 1].find(c) == searched[r + 1].end()) && (ums.find(r + 1) == ums.end() || ums[r + 1].find(c) == ums[r + 1].end()))
				{
					nodup_next[r + 1].insert(c);
					next.push_back({ r + 1, c });
				}
				if (c < 999999 && (nodup_next.find(r) == nodup_next.end() || nodup_next[r].find(c + 1) == nodup_next[r].end()) && (searched.find(r) == searched.end() || searched[r].find(c + 1) == searched[r].end()) && (ums.find(r) == ums.end() || ums[r].find(c + 1) == ums[r].end()))
				{
					nodup_next[r].insert(c + 1);
					next.push_back({ r, c + 1 });
				}
			}
			pre = next;
		}
		if (empty <= maxblock) return false;  //起点被包住了

		//from target
		vector<pair<int, int>> pre2;
		unordered_map<int, unordered_set<int>> searched2; //记录: 行:列 已搜索坐标
		pre2.push_back({ target[0], target[1] });
		int empty2 = 0;

		while (empty2 <= maxblock && !pre2.empty())
		{
			vector<pair<int, int>> next;
			unordered_map<int, unordered_set<int>> nodup_next;
			for (auto& p : pre2)
			{
				empty2++;
				int r = p.first;
				int c = p.second;
				searched2[r].insert(c);
				if (r > 0 && (nodup_next.find(r - 1) == nodup_next.end() || nodup_next[r - 1].find(c) == nodup_next[r - 1].end()) && 
					(searched2.find(r - 1) == searched2.end() || searched2[r - 1].find(c) == searched2[r - 1].end()) && (ums.find(r - 1) == ums.end() || ums[r - 1].find(c) == ums[r - 1].end()))
				{
					nodup_next[r - 1].insert(c);
					next.push_back({ r - 1, c });
				}
				if (c > 0 && (nodup_next.find(r) == nodup_next.end() || nodup_next[r].find(c - 1) == nodup_next[r].end()) && 
					(searched2.find(r) == searched2.end() || searched2[r].find(c - 1) == searched2[r].end()) && (ums.find(r) == ums.end() || ums[r].find(c - 1) == ums[r].end()))
				{
					nodup_next[r].insert(c - 1);
					next.push_back({ r, c - 1 });
				}
				if (r < 999999 && (nodup_next.find(r + 1) == nodup_next.end() || nodup_next[r + 1].find(c) == nodup_next[r + 1].end()) &&
					(searched2.find(r + 1) == searched2.end() || searched2[r + 1].find(c) == searched2[r + 1].end()) && (ums.find(r + 1) == ums.end() || ums[r + 1].find(c) == ums[r + 1].end()))
				{
					nodup_next[r + 1].insert(c);
					next.push_back({ r + 1, c });
				}
				if (c < 999999 && (nodup_next.find(r) == nodup_next.end() || nodup_next[r].find(c + 1) == nodup_next[r].end()) && 
					(searched2.find(r) == searched2.end() || searched2[r].find(c + 1) == searched2[r].end()) && (ums.find(r) == ums.end() || ums[r].find(c + 1) == ums[r].end()))
				{
					nodup_next[r].insert(c + 1);
					next.push_back({ r, c + 1 });
				}
			}
			pre2 = next;
		}
		if (empty2 <= maxblock) return false;  //终点被包住了

		return true; //d都没被包住
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> blocked = { {0,1},{1,0} };
	//vector<int> source = {0,0};
	//vector<int> target = {0,2};
	//cout << s->isEscapePossible(blocked, source, target);

	vector<vector<int>> blocked2 = { {100059,100063},{100060,100064},{100061,100065},{100062,100066},{100063,100067},{100064,100068},{100065,100069},{100066,100070},{100067,100071},{100068,100072},{100069,100073},{100070,100074},{100071,100075},{100072,100076},{100073,100077},{100074,100078},{100075,100079},{100076,100080},{100077,100081},{100078,100082},{100079,100083},{100080,100082},{100081,100081},{100082,100080},{100083,100079},{100084,100078},{100085,100077},{100086,100076},{100087,100075},{100088,100074},{100089,100073},{100090,100072},{100091,100071},{100092,100070},{100093,100069},{100094,100068},{100095,100067},{100096,100066},{100097,100065},{100098,100064},{100099,100063},{100098,100062},{100097,100061},{100096,100060},{100095,100059},{100094,100058},{100093,100057},{100092,100056},{100091,100055},{100090,100054},{100089,100053},{100088,100052},{100087,100051},{100086,100050},{100085,100049},{100084,100048},{100083,100047},{100082,100046},{100081,100045},{100080,100044},{100079,100043},{100078,100044},{100077,100045},{100076,100046},{100075,100047},{100074,100048},{100073,100049},{100072,100050},{100071,100051},{100070,100052},{100069,100053},{100068,100054},{100067,100055},{100066,100056},{100065,100057},{100064,100058},{100063,100059},{100062,100060},{100061,100061},{100060,100062} };
	vector<int> source2 = { 100079,100063 };
	vector<int> target2 = { 999948,999967 };
	cout << s->isEscapePossible(blocked2, source2, target2);
	return 0;
}
*/
