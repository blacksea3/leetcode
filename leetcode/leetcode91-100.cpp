#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_91_100

int Solution::numDecodings(string s)
{
	//һ��ɨ��

	//��¼��һ����ĸ
	//a(n) = a(n-1)(�����ǰ��ĸ����'0') + (�����һ����ĸ�͵�ǰ��ĸ���Ժϲ�)a(n-2)
	//ע�������ǰ��ĸ��'0',��һ����ĸ�����ܺϲ�,ֱ�ӷ���0

	//��ʼ���Լ��������
	int slen = s.size();

	int an = 0;
	int an_ad1 = 0;
	an = (s[0] != '0') ? 1 : 0;
	if (slen == 1) return an;
	if (an == 0) return 0;

	if ((s[0] == '1') || (s[0] == '2') && (s[1] <= '6')) an_ad1 = 2;
	else an_ad1 = 1;

	bool is_ad1_bigger = true;   //�Ƿ�an_ad1��an��,�Ǿ�true

	//��ѭ������,����an���ز���
	for (int i = 2; i < slen; i++)
	{
		if (is_ad1_bigger)
		{
			if (s[i] == '0')
			{
				if ((s[i - 1] != '1') && (s[i - 1] != '2')) return 0;
				else
				{
					//an = an;
					is_ad1_bigger = false;
				}
			}
			else
			{
				if ((s[i - 1] == '1') || (s[i - 1] == '2') && (s[i] <= '6'))
				{
					an = an + an_ad1;
					is_ad1_bigger = false;
				}
				else
				{
					an = an_ad1;
					is_ad1_bigger = false;
				}
			}
		}
		else
		{
			if (s[i] == '0')
			{
				if ((s[i - 1] != '1') && (s[i - 1] != '2')) return 0;
				else
				{
					//an = an;
					is_ad1_bigger = true;
				}
			}
			else
			{
				if ((s[i - 1] == '1') || (s[i - 1] == '2') && (s[i] <= '6'))
				{
					an_ad1 = an_ad1 + an;
					is_ad1_bigger = true;
				}
				else
				{
					an_ad1 = an;
					is_ad1_bigger = true;
				}
			}
		}
	}

	return (is_ad1_bigger) ? an_ad1 : an;
}

ListNode * Solution::reverseBetween(ListNode * head, int m, int n)
{
	if (m == n) return head;

	//һ��ɨ��
	ListNode *dump = new ListNode(0);
	dump->next = head;
	int loc = 0;
	ListNode *left = dump;
	ListNode * right = dump;
	bool isstart = false;
	ListNode *preln = dump;
	while (loc < n)
	{
		if (!isstart)
		{
			if ((loc + 1) == m)
			{
				left = preln;
				isstart = true;
			}
			loc++;
			preln = preln->next;
		}
		else
		{
			right = preln;  //ʵ������left->next��right->next����
			// 1->3->2->4->5  left:1 right:2
			ListNode *temp = left->next;
			left->next = right->next;
			right->next = left->next->next;
			left->next->next = temp;

			loc++;
		}
	}
	return dump->next;
}

vector<string> Solution::restoreIpAddresses(string s)
{
	//������ip��4���������,ÿ�����ַ�Χ��[0,255],��0������0��ͷ

	//���ݿɶ���̫����,ֱ�ӱ������
	//�Գ������,Ȼ�󰤸��ж�ȥ��,fuck,n^3ʱ�临�Ӷ�

	int slen = s.size();
	vector<string> res = {};

	for (int i = 1; i <= 3; i++)
	{
		if ((slen - i) < 3) break;
		if ((slen - i) > 9) continue;
		for (int j = 1; j <= 3; j++)
		{
			if ((slen - i - j) < 2) break;
			if ((slen - i - j) > 6) continue;
			for (int k = 1; k <= 3; k++)
			{
				if ((slen - i - j - k) < 1) break;
				if ((slen - i - j - k) > 3) continue;
				//ֱ���жϰ�,md
				int temp;

				if (s.substr(0, 1) == "0")
					if (i != 1) continue;
				temp = atoi(s.substr(0, i).c_str());
				if (temp > 255) continue;

				if (s.substr(i, 1) == "0")
					if (j != 1) continue;
				temp = atoi(s.substr(i, j).c_str());
				if (temp > 255) continue;

				if (s.substr(i + j, 1) == "0")
					if (k != 1) continue;
				temp = atoi(s.substr(i + j, k).c_str());
				if (temp > 255) continue;

				if (s.substr(i + j + k,1) == "0")
					if ((slen - i - j - k) != 1) continue;
				temp = atoi(s.substr(i + j + k).c_str());
				if (temp > 255) continue;

				//�����,md
				string tip = s.substr(0, i) + "." + s.substr(i, j) + "." + s.substr(i + j, k) + "." + s.substr(i + j + k);
				res.push_back(tip);
			}
		}
	}
	return res;
}

vector<int> Solution::inorderTraversal(TreeNode * root)
{
	//��Ч���ֱ�ʾ�����,����˳λ���Ҷ���,null��ʾĳ���ڵ�Ϊ��

	//������,����ջ,��ջʱ�ı�����Ϊ�������,
	//ÿ������һ��NULL��һ��ջ

	//          1
	//
	//       2        5
	//
	//    3    NU
	//
	// NU  4
	//
	//  NU  NU
	///////////////stack:1,5    3 4 2 5 1

	//�Ҳ�֪���ǲ��ǳ���NULL��ʱ��������Ԫ�ؿ���������ջ��,��δ֤��

	//��,ԭ��ֱ������ľ�����

	vector<int> res = {};
	vector<TreeNode> stack = {};
	TreeNode *pre = root;
	while ((pre != nullptr) || !stack.empty())
	{
		if (pre != nullptr)
		{
			stack.push_back(*pre);
			pre = pre->left;
		}
		else
		{
			//����һ��
			pre = &stack[stack.size() - 1];
			stack.pop_back();
			res.push_back(pre->val);
			pre = pre->right;
		}
	}
	return res;
}

vector<TreeNode*> Solution::iter_gen_trees(int n, int m)
{
	if (n == m)
	{
		TreeNode *tn = new TreeNode(n);
		return vector<TreeNode*> {tn};
	}
	else
	{
		//�����ڵ��,���ڵ��n��m,��������None,n,n+1..n��m-1
		//��������n+1....m,None
		vector<TreeNode*> res;
		//������None��,
		vector<TreeNode*> leftnull_sons = iter_gen_trees(n + 1, m);
		for (auto ln : leftnull_sons)
		{
			TreeNode* leftnull = new TreeNode(n);
			leftnull->right = ln;
			res.push_back(leftnull);
		}
		//������None��
		vector<TreeNode*> rightnull_sons = iter_gen_trees(n, m - 1);
		for (auto rn : rightnull_sons)
		{
			TreeNode* rightnull = new TreeNode(m);
			rightnull->left = rn;
			res.push_back(rightnull);
		}
		//����
		for (int i = n + 1; i <= m - 1; i++)
		{
			vector<TreeNode*> leftsons = iter_gen_trees(n, i - 1);
			vector<TreeNode*> rightsons = iter_gen_trees(i + 1, m);
			for (auto left : leftsons)
				for (auto right : rightsons)
				{
					TreeNode* bothside = new TreeNode(i);
					bothside->left = left;
					bothside->right = right;
					res.push_back(bothside);
				}
		}
		return res;
	}
}

vector<TreeNode*> Solution::generateTrees(int n)
{
	if (n <= 0) return vector<TreeNode*> {};

	//�ݹ�,�����ڵ�ݹ�
	return iter_gen_trees(1, n);
}

int Solution::numTrees(int n)
{
	//a(n=18) = ���a(i)*a(17-i) i=0��17
	//a(n=0) = 1
	vector<int> numtrees = { 1,1 };  //numtrees[�±�]��ʾa(n),a(0)=1,a(1)=1

	if (n <= 0) return 0;
	
	for (int i = 2; i <= n; i++)
	{
		int resn = 0;
		for (int j = 0; j < i; j++)
			resn += numtrees[j] * numtrees[i - 1 - j];
		numtrees.push_back(resn);
	}
	return numtrees[n];
}

bool Solution::isInterleave(string s1, string s2, string s3)
{
	//��̬�滮
	//ά��dp[i][j]: i��ʾs1��ǰi���ַ�,j��ʾs2��ǰj���ַ�

	//dp[i][j]��ʾs3��ǰ(i+j)���ַ��Ƿ���s1ǰi �� s2ǰj�������
	//i��jΪ0��ʾ���ַ���

	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = s3.size();

	if ((len1 + len2) != len3) return false;

	if (len1 == 0) return (s2 == s3);
	if (len2 == 0) return (s1 == s3);

	vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
	dp[0][0] = true;

	for (int i = 1; i <= len1; i++)
		dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
	for (int j = 1; j <= len2; j++)
		dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);

	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++)
			dp[i][j] = ((dp[i - 1][j] && (s1[i - 1] == s3[i - 1 + j])) || (dp[i][j - 1] && (s2[j - 1] == s3[j - 1 + i])));

	return dp[len1][len2];
}

bool Solution::isValidBST(TreeNode * root)
{
	//�������,ֻ�����������Ľڵ�,������һ���ڵ�Ƚ�

	int last_num;

	vector<TreeNode> stack = {};
	TreeNode *pre = root;
	//���ҵ���һ��
	while ((pre != nullptr) || !stack.empty())
	{
		if (pre != nullptr)
		{
			stack.push_back(*pre);
			pre = pre->left;
		}
		else
		{
			//����һ��
			pre = &stack[stack.size() - 1];
			stack.pop_back();
			last_num = pre->val;
			pre = pre->right;
			break;
		}
	}

	while ((pre != nullptr) || !stack.empty())
	{
		if (pre != nullptr)
		{
			stack.push_back(*pre);
			pre = pre->left;
		}
		else
		{
			//����һ��
			pre = &stack[stack.size() - 1];
			stack.pop_back();
			if (last_num >= pre->val) return false;
			else last_num = pre->val;
			pre = pre->right;
		}
	}

	return true;
}

#else
#endif

