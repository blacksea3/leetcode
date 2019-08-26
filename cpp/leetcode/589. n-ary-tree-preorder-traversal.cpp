#include "public.h"

//208ms, 93.40%
//ÖĞ×óÓÒ±éÀú

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
public:
	vector<int> preorder(Node* root) {
		if (!root) return {};

		stack<Node*> st;
		st.push(root);
		vector<int> res;

		while (!st.empty())
		{
			Node* temp = st.top();
			st.pop();
			res.push_back(temp->val);
			for (vector<Node*>::reverse_iterator iter = temp->children.rbegin(); iter != temp->children.rend(); ++iter)
			{
				st.push(*iter);
			}
		}
		return res;
	}
};
