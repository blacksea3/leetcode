#include "public.h"

//使用固定轮转双端BFS, 还可以接着优化成动态双端BFS, 132ms, 70.57%

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
		//特殊情况:没有endWord
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
		//特殊情况2:beginWord直接连到endWord
		if (isconvert(beginWord, endWord)) return 2;

		unordered_set<string> wordset;
		//为提高速度,vector->unordered_set
		for (auto iter = wordList.begin(); iter != wordList.end(); ++iter)
			wordset.insert(*iter);
		unordered_set<string> wordset_reverse = wordset;

		//双端BFS
		unordered_set<string> history;
		history.insert(beginWord);
		unordered_set<string> history_reverse;
		history_reverse.insert(endWord);

		int res = 0;
		bool isreverse = false;   //是否反向BFS
		const int letter_length = beginWord.size();

		while (true)
		{
			unordered_set<string> nextset;
			if (!isreverse)
			{
				for (auto str : history) wordset.erase(str);
				if (history.empty()) return 0; //强制退出,无转换序列
				for (auto phstring = history.begin(); phstring != history.end(); ++phstring)
				{
					for (int loc = 0; loc < letter_length; ++loc)
					{
						string nexttemp = *phstring;
						for (char c = 'a'; c < 'z'; ++c)
						{
							nexttemp[loc] = c;
							if (wordset.find(nexttemp) != wordset.end())
							{
								nextset.insert(nexttemp);
							}
							if (history_reverse.find(nexttemp) != history_reverse.end())
							{
								++res;
								goto BIGbreak;
							}
						}
					}
				}
				history = nextset;
				isreverse = true;
			}
			else
			{
				for (auto str : history_reverse) wordset_reverse.erase(str);
				if (history_reverse.empty()) return 0; //强制退出,无转换序列
				for (auto phstring = history_reverse.begin(); phstring != history_reverse.end(); ++phstring)
				{
					for (int loc = 0; loc < letter_length; ++loc)
					{
						string nexttemp = *phstring;
						for (char c = 'a'; c < 'z'; ++c)
						{
							nexttemp[loc] = c;
							if (wordset_reverse.find(nexttemp) != wordset_reverse.end())
							{
								nextset.insert(nexttemp);
							}
							if (history.find(nexttemp) != history.end())
							{
								++res;
								goto BIGbreak;
							}
						}
					}
				}
				history_reverse = nextset;
				isreverse = false;
			}
			++res;
		}
	BIGbreak:
		return res + 1;
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
