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

int Solution::maxDepth(TreeNode * root)
{
	//没有什么特殊操作

	//维护两个vector<TreeNode*> pre_t1,pre_t2;
	//维护一个vector<vector<int>> total_res
	//维护一个vector<int> pre_res

	if (root == nullptr) return 0;

	vector<TreeNode*> pre_t1, pre_t2;

	int count = 0;
	vector<int> pre_res;

	bool ist1valid = true;

	pre_t1.push_back(root);

	while (true)
	{
		count++;
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
			if (pre_t1.empty()) break;
		}
	}
	return count;
}

TreeNode * Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	//递归会溢出噢,fuck

	//迭代,通过前序的第一个节点判断根节点,在中序中以此为依据拆出左右两个子树,作为左子树和右子树
	//然后用左右子树长度获取对应的前序遍历,迭代下去即可

	if (preorder.size() == 0) return nullptr;

	stack<TreeNode*> st;
	TreeNode* root = new TreeNode(preorder[0]);
	st.push(root);
	int index = 0;

	//先preorder往后面扫,如果当前节点!=inorder未操作节点,则记录至左儿子
	//然后存至栈,注意这里扫的时候,被扫的节点在当前节点后一格
	//否则,栈退出,当前节点上溯
	//inorder节点连续被操作,操作停止时当前节点的右节点恰好等于preorder
	//的被扫描的节点

	for (int i = 1; i <= preorder.size(); ++i)
	{
		TreeNode *cur = st.top();
		if (cur->val != inorder[index])
		{
			cur->left = new TreeNode(preorder[i]);
			st.push(cur->left);
		}
		else
		{
			while (!st.empty() && st.top()->val == inorder[index])
			{
				cur = st.top();
				st.pop();
				++index;
			}
			if (index < inorder.size())  //这相当于退出循环标志
			{
				cur->right = new TreeNode(preorder[i]);
				st.push(cur->right);
			}
		}
	}
	return root;
}

TreeNode * Solution::buildTree_106(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() == 0) return nullptr;

	stack<TreeNode*> st;
	TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
	st.push(root);
	int index = inorder.size() - 1;

	//上一题是这样
	//先preorder往后面扫,如果当前节点!=inorder未操作节点,则记录至左儿子
	//然后存至栈,注意这里扫的时候,被扫的节点在当前节点后一格
	//否则,栈退出,当前节点上溯
	//inorder节点连续被操作,操作停止时当前节点的右节点恰好等于preorder
	//的被扫描的节点

	//这一题是这样
	//把后序遍历倒过来就是根->右->左
	//把中序遍历倒过来就是右->根->左
	//这样和上一题不是差不多蛮!

	for (int i = postorder.size() - 2; i >= 0; --i)
	{
		TreeNode *cur = st.top();
		if (cur->val != inorder[index])
		{
			cur->right = new TreeNode(postorder[i]);
			st.push(cur->right);
		}
		else
		{
			while (!st.empty() && st.top()->val == inorder[index])
			{
				cur = st.top();
				st.pop();
				--index;
			}
			if (index >= 0)  //这相当于退出循环标志
			{
				cur->left = new TreeNode(postorder[i]);
				st.push(cur->left);
			}
		}
	}
	return root;
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode * root)
{
	vector<vector<int>> res = levelOrder(root);

	//给res转一下
	for (int i = 0; i < res.size(); i++)
	{
		vector<int> temp = res[res.size() - 1];
		res.pop_back();
		res.insert(res.begin() + i, temp);
	}
	return res;
}

TreeNode * Solution::iter_sortedArrayToBST(vector<int>& nums, int left, int right)
{
	//拆成两半,然后递归
	int nsize = right - left + 1;
	if (nsize == 1)
	{
		TreeNode *root = new TreeNode(nums[left]);
		return root;
	}
	else if (nsize == 2)
	{
		TreeNode *root = new TreeNode(nums[right]);
		root->left = new TreeNode(nums[left]);
		return root;
	}
	else
	{
		int mid = left + (right - left) / 2;  //求中点不要用 int mid = (l + r)/2，有溢出风险
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = iter_sortedArrayToBST(nums, left, mid - 1);
		root->right = iter_sortedArrayToBST(nums, mid + 1, right);

		return root;
	}
}

TreeNode * Solution::sortedArrayToBST(vector<int>& nums)
{
	if (nums.size() == 0) return nullptr;
	else return iter_sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode * Solution::sortedListToBST(ListNode * head)
{
	//转成有序数组,然后就复用了上一题的代码

	vector<int> nums = {};
	ListNode* pre = head;
	while (pre != nullptr)
	{
		nums.push_back(pre->val);
		pre = pre->next;
	}
	return sortedArrayToBST(nums);
}

int Solution::treeDepth(TreeNode * root)
{
	if (root == nullptr) return 0;
	else return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}

bool Solution::isBalanced(TreeNode * root)
{
	//递归,获取二叉树的深度然后判断
	//假设不会栈溢出

	if (root == nullptr) return true;
	if (abs(treeDepth(root->left) - treeDepth(root->right) ) > 1) return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

#else
#endif
