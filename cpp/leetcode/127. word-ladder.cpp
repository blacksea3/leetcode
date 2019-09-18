#include "public.h"

//84ms, 84.02%
//动态双端BFS

class Solution {
private:	
	//外部应确保w1不等于w2
	//返回false:不能转换, true:能转换
	bool isconvert(const string& w1, const string& w2)
	{
		bool isdif = false;
		for (int i = 0; i < w1.size(); ++i)
		{
			if (w1[i] != w2[i])
				if (isdif) return false;
				else isdif = true;
		}
		return true;
	}

public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//为提高速度,vector->unordered_set
		unordered_set<string> wordset(wordList.begin(), wordList.end());
		//特殊情况: endWord不存在于wordList中
		if (wordset.find(endWord) == wordset.end()) return 0;
		bool breakflag = false;
		bool isreverse = false;   //是否反向BFS

		unordered_set<string> history = { beginWord };
		unordered_set<string> history_reverse = { endWord };

		//第一轮双端BFS,构建图 gblmap
		int res = 2;

		while (!history.empty())
		{
			unordered_set<string> next;
			for (auto& str : history) wordset.erase(str);
			for (auto& str : history)
			{
				for (auto& nextstring : wordset)
				{
					if (isconvert(str, nextstring))
					{
						next.insert(nextstring);
						if (history_reverse.find(nextstring) != history_reverse.end())
						{
							breakflag = true;
						}
					}
				}
			}
			if (breakflag) break;
			else res++;
			if (next.size() <= history_reverse.size())
			{
				history = next;
			}
			else
			{
				history = history_reverse; history_reverse = next;
				isreverse = !isreverse;
			}
		}

		return (breakflag) ? res : 0;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << s->ladderLength("hit", "cog", wordList);

	//vector<string> wordList = { "a", "b", "c"};
	//vector<vector<string>> res = s->findLadders("a", "c", wordList);

	return 0;
}
*/
