#include "public.h"

//复用前缀树, 128ms, 83.88%

class WordDictionary {
private:
	struct TrieTreeNode
	{
		char val;
		vector<TrieTreeNode*> nexts = {};
		bool isend = false;
	};

	TrieTreeNode* ancestor;

public:
	/** Initialize your data structure here. */
	WordDictionary() {
		ancestor = new TrieTreeNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isbreakinter = false;
		for (auto ch : word)
		{
			isbreakinter = false;
			for (auto next : pre->nexts)
			{
				if (next->val == ch)
				{
					pre = next;
					isbreakinter = true;
				}
			}
			if (!isbreakinter)
			{
				TrieTreeNode* newtt = new TrieTreeNode();
				newtt->val = ch;
				pre->nexts.push_back(newtt);
				pre = newtt;
			}
		}
		pre->isend = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		//从祖先开始搜
		//这里有个回溯夹在中间,他妈的
		TrieTreeNode* pre = ancestor;
		bool isfind = false;
		stack<pair<pair<TrieTreeNode*, int>, int>> st;  //用于回溯,表示当前可以用来回溯的TrieTreeNode*.未搜索过的next将从int开始,int是一个实际的下标(理论上这里将从1开始),因为下标0一定会被首先使用而不会保存到作为接下来的起始搜索下标保存
		//另外还储存当前匹配下标(如果从任意一个字符替换了.的话)
		bool isneedrecall = false;
		int wordloc = -1;

		while (true)
		{
			if (!isneedrecall)
			{
				if (wordloc == word.size() - 1)
				{
					if (pre->isend) break;
					else isneedrecall = true;
				}
				else
				{
					wordloc++;
					char ch = word[wordloc];
					if (ch == '.')
					{
						if (pre->nexts.size() > 0)
						{
							st.push(pair<pair<TrieTreeNode*, int>, int> {pair<TrieTreeNode*, int>{pre, 1}, wordloc});
							pre = pre->nexts[0];
						}
						else isneedrecall = true;
					}
					else
					{
						isfind = false;
						for (auto next : pre->nexts)
						{
							if (next->val == ch)
							{
								isfind = true;
								pre = next;
								break;
							}
						}
						if (!isfind) isneedrecall = true;
					}
				}
			}
			else
			{
				if (st.empty()) return false;

				pair<pair<TrieTreeNode*, int>, int> BIG_precondition = st.top();
				pair<TrieTreeNode*, int> precondition = BIG_precondition.first;
				if (precondition.second == precondition.first->nexts.size())
					st.pop();
				else
				{
					pre = precondition.first->nexts[precondition.second];
					st.top().first.second++;
					wordloc = BIG_precondition.second;
					isneedrecall = false;
				}
			}
		}

		return true;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
