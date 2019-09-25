#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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

//直接包含树的输入
void buildOneTree(int n, vector<Node*>& vn) //v大小是n+1
{
	for (int i = 1; i <= n; ++i) vn[i] = new Node(0);
	for (int i = 1; i <= n; ++i)
	{
		int l, r;
		cin >> l >> r;
		vn[i]->left = vn[l];
		vn[i]->right = vn[r];
	}
}

void preOrder(Node* root)
{
	stack<Node*> s;
	Node* pre = root;

	while (!s.empty() || pre)
	{
		cout << pre->v << ' ';
		s.push(pre);

		if (pre->left)
		{
			pre = pre->left;
		}
		else
		{
			while (!s.empty())
			{
				Node* temp = s.top();
				s.pop();
				if (temp->right)
				{
					pre = temp->right;
					goto end;
				}
				else
				{
					continue;
				}
			}
			if (s.empty()) break;
		end:;
		}
	}
}

void inOrder(Node* root)
{
	stack<Node*> s;
	Node* pre = root;

	while (!s.empty() || pre)
	{
		s.push(pre);
		if (pre->left)
		{
			pre = pre->left;
		}
		else
		{
			while (!s.empty())
			{
				Node* temp = s.top();
				s.pop();
				cout << temp->v << ' ';
				if (temp->right)
				{
					pre = temp->right;
					goto end;
				}
				else
				{
					continue;
				}
			}
			if (s.empty()) break;
		end:
			;
		}
	}
}

void postOrder(Node* root)
{
	stack<Node*> s;
	Node* pre = root;
	vector<int> vals;

	while (!s.empty() || pre)
	{
		vals.emplace_back(pre->v);
		s.push(pre);

		if (pre->right)
		{
			pre = pre->right;
		}
		else
		{
			while (!s.empty())
			{
				Node* temp = s.top();
				s.pop();
				if (temp->left)
				{
					pre = temp->left;
					goto end;
				}
				else
				{
					continue;
				}
			}
			if (s.empty()) break;
		end:;
		}
	}

	reverse(vals.begin(), vals.end());

	for (auto& v : vals)
	{
		cout << v << ' ';
	}
}

void levelOrder(Node* root)
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

int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\bianlierchashu.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		int n;
		cin >> n;

		vector<Node*> vn(n + 1); //1号是根节点, 如果么有则为空树
		for (int i = 1; i <= n; ++i) vn[i] = new Node(0);
		for (int i = 1; i <= n; ++i)
		{
			int l, r;
			cin >> l >> r;
			vn[i]->left = vn[l];
			vn[i]->right = vn[r];
		}
		for (int i = 1; i <= n; ++i)
		{
			vn[i]->v = i;
		}

		preOrder(vn[1]);
		cout << endl;
		inOrder(vn[1]);
		cout << endl;
		postOrder(vn[1]);
		cout << endl;
		levelOrder(vn[1]);
		cout << endl;
	}
}
