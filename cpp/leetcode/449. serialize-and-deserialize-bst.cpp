#include "BinaryTree.h"

//28ms, 100%
//ǰ�����: ɨ��ĳ��ַ�����#���
//Ȼ��ɨ���ַ���, ���ݴ�С��ϵ��������߻����ұ�, ����ջ

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
private:
	string ser_res = "";
	//�����ұ���
	void preorder(TreeNode* root)
	{
		if (!root) return;
		else
		{
			ser_res += (to_string(root->val) + "#");
			preorder(root->left);
			preorder(root->right);
		}
	}

public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		preorder(root);
		return ser_res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		//����data
		if (data == "") return nullptr;
		//��ת��vector, ������д, ����Ч���½�
		vector<int> vdata;
		int oldloc = 0;
		int preloc = 0;
		while (preloc < data.size())
		{
			while (preloc < data.size() && data[preloc] != '#') preloc++;
			vdata.push_back(atoi(data.substr(oldloc, preloc - oldloc).c_str()));
			oldloc = preloc + 1;
			preloc++;
		}
		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(vdata[0]);
		st.push(root);
		int vloc = 1;
		while (vloc < vdata.size())
		{
			TreeNode* temp = new TreeNode(vdata[vloc]);
			TreeNode* pre = st.top(); //�����ϴ˴�st����Ϊ��
			if (st.top()->val > vdata[vloc])
			{
				st.top()->left = temp;
				st.push(temp);
			}
			else
			{
				while (true)
				{
					if (st.empty())
					{
						pre->right = temp;
						st.push(temp);
						break;
					}
					else if (st.top()->val < vdata[vloc])
					{
						pre = st.top();
						st.pop();
					}
					else
					{
						pre->right = temp;
						st.push(temp);
						break;
					}
				}
			}
			vloc++;
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	Codec codec;
	//codec.deserialize(codec.serialize(stringToTreeNode("[2,1,3]")));
	codec.deserialize(codec.serialize(stringToTreeNode("[3,1,4,null,2]")));
}
