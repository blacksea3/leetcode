#include"public.h"

//brute force

class Solution {
public:
	int twoSumLessThanK(vector<int>& A, int K) {
		int res = -1;

		sort(A.begin(), A.end());
		for (int i = 0; i < A.size() - 1; ++i)
		{
			for (int j = i + 1; j < A.size(); ++j)
			{
				if ((A[i] + A[j]) < K) res = max(A[i] + A[j], res);
			}
		}

		return res;
	}

	int numKLenSubstrNoRepeats(string S, int K) {
		if (S.size() < K) return 0;

		//init
		int preloc = 0;
		int startloc = -1 * K + 1;
		int res = 0;
		vector<int> V(256, -1);

		while (preloc < S.size())
		{
			if (V[S[preloc]] >= startloc)
			{
				startloc = V[S[preloc]] + 1;
				V[S[preloc]] = preloc;
				preloc++;
			}
			else
			{
				V[S[preloc]] = preloc;
				if ((preloc - startloc) == (K - 1))
				{
					if (startloc >= 0) res++;
					startloc++;
					preloc++;
				}
				else
				{
					preloc++;
				}
			}
		}
		return res;
	}

	int earliestAcq(vector<vector<int>>& logs, int N) {
		//得先排序
		sort(logs.begin(), logs.end());

		//先搞清楚有多少人
		vector<unordered_set<int>> groups;
		for (int i = 0; i < N; ++i) groups.push_back(unordered_set<int>{i});

		//然后模拟
		int res;
		int loc = 0;
		bool isfindres = false;

		while (loc < logs.size())
		{
			bool findfirst = false;
			bool issamegroup = false;

			int first = 0;
			for (first = 0; first < groups.size(); ++first)
			{
				if (groups[first].find(logs[loc][1]) != groups[first].end())
				{
					if (groups[first].find(logs[loc][2]) != groups[first].end())
					{
						issamegroup = true;
						break;
					}
					break;
				}
			}
			if (issamegroup)
			{
				loc++;
				continue;
			}
			else
			{
				int second = 0;
				for (second = 0; second < groups.size(); ++second)
				{
					if (groups[second].find(logs[loc][2]) != groups[second].end())
					{
						break;
					}
				}
				//merge first and second
				unordered_set<int> temp = groups[first];
				for (auto& uss : groups[second]) temp.insert(uss);
				groups[first] = temp;
				groups.erase(groups.begin() + second);
				loc++;
			}

			if (groups.size() == 1)
			{
				isfindres = true;
				break;
			}
		}
		if (isfindres) res = logs[loc - 1][0];
		else res = -1;

		return res;
	}

//此题解法有错
private:
	static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.first > p2.first;
	}

	bool success = false;
	multiset<int> newpre;

	void DFS(vector<vector<int>>& A, vector<vector<bool>>& issearched, int row, int col)
	{
		if (success) return;

		if ((row == A.size() - 1) && (col == A[0].size() - 1)) success = true;

		newpre.insert(A[row][col]);
		issearched[row][col] = true;

		//往高的地方走
		vector<pair<int, int>> val_dir;   //dir:0 north, 1:east, 2:south, 3:west

		if ((col < A[0].size() - 1) && (!issearched[row][col + 1]))
			val_dir.push_back(pair<int, int>{A[row][col + 1], 1});
		if ((row < A.size() - 1) && (!issearched[row + 1][col]))
			val_dir.push_back(pair<int, int>{A[row + 1][col], 2});
		if ((row > 0) && (!issearched[row - 1][col]))
			val_dir.push_back(pair<int, int>{A[row - 1][col], 0});
		if ((col > 0) && (!issearched[row][col - 1]))
			val_dir.push_back(pair<int, int>{A[row][col - 1], 3});

		sort(val_dir.begin(), val_dir.end(), cmp);

		for (int i = 0; i < val_dir.size(); ++i)
		{
			switch (val_dir[i].second)
			{
			case 0:
			{
				DFS(A, issearched, row - 1, col);
				break;
			}
			case 1:
			{
				DFS(A, issearched, row, col + 1);
				break;
			}
			case 2:
			{
				DFS(A, issearched, row + 1, col);
				break;
			}
			case 3:
			{
				DFS(A, issearched, row, col - 1);
				break;
			}
			default:
				break;
			}
			if (success) return;
		}

		multiset <int>::iterator pos = newpre.find(A[row][col]);
		newpre.erase(pos);
		issearched[row][col] = false;
	}

public:
	int maximumMinimumPath(vector<vector<int>>& A) {

		vector<vector<bool>> issearched(A.size(), vector<bool>(A[0].size(), false));
		DFS(A, issearched, 0, 0);
		multiset<int>::iterator iter = newpre.begin();
		int pre = *iter;
		return pre;
	}

};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->numKLenSubstrNoRepeats("aaaaaaa", 2);

	//vector<vector<int>> logs = { {20190101, 0, 1}, {20190104, 3, 4}, {20190107, 2, 3}, {20190211, 1, 5}, {20190224, 2, 4},{20190301, 0, 3},{20190312, 1, 2 }, { 20190322, 4, 5 } };
	//cout << s->earliestAcq(logs, 6);
	//vector<vector<int>> logs = { {0, 2, 7}, {12, 3, 1}, {6, 2, 4}, {7, 7, 3}, {5, 5, 2}, {10, 2, 4}, {1, 5, 0}, {3, 4, 5}, {9, 0, 3}, {4, 2, 7}, {11, 0, 5}, {8, 5, 2}, {2, 5, 3} };
	//cout << s->earliestAcq(logs, 8);

	//vector<vector<int>> maps = { {5, 4, 5},{1, 2, 6},{7, 4, 6} };
	//vector<vector<int>> maps = { {3, 4, 6, 3, 4}, { 0, 2, 1, 1, 7 }, { 8, 8, 3, 2, 7 }, { 3, 2, 4, 9, 8 }, { 4, 1, 2, 0, 0 }, { 4, 6, 5, 4, 3 } };
	//vector<vector<int>> maps = {{5, 4, 3, 1}, { 7, 4, 5, 2}, { 4, 9, 8, 2}, { 2, 3, 6, 6}};
	
	vector<vector<int>> maps = { {2, 5, 5, 4, 3, 0, 2}, { 1,5,3,1,2,5,5 }, { 3,3,3,4,3,3,4 }, { 5,5,2,5,2,4,0 }, { 3,1,3,3,5,4,5 }, { 2,2,3,5,4,5,0 }, { 1,0,3,2,4,5,4 } };
	cout << s->maximumMinimumPath(maps);
	return 0;
}

*/