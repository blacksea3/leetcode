#include "BinaryTree.h"

//44ms, 99.03%
//¿‡À∆µƒ≤„–Ú±È¿˙

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "";
		string res = "[";
		queue<TreeNode*> pre;
		pre.push(root);
		res += to_string(root->val);

		while (true)
		{
			queue<TreeNode*> next;
			string snext = "";
			bool hasnext = false;
			while (!pre.empty())
			{
				TreeNode* temp = pre.front();
				pre.pop();
				if (temp->left)
				{
					next.push(temp->left);
					snext.push_back(',');
					snext += to_string(temp->left->val);
					hasnext = true;
				}
				else
				{
					snext.push_back(',');
					snext += "null";
				}
				if (temp->right)
				{
					next.push(temp->right);
					snext.push_back(',');
					snext += to_string(temp->right->val);
					hasnext = true;
				}
				else
				{
					snext.push_back(',');
					snext += "null";
				}
			}
			if (hasnext)
			{
				pre = next;
				res += snext;
			}
			else break;
		}
		res.push_back(']');
		return res;
	}

	// Decodes your encoded data to tree.
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.size() == 0) return nullptr;

		//extract root
		queue<TreeNode*> pre;
		queue<TreeNode*> next;
		TreeNode* root;
		int prenum = 0;
		bool sign = true;

		int loc = 1;
		while (true)
		{
			if (isdigit(data[loc]))
			{
				prenum = prenum * 10 + data[loc] - '0';
				loc++;
			}
			else if (data[loc] == '-')
			{
				sign = false;
				loc++;
			}
			else
			{
				if (!sign) prenum *= -1;
				TreeNode* nt = new TreeNode(prenum);
				pre.push(nt);
				root = nt;
				loc++;
				sign = true;
				break;
			}
		}
		bool isnum = false;
		bool isleft = true;
		TreeNode* pretn = pre.front();
		pre.pop();
		bool updatepretn = false;

		//
		while (loc < data.size())
		{
			if (updatepretn)
			{
				if (pre.empty())
				{
					swap(pre, next);
					pretn = pre.front();
					pre.pop();
				}
				else
				{
					pretn = pre.front();
					pre.pop();
				}
				updatepretn = false;
			}

			if (isleft)
			{
				if (!isnum)
				{
					if (isdigit(data[loc]))
					{
						prenum = data[loc] - '0';
						isnum = true;
						loc++;
					}
					else if (data[loc] == '-')
					{
						sign = false;
						loc++;
					}
					else
					{
						loc += 5; //jump over null
						isleft = false;
					}
				}
				else
				{
					if (isdigit(data[loc]))
					{
						prenum = 10 * prenum + data[loc] - '0';
						loc++;
					}
					else
					{
						if (!sign) prenum *= -1;
						TreeNode* temp = new TreeNode(prenum);
						pretn->left = temp;
						next.push(temp);
						isnum = false;
						isleft = false;
						loc++;
						sign = true;
					}
				}
			}
			else
			{
				if (!isnum)
				{
					if (isdigit(data[loc]))
					{
						prenum = data[loc] - '0';
						isnum = true;
						loc++;
					}
					else if (data[loc] == '-')
					{
						sign = false;
						loc++;
					}
					else
					{
						loc += 5; //jump over null
						isleft = true;
						updatepretn = true;
					}
				}
				else
				{
					if (isdigit(data[loc]))
					{
						prenum = 10 * prenum + data[loc] - '0';
						loc++;
					}
					else
					{
						if (!sign) prenum *= -1;
						TreeNode* temp = new TreeNode(prenum);
						pretn->right = temp;
						next.push(temp);
						isnum = false;
						isleft = true;
						loc++;
						updatepretn = true;
						sign = true;
					}
				}
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	//TreeNode* root = stringToTreeNode("[1,2,3,null,null,4,5]");
	TreeNode* root = stringToTreeNode("[5, 2, 3, null, null, 2, 4, 3, 1]");
	
	Codec codec;
	string res = codec.serialize(root);
	TreeNode* root2 = codec.deserialize(res);
	return 0;
}



