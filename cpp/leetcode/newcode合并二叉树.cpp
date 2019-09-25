#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

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

Node* merge(Node* root1, Node* root2)
{
	if (!root1 && !root2) return root1;
	else if (!root1) return root2;
	else if (!root2) return root1;
	else
	{
		root1->v += root2->v;
		root1->left = merge(root1->left, root2->left);
		root1->right = merge(root1->right, root2->right);
		return root1;
	}
}

void output(Node* root)
{
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* pre = q.front();
		q.pop();
		cout << pre->v;
		cout << ' ';
		if (pre->left) q.push(pre->left);
		if (pre->right) q.push(pre->right);
	}
}

/*
int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\hebingerchashu.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		int n, m;
		cin >> n >> m;
		
		vector<Node*> vn(n + 1); //1号是根节点, 如果么有则为空树
		vector<Node*> vm(m + 1);

		for (int i = 1; i <= n; ++i) vn[i] = new Node(0);
		for (int i = 1; i <= m; ++i) vm[i] = new Node(0);

		for (int i = 1; i <= n; ++i)
		{
			int l, r, v;
			cin >> l >> r >> v;
			vn[i]->v = v;
			vn[i]->left = vn[l];
			vn[i]->right = vn[r];
		}

		for (int i = 1; i <= m; ++i)
		{
			int l, r, v;
			cin >> l >> r >> v;
			vm[i]->v = v;
			vm[i]->left = vm[l];
			vm[i]->right = vm[r];
		}

		merge(vn[1], vm[1]);
		output(vn[1]);
	}
}

*/