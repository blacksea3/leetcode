#include "public.h"

//708ms, 52.17%
//后缀树

class StreamChecker {
private:
	struct Node
	{
		unordered_map<char, Node*> nexts;
		bool end = false;
	};
	Node* root = new Node();
	deque<char> query_ready;

public:
	//后缀树初始化
	StreamChecker(vector<string>& words) {
		for (auto& word : words)
		{
			Node* pre = root;
			reverse(word.begin(), word.end());
			for (auto& iiw : word)
			{
				if (pre->nexts.find(iiw) == pre->nexts.end())
				{
					Node* temp = new Node();
					pre->nexts.insert({ iiw, temp });
				}
				pre = pre->nexts[iiw];
			}
			pre->end = true;
		}
	}

	//后缀树查找
	//按letter倒序生成查找字符串
	bool query(char letter) {
		query_ready.push_front(letter);
		Node* pre = root;
		for (auto& q : query_ready)
		{
			if (pre->nexts.find(q) == pre->nexts.end()) return false;
			else
			{
				pre = pre->nexts[q];
				if (pre->end) return true;
			}
		}
		return false;
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
