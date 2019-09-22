#include "public.h"

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors = {}) {
		val = _val;
		neighbors = _neighbors;
	}
};

//28ms, 98.50%
//DFS，递归，记录旧节点指针与新节点指针的关联，以标记创建的节点

class Solution {
private:
	unordered_map<Node*, Node*> visited;  //内部建立原Node(key)至复制Node(value)的联系
public:
	Node* cloneGraph(Node* node) {
		if (visited.find(node) != visited.end()) return visited[node];
		Node* root = new Node(node->val);
		visited[node] = root;
		for (auto& n : node->neighbors)
			root->neighbors.emplace_back(cloneGraph(n));
		return root;
	}
};
