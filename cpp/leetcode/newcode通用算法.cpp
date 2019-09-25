#include "public.h"

/*
class Node
{
public:
	int v;
	Node* left;
	Node* right;

	Node(int inputv)
	{
		v = inputv;
		left = nullptr;
		right = nullptr;
	}
};

//直接包含树的输入
void buildOneTree(int n, vector<Node*>& vn) //v大小是n+1
{
	for (int i = 1; i <= n; ++i) vn[i] = new Node(0);
	for (int i = 1; i <= n; ++i)
	{
		int l, r, v;
		cin >> l >> r >> v;
		vn[i]->v = v;
		vn[i]->left = vn[l];
		vn[i]->right = vn[r];
	}
}
*/
