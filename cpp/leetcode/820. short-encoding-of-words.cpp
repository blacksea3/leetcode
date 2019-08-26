#include "public.h"

//164ms, 35.59%
//生成字典树
//包括插入和查看root到所有叶子节点的总长度

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

	int res = 0;
	int get_total_length()
	{
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		DFS(pre, 0);
		return res;
	}

	void DFS(TrieTreeNode* root, int length)
	{
		length++;
		if (root->nexts.size() == 0) res += length; //额外加一: #号
		else
		{
			for (auto& n : root->nexts)
			{
				DFS(n, length);
			}
		}
	}
};

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		Trie* obj = new Trie();
		for (auto& word : words)
		{
			reverse(word.begin(), word.end());
			obj->insert(word);
		}

		return obj->get_total_length();
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> words = { "time", "me", "bell" };
	cout << s->minimumLengthEncoding(words);
	return 0;
}
*/
