#include "public.h"

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

//DFS, 40ms, 87.04%
class Solution {
private:
	unordered_map<Node*, Node*> visited;  //�ڲ�����ԭNode(key)������Node(value)����ϵ
	Node* DFS(Node* node)
	{
		if (visited.find(node) != visited.end()) return visited[node];
		Node* root = new Node(node->val, {});
		visited.insert({ node, root });
		for (auto n : node->neighbors)
			root->neighbors.push_back(DFS(n));
		return root;
	}

public:
	Node* cloneGraph(Node* node) {
		return DFS(node);
	}
};