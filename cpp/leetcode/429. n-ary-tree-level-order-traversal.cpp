#include "public.h"

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

//196ms, 92.43%
//╤сап

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> q;
		vector<vector<int>> res;

		while (!q.empty())
		{
			queue<Node*> ne;
			vector<int> pre;
			while (!q.empty())
			{
				Node* np = q.front();
				pre.emplace_back(np->val);
				q.pop();
				for (auto& iternp : np->children)
				{
					ne.push(iternp);
				}
			}
			res.emplace_back(pre);
			q = ne;
		}
		return res;
	}
};
