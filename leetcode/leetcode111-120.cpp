#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_111_120

int Solution::minDepth(TreeNode * root)
{
	//维护两个vector<TreeNode*> pre_t1,pre_t2;
    //维护一个vector<vector<int>> total_res
    //维护一个vector<int> pre_res

	if (root == nullptr) return 0;

	vector<TreeNode*> pre_t1, pre_t2;

	vector<int> pre_res;

	bool ist1valid = true;
	int depth = 0;
	bool isleftson_null = false;

	pre_t1.push_back(root);

	while (true)
	{
		depth++;
		if (ist1valid)
		{
			pre_t2.clear();
			for (auto tn : pre_t1)
			{
				isleftson_null = false;
				if (tn->left)
				{
					pre_t2.push_back(tn->left);
				}
				else
				{
					isleftson_null = true;
				}
				if (tn->right)
				{
					pre_t2.push_back(tn->right);
				}
				else if (isleftson_null)
				{
					goto end;
				}
				else;
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
				isleftson_null = false;
				if (tn->left) 
				{
					pre_t1.push_back(tn->left);
				}
				else
				{
					isleftson_null = true;
				}
				if (tn->right)
				{
					pre_t1.push_back(tn->right);
				}
				else if (isleftson_null)
				{
					goto end;
				}
				else;
			}
			ist1valid = true;
			if (pre_t1.empty()) break;
		}
	}
	end:
	return depth;
}

bool Solution::hasPathSum(TreeNode * root, int sum)
{
	//迭代实在是太难了,递归处理

	if (root == nullptr) return false;
	else if ((root->left == nullptr) && (root->right == nullptr))
		return (sum == root->val);
	else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

vector<vector<int>> Solution::pathSum(TreeNode * root, int sum)
{
	//迭代实在是太难了,递归处理
	if (root == nullptr) return {};
	else if ((root->left == nullptr) && (root->right == nullptr))
	{
		if (root->val == sum)
		{
			vector<vector<int>> res;
			res.push_back(vector<int>{root->val});
			return res;
		}
		else return {};
    }
	else
	{
		vector<vector<int>> preres1 = pathSum(root->left, sum - root->val);
		vector<vector<int>> preres2 = pathSum(root->right, sum - root->val);
		vector<vector<int>> res = {};
		int prenum = root->val;
		for (auto r : preres1)
		{
			r.insert(r.begin(), prenum);
			res.push_back(r);
		}
		for (auto r : preres2)
		{
			r.insert(r.begin(), prenum);
			res.push_back(r);
		}

		return res;
	}
}

void Solution::flatten(TreeNode * root)
{
	//先序遍历

	if (root == nullptr) return;

	//init
	stack<TreeNode*> r;
	TreeNode* rootbak = root;

	r.push(root);
	//每次都从栈中取出最后一个元素
	//如果有右儿子就放入右儿子(这一步确保右儿子隔离),确保之后是右儿子后读取
	//如果有左儿子就放入左儿子(这一步确保左儿子隔离)
	//如果这个元素不等于当前根元素(这只有第一个循环有效),那么当前元素(链表)增加这个元素作为右儿子,左儿子置空
	while (!r.empty())
	{
		TreeNode* pre = r.top();
		r.pop();
		if (pre->right) r.push(pre->right);
		if (pre->left) r.push(pre->left);
		if (pre != root)
		{
			root->left = nullptr;
			root->right = new TreeNode(pre->val);
			root = root->right;
		}
	}
}

int Solution::numDistinct(string s, string t)
{
	//动态规划

	//dp[i][j]表示S的前i个字符包含了T的前j个字符 的 子序列的个数

	//对 123546 与  125 因为 12354与125是1, 6!=5 所以 123546 与  125是1
	//对 123545 与  125 因为 12354与125是1, 6!=5 所以 123545 与  125是12354与125(多出来的5不使用),加上12354与12(多出来的5使用)

	//应该先给j遍历,以提高t的长度
	//然后给i遍历,以提高s的长度

	//所有t空s有的情况均认为是1
	//所有t有s空的情况均认为是0,以及一些t比s长的情况跳过

	vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));

	for (int i = 0; i <= s.size(); i++)
		dp[0][i] = 1;

	for (int j = 1; j <= t.size(); j++)
		for (int i = 1; i <= s.size(); i++)
			if (s[i - 1] == t[j - 1])
				dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
			else
				dp[j][i] = dp[j][i - 1];

	return dp[t.size()][s.size()];
}

Node * Solution::connect(Node * root)
{
	//这只要记住每一行的最左边元素,然后慢慢拖过去,一直到没有了
	//表达很简单,但是写起来很麻烦

	if (root == nullptr) return root;

	Node* rootbak = root;

	Node* pre_parent;
	Node* pre;
	Node* next_left_parent = root;
	Node* old;
	bool isfirst = true;
	bool isleftson = true;

	while (true)
	{
		isfirst = true;
		isleftson = true;
		pre_parent = next_left_parent;
		pre = pre_parent->left;
		next_left_parent = NULL;
		while (true)
		{
			if (pre != nullptr)
			{
				if (isfirst)
				{
					next_left_parent = pre;
					isfirst = false;
				}
				else
				{
					old->next = pre;
				}
				old = pre;
			}

			if (isleftson)
			{
				pre = pre_parent->right;
				isleftson = false;
			}
			else
			{
				if (pre_parent->next != NULL)
				{
					pre_parent = pre_parent->next;
					isleftson = true;
					pre = pre_parent->left;
				}
				else
					break;
			}
		}
		if (next_left_parent == NULL) break;
	}
	return rootbak;
}

#else
#endif
