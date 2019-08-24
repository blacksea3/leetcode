#include "public.h"

//
//模拟
//相当于树

class FileSystem {
private:
	struct Node
	{
		string content;
		int val;
		vector<Node*> next;
		Node(string precon, int prev)
		{
			content = precon;
			val = prev;
			next.clear();
		}
	};
	Node* head;

public:
	FileSystem() {
		Node* dump = new Node("", -1);
		head = dump;
	}

	bool create(string path, int value) {
		if (path.empty() || path[0] != '/') return false;
		if (path[path.size() - 1] == '/') return false;

		//切割path
		vector<string> splitpath;
		int leftindex = 0;
		int preindex = 1;
		while (preindex < path.size())
		{
			while (preindex < path.size() && path[preindex] != '/')
			{
				preindex++;
			}
			string pre = path.substr(leftindex + 1, preindex - leftindex - 1);
			if (pre.empty()) return false;

			splitpath.push_back(pre);
			leftindex = preindex;
			preindex++;
		}

		Node* preNode = head;
		for (int index = 0; index < splitpath.size() - 1; ++index)
		{
			bool isfind = false;
			for (auto& pnextNode : preNode->next)
			{
				if (pnextNode->content == splitpath[index])
				{
					isfind = true;
					preNode = pnextNode;
					break;
				}
			}
			if (!isfind) return false;
		}

		for (auto& pnextNode : preNode->next)
		{
			if (pnextNode->content == splitpath[splitpath.size() - 1])
			{
				return false;
			}
		}

		Node* newNode = new Node(splitpath[splitpath.size() - 1], value);
		preNode->next.push_back(newNode);
		return true;
	}

	int get(string path) {
		if (path.empty() || path[0] != '/') return -1;
		if (path[path.size() - 1] == '/') return -1;

		//切割path
		vector<string> splitpath;
		int leftindex = 0;
		int preindex = 1;
		while (preindex < path.size())
		{
			while (preindex < path.size() && path[preindex] != '/')
			{
				preindex++;
			}
			string pre = path.substr(leftindex + 1, preindex - leftindex - 1);
			if (pre.empty()) return false;

			splitpath.push_back(pre);
			leftindex = preindex;
			preindex++;
		}

		Node* preNode = head;
		for (int index = 0; index < splitpath.size() - 1; ++index)
		{
			bool isfind = false;
			for (auto& pnextNode : preNode->next)
			{
				if (pnextNode->content == splitpath[index])
				{
					isfind = true;
					preNode = pnextNode;
					break;
				}
			}
			if (!isfind) return -1;
		}

		for (auto& pnextNode : preNode->next)
		{
			if (pnextNode->content == splitpath[splitpath.size() - 1])
			{
				return pnextNode->val;
			}
		}
		return -1;
	}
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */

/*
int main()
{
	FileSystem* obj = new FileSystem();
	cout << obj->create("/leet", 1) << endl;
	cout << obj->create("/leet/code", 2) << endl;
	cout << obj->get("/leet/code");
	cout << obj->create("/c/d", 1);
	cout << obj->get("/c");
	return 0;
}
*/