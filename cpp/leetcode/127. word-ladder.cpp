#include "public.h"

//84ms, 84.02%
//��̬˫��BFS

class Solution {
private:	
	//�ⲿӦȷ��w1������w2
	//����false:����ת��, true:��ת��
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
		//Ϊ����ٶ�,vector->unordered_set
		unordered_set<string> wordset(wordList.begin(), wordList.end());
		//�������: endWord��������wordList��
		if (wordset.find(endWord) == wordset.end()) return 0;
		bool breakflag = false;
		bool isreverse = false;   //�Ƿ���BFS

		unordered_set<string> history = { beginWord };
		unordered_set<string> history_reverse = { endWord };

		//��һ��˫��BFS,����ͼ gblmap
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
