#include "public.h"

//复用搜索树结构, 未优化DFS搜索, 未优化搜索树(加入删除功能), 632ms, 13.38%

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

	bool search(string word) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isfind = false;
		for (auto ch : word)
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
			if (!isfind) return false;
		}
		return (pre->isend);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		//从祖先开始搜
		TrieTreeNode* pre = ancestor;
		bool isfind = false;
		for (auto ch : prefix)
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
			if (!isfind) return false;
		}
		return true;
	}
};

class Solution {
private:
	vector<string> res;
	void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited,
		Trie* allwords, int row, int col,
		const int& maxrow, const int& maxcol, string pre)
	{
		visited[row][col] = true;
		if (allwords->search(pre))
		{
			if (find(res.begin(), res.end(), pre) == res.end())
				res.push_back(pre);
		}
		if (allwords->startsWith(pre))  //这里必定会重复搜索一层,玛德
		{
			if ((row > 0) && (!visited[row - 1][col]))
			{
				pre.push_back(board[row - 1][col]);
				DFS(board, visited, allwords, row - 1, col, maxrow, maxcol, pre);
				pre.pop_back();
			}
			if ((row < maxrow) && (!visited[row + 1][col]))
			{
				pre.push_back(board[row + 1][col]);
				DFS(board, visited, allwords, row + 1, col, maxrow, maxcol, pre);
				pre.pop_back();
			}
			if ((col > 0) && (!visited[row][col - 1]))
			{
				pre.push_back(board[row][col - 1]);
				DFS(board, visited, allwords, row, col - 1, maxrow, maxcol, pre);
				pre.pop_back();
			}
			if ((col < maxcol) && (!visited[row][col + 1]))
			{
				pre.push_back(board[row][col + 1]);
				DFS(board, visited, allwords, row, col + 1, maxrow, maxcol, pre);
				pre.pop_back();
			}
		}
		visited[row][col] = false;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (words.size() == 0) return vector<string>{};
		int maxrow = board.size() - 1;
		if (maxrow < 0) return vector<string>{};
		int maxcol = board[0].size() - 1;
		if (maxcol < 0) return vector<string>{};

		Trie* allwords = new Trie();
		//words需要生成一个字典树,使用208题的前缀树
		for (auto word : words) allwords->insert(word);

		vector<vector<bool>> visited(maxrow + 1, vector<bool>(maxcol + 1, false));
		string pre;

		//DFS搜索
		for (int row = 0; row <= maxrow; ++row)
		{
			for (int col = 0; col <= maxcol; ++col)
			{
				pre.push_back(board[row][col]);
				DFS(board, visited, allwords, row, col, maxrow, maxcol, pre);
				pre.pop_back();
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<char>> board = { {'a'} };
	vector<string> words = {"a"};
	vector<string> res = s->findWords(board, words);

	return 0;
}
*/
