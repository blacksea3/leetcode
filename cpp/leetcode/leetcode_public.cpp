#include "public.h"
#include "leetcode.h"

void Solution::printlistnode(ListNode* input)
{
	while (input != NULL)
	{
		cout << input->val;
		input = input->next;
	}
	cout << endl;
}

//input 至少应含有一个元素
ListNode * Solution::initlistnode(vector<int> input)
{
	ListNode* return_ln = new ListNode(NULL);
	ListNode* old_ln = return_ln;
	for (vector<int>::const_iterator iter = input.cbegin(); iter != input.cend(); iter++)
	{
		ListNode* new_ln = new ListNode((*iter));
		old_ln->next = new_ln;
		old_ln = new_ln;
	}

	return return_ln->next;
}

//外部确保input不要输入0作为节点值,NULL被作为空节点
TreeNode * Solution::initTreeNode(vector<int> input)
{
	if (input.empty()) return NULL;

	//var node = nodes[0];

	vector<TreeNode*> tier;          //层集合
	TreeNode *treeNode = new TreeNode(input[0]);
	tier.push_back(treeNode);              //添加第一层数据

	//遍历层
	for (int i = 1; i < input.size();)
	{
		vector<TreeNode*> nextTier = {};
		int count = min(tier.size() * 2, input.size() - i); //得到遍历数量
		for (int j = 0; j < count; j++)
		{
			int node = input[i + j];
			if (node == NULL) continue;
			TreeNode *n = new TreeNode(node);
			nextTier.push_back(n);

			if (j % 2 == 0)
			{
				tier[j / 2]->left = n;
			}
			else
			{
				tier[j / 2]->right = n;
			}
		}
		tier = nextTier;
		i += count;
	}
	return treeNode;
	/*
	-------------------- -
		作者：NewAI256
		来源：CSDN
		原文：https ://blog.csdn.net/weixin_43251547/article/details/82846760
	版权声明：本文为博主原创文章，转载请附上博文链接！*/
}
