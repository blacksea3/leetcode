#include "public.h"

//336ms, 20.56%
//DFS

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

class Solution {
private:
	int depth = 1;
	void DFS(Node* root, int olddepth)
	{
		olddepth++;
		depth = max(depth, olddepth);
		for (auto& p_node : root->children)
			DFS(p_node, olddepth);
	}

public:
	int maxDepth(Node* root) {
		if (!root) return 0;
		DFS(root, 0);
		return depth;
	}
};
