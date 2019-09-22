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
//DFS���ݹ飬��¼�ɽڵ�ָ�����½ڵ�ָ��Ĺ������Ա�Ǵ����Ľڵ�

class Solution {
private:
	unordered_map<Node*, Node*> visited;  //�ڲ�����ԭNode(key)������Node(value)����ϵ
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
