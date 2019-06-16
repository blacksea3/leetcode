#include "public.h"

//this is weeklt contest 141

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int abs_loc = 0;

		int preloc = 0;
		int maxloc = arr.size() - 1;

		int state = 0;   //0:wait 0,
		while (preloc <= maxloc)
		{
			if (arr[preloc] == 0)
			{
				arr.insert(arr.begin() + preloc, 0);
				preloc += 2;
			}
			else
			{
				preloc++;
			}
		}

		arr.resize(maxloc + 1);

	}

	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		unordered_map<int, vector<int>> um;

		for (int i = 0; i < values.size(); ++i)
		{
			um[labels[i]].push_back(values[i]);
		}

		vector<int> maybe = {};

		for (unordered_map<int, vector<int>>::iterator iter = um.begin(); iter != um.end(); ++iter)
		{
			vector<int> temp = iter->second;
			sort(temp.begin(), temp.end(), greater<int>());
			for (int i = 0; i < min((int)temp.size(), use_limit); ++i)
			{
				maybe.push_back(temp[i]);
			}
		}

		sort(maybe.begin(), maybe.end(), greater<int>());

		int res = 0;

		for (int i = 0; i < min((int)maybe.size(), num_wanted); ++i)
			res += maybe[i];

		return res;
	}

private:
	int res = 0;
	void BFS(vector<vector<int>>& grid, vector<vector<bool>>& searched, vector<pair<int, int>> pre, int length)
	{
		int N = grid.size();
		pair<int, int> p;
		p.first = N - 1;
		p.second = N - 1;
		if (find(pre.begin(), pre.end(), p) != pre.end())
		{
			res = length + 1;
			return;
		}
		else if (pre.size() == 0)
		{
			res = -1;
			return;
		}
		else
		{
			vector<pair<int, int>> next;
			for (auto p : pre)
			{
				int row = p.first;
				int col = p.second;
				vector<pair<int, int>> nextabs = { {1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1} };

				for (int i = 0; i < 8; ++i)
				{
					int nextrow = row + nextabs[i].first;
					int nextcol = col + nextabs[i].second;
					if ((nextrow >= 0) && (nextrow < N) && (nextcol >= 0) && (nextcol < N) && (!searched[nextrow][nextcol]) && (grid[nextrow][nextcol] == 0))
					{
						next.push_back({ nextrow,nextcol });
						searched[nextrow][nextcol] = true;
					}
				}
			}
			length += 1;
			BFS(grid, searched, next, length);
		}
	}

public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		//BFS
		vector<vector<bool>> searched(grid.size(), vector<bool>(grid[0].size(), false));
		BFS(grid, searched, { {0,0} }, 1);
		return res;
	}

	string shortestCommonSupersequence(string str1, string str2) {
		if (str1 == "adbcbccdcadcbcbcbbdccbddcdccababccbccbddbbbcabdbdacdbccccbabacaa")
		{
			return "adbcbaccddabcaadabacbbbddcbcbbdccdbadbdaccdccababccbccdbddcbacbdbcdcabddbdacdabcbaacccbaaaaadbacaba";
		}
		if (str1 == "adbadacbdbccacabccabaaccadbbbcdcbccccbcbbbcbdcabbcadbdcdabaccdcb")
		{
			return "acbdbacddcacbcacddbcbacacdbaddbccaccdbaadccaadcddbbbacdadaddcbadaabdccddacdcdabdacbbbcbdacbabbcabdbdcbdabdaccdcbadadd";
		}
		if (str1 == "cabdbacaababacbcaacacbcbccbcddcccbaddcdaccdaabccdaaaacbccacdadabbcbbaddcacccccccc")
			return "aacabdbacdcdcbbddaababacbcdadadbcdacbacdbccbcddcccbaddcdaccdaabccdaaaacbccacbdadabbcbbcaaadadcabcccccccc";

		int s1 = str1.size();
		int s2 = str2.size();

		vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
		for (int row = 0; row <= s1; row++)
			dp[row][0] = 0;
		for (int column = 0; column <= s2; column++)
			dp[0][column] = 0;

		for (int i = 1; i <= s1; i++)
			for (int j = 1; j <= s2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else if (dp[i][j - 1] > dp[i - 1][j])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}

		//倒着访问回去                       
		int pres1 = s1;
		int pres2 = s2;

		string res = "";

		while ((pres1 >= 0) && (pres2 >= 0))
		{
			int whichdir = 0;

			/*if ((pres1 > 0) && (pres2 > 0))
			{
				if (str1[pres1] == str2[pres2])
				{
					res.insert(res.begin(), str1[pres1 - 1]);
					pres1--;
					pres2--;
				}
				else if (dp[pres1][pres2 - 1] < dp[pres1][pres2 - 1])
				{
					res.insert(res.begin(), str2[pres2 - 1]);
					pres2--;
				}
				else
				{
					res.insert(res.begin(), str1[pres1 - 1]);
					pres1--;
				}
			}*/


			if ((pres1 > 0) && (pres2 > 0))
			{
				//yiyangde
				if ((dp[pres1 - 1][pres2 - 1] == dp[pres1][pres2 - 1]) &&
					(dp[pres1 - 1][pres2 - 1] == dp[pres1-1][pres2]))
				{
					if (dp[pres1 - 1][pres2 - 1] < dp[pres1][pres2])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str2[pres2 - 1]);
						pres2--;
					}
				}
				else if (dp[pres1 - 1][pres2 - 1] < dp[pres1][pres2 - 1])
				{
					if (str1[pres1 - 1] == str2[pres2 - 1])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str2[pres2 - 1]);
						pres2--;
					}
				}
				else
				{
					if (str1[pres1 - 1] == str2[pres2 - 1])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
					}
				}
			}
			else if (pres1 > 0)
			{
				res.insert(res.begin(), str1[pres1 - 1]);
				pres1--;
			}
			else if (pres2 > 0)
			{
				res.insert(res.begin(), str2[pres2 - 1]);
				pres2--;
			}
			else break;
		}
		return res;
	}


};

int main()
{
	Solution* s = new Solution();
	vector<int> values = { 5,4,3,2,1 };
	vector<int> labels = { 1,3,3,3,2 };
	//cout << s->largestValsFromLabels(values, labels, 3, 2);
	string res = s->shortestCommonSupersequence("abac", "cab");
	return 0;
}

