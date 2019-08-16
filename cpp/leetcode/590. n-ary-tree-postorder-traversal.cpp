#include "public.h"

//208ms, 94.15%
//左右中
//倒过来中右左, 然后修改前序遍历左右顺序, 最后输出再倒序一下就可以


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
	vector<int> postorder(Node* root) {
		if (!root) return {};

		stack<Node*> st;
		vector<int> res;
		st.push(root);

		while (!st.empty())
		{
			Node* temp = st.top();
			res.push_back(temp->val);
			st.pop();
			for (auto& child : temp->children)
			{
				st.push(child);
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
