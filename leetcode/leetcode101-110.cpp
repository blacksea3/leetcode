#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_101_110

bool Solution::isSymmetric(TreeNode * root)
{
	//用迭代,递归太简单

	//对深度>1的情况
	//维护两个vector<TreeNode*>表示左右的节点们,然后扫下来
	//只有当前节点的儿子们对称了,才会放入stack

	//特殊情况
	if (root == nullptr) return true;
	vector<TreeNode*> left1;
	vector<TreeNode*> right1;
	vector<TreeNode*> left2;
	vector<TreeNode*> right2;
	bool isvalid1 = true;

	//init left/right
	if ((root->right) && (root->left))
	{
		if ((root->right->val) == (root->left->val))
		{
			left1.push_back(root->left);
			right1.push_back(root->right);
		}
		else return false;
	}
	else if (!(root->right) && !(root->left)) return true;
	else return false;

	int count = 0;
	int countmax = (isvalid1) ? left1.size() : left2.size();
	while (true)  //按层遍历
	{
		if (isvalid1)
		{
			TreeNode *tl = left1[0];
			TreeNode *tr = right1[0];
			left1.erase(left1.begin());
			right1.erase(right1.begin());
			if ((tr->right) && (tl->left))
			{
				if ((tr->right->val) == (tl->left->val))
				{
					left2.push_back(tl->left);
					right2.push_back(tr->right);
				}
				else return false;
			}
			else if (!(tr->right) && !(tl->left));
			else return false;

			if ((tr->left) && (tl->right))
			{
				if ((tr->left->val) == (tl->right->val))
				{
					left2.push_back(tl->right);
					right2.push_back(tr->left);
				}
				else return false;
			}
			else if (!(tr->left) && !(tl->right));
			else return false;
			count++;
		}
		else
		{
			TreeNode *tl = left2[0];
			TreeNode *tr = right2[0];
			left2.erase(left2.begin());
			right2.erase(right2.begin());
			if ((tr->right) && (tl->left))
			{
				if ((tr->right->val) == (tl->left->val))
				{
					left1.push_back(tl->left);
					right1.push_back(tr->right);
				}
				else return false;
			}
			else if (!(tr->right) && !(tl->left));
			else return false;

			if ((tr->left) && (tl->right))
			{
				if ((tr->left->val) == (tl->right->val))
				{
					left1.push_back(tl->right);
					right1.push_back(tr->left);
				}
				else return false;
			}
			else if (!(tr->left) && !(tl->right));
			else return false;
			count++;
		}


		if (count == countmax)
		{
			if (isvalid1)
			{
				left1.clear();
				right1.clear();
				countmax = left2.size();
				count = 0;
				isvalid1 = false;
				if (countmax == 0) break;
			}
			else
			{
				left2.clear();
				right2.clear();
				countmax = left1.size();
				count = 0;
				isvalid1 = true;
				if (countmax == 0) break;
			}
		}
	}
	return true;
}

vector<vector<int>> Solution::levelOrder(TreeNode * root)
{
	//没有什么特殊操作

	//维护两个vector<TreeNode*> pre_t1,pre_t2;
	//维护一个vector<vector<int>> total_res
	//维护一个vector<int> pre_res

	if (root == nullptr) return vector<vector<int>> {};

	vector<TreeNode*> pre_t1, pre_t2;

	vector<vector<int>> total_res;
	vector<int> pre_res;

	bool ist1valid = true;

	pre_t1.push_back(root);

	while (true)
	{
		if (ist1valid)
		{
			pre_t2.clear();
			pre_res.clear();
			for (auto tn : pre_t1)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t2.push_back(tn->left);
				if (tn->right) pre_t2.push_back(tn->right);
			}
			ist1valid = false;
			total_res.push_back(pre_res);
			if (pre_t2.empty()) break;
		}
		else
		{
			pre_t1.clear();
			pre_res.clear();
			for (auto tn : pre_t2)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t1.push_back(tn->left);
				if (tn->right) pre_t1.push_back(tn->right);
			}
			ist1valid = true;
			total_res.push_back(pre_res);
			if (pre_t1.empty()) break;
		}
	}
	return total_res;
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode * root)
{
	//没有什么特殊操作

	//维护两个vector<TreeNode*> pre_t1,pre_t2;
	//维护一个vector<vector<int>> total_res
	//维护一个vector<int> pre_res

	if (root == nullptr) return vector<vector<int>> {};

	vector<TreeNode*> pre_t1, pre_t2;

	vector<vector<int>> total_res;
	vector<int> pre_res;

	bool ist1valid = true;  //这个同时也反映了遍历左右方向

	pre_t1.push_back(root);

	while (true)
	{
		if (ist1valid)
		{
			pre_t2.clear();
			pre_res.clear();
			for (auto tn : pre_t1)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t2.push_back(tn->left);
				if (tn->right) pre_t2.push_back(tn->right);
			}
			ist1valid = false;
			total_res.push_back(pre_res);
			if (pre_t2.empty()) break;
		}
		else
		{
			pre_t1.clear();
			pre_res.clear();
			for (int i = pre_t2.size() - 1; i >= 0; i--)
			{
				TreeNode *tn = pre_t2[i];
				pre_res.push_back(tn->val);
				if (tn->right) pre_t1.insert(pre_t1.begin(), tn->right);
				if (tn->left) pre_t1.insert(pre_t1.begin(), tn->left);
			}
			ist1valid = true;
			total_res.push_back(pre_res);
			if (pre_t1.empty()) break;
		}
	}
	return total_res;
}

#else
#endif
