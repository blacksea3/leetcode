#include "public.h"

//前缀树, 116ms, 78.76%

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
			if (!isfind) return false;
		}
		return (pre->isend);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isfind = false;
		for (auto& ch : prefix)
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
			if (!isfind) return false;
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
