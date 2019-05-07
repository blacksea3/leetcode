#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_111_120

int Solution::minDepth(TreeNode * root)
{
	//ά������vector<TreeNode*> pre_t1,pre_t2;
    //ά��һ��vector<vector<int>> total_res
    //ά��һ��vector<int> pre_res

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
	//����ʵ����̫����,�ݹ鴦��

	if (root == nullptr) return false;
	else if ((root->left == nullptr) && (root->right == nullptr))
		return (sum == root->val);
	else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

vector<vector<int>> Solution::pathSum(TreeNode * root, int sum)
{
	//����ʵ����̫����,�ݹ鴦��
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
	//�������

	if (root == nullptr) return;

	//init
	stack<TreeNode*> r;
	TreeNode* rootbak = root;

	r.push(root);
	//ÿ�ζ���ջ��ȡ�����һ��Ԫ��
	//������Ҷ��Ӿͷ����Ҷ���(��һ��ȷ���Ҷ��Ӹ���),ȷ��֮�����Ҷ��Ӻ��ȡ
	//���������Ӿͷ��������(��һ��ȷ������Ӹ���)
	//������Ԫ�ز����ڵ�ǰ��Ԫ��(��ֻ�е�һ��ѭ����Ч),��ô��ǰԪ��(����)�������Ԫ����Ϊ�Ҷ���,������ÿ�
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
	//��̬�滮

	//dp[i][j]��ʾS��ǰi���ַ�������T��ǰj���ַ� �� �����еĸ���

	//�� 123546 ��  125 ��Ϊ 12354��125��1, 6!=5 ���� 123546 ��  125��1
	//�� 123545 ��  125 ��Ϊ 12354��125��1, 6!=5 ���� 123545 ��  125��12354��125(�������5��ʹ��),����12354��12(�������5ʹ��)

	//Ӧ���ȸ�j����,�����t�ĳ���
	//Ȼ���i����,�����s�ĳ���

	//����t��s�е��������Ϊ��1
	//����t��s�յ��������Ϊ��0,�Լ�һЩt��s�����������

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
	//��ֻҪ��סÿһ�е������Ԫ��,Ȼ�������Ϲ�ȥ,һֱ��û����
	//���ܼ�,����д�������鷳

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
