#include "public.h"

//156ms, 31.72%
//先排序再前缀树

class Trie {
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
	Trie() {
		ancestor = new TrieTreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isbreakinter = false;
		for (auto& ch : word)
		{
			isbreakinter = false;
			for (auto& next : pre->nexts)
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

	/** Returns if the word is in the trie. */
	bool search(string word) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isfind = false;
		for (auto& ch : word)
		{
			isfind = false;
			for (auto& next : pre->nexts)
			{
				if (next->val == ch)
				{
					isfind = true;
					pre = next;
					break;
				}
			}
			if (!isfind || !pre->isend) return false; //如果没找到或者找到的不是单词结尾, 则返回false
		}
		return (pre->isend);
	}
};

class Solution {
public:
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		string res = "";
		Trie* trie = new Trie();

		//找它的前缀在不在里面, 找不到就不插入了
		for (auto& word : words)
		{
			if (word.size() == 1)
			{
				if (res.size() < word.size())
				{
					res = word;
				}
				trie->insert(word);
			}
			else
			{
				if (trie->search(word.substr(0, word.size() - 1)))
				{
					if (res.size() < word.size())
					{
						res = word;
					}
					trie->insert(word);
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
	auto res = s->longestWord(words);
	return 0;
}
