#include "public.h"

//156ms, 31.72%
//��������ǰ׺��

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
		//�����ȿ�ʼ��
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
		//�����ȿ�ʼ��
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
			if (!isfind || !pre->isend) return false; //���û�ҵ������ҵ��Ĳ��ǵ��ʽ�β, �򷵻�false
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

		//������ǰ׺�ڲ�������, �Ҳ����Ͳ�������
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
