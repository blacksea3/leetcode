#include "include.h"

#ifdef LEETCODE_121_130
#include "public.h"
#include "leetcode.h"

int Solution::maxProfit(vector<int>& prices)
{
	//һ�����,��ס���±�1��ʼ������Ԫ��֮ǰ����СԪ�ز����뵱ǰԪ�رȽϼ���

	int psize = prices.size();
	int res = 0;
	int premin = INT_MAX;
	for (int i = 1; i < psize; i++)
	{
		premin = min(premin, prices[i - 1]);
		res = max(res, prices[i] - premin);
	}
	return res;
}

int Solution::maxProfit_122(vector<int>& prices)
{
	//ֻҪ��һ���ǰһ��۸��,������
	int res = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
	}
	return res;
}

int Solution::maxProfit_123(vector<int>& prices)
{
	//�ο����˵Ķ�̬�滮
	//ֻ��Ҫ��ͼ����������,�������,��������Ʊ��������
	//dp[i][j]:��i+1��,��Ʊ��������(0:��,1����һ��,2����һ��,3����һ��Ȼ�����һ��,4��������)���������(������Ǹ���,���������ʱ)

	if (prices.size() == 0) return 0;

	vector<vector<int>> dp(prices.size(), vector<int>(5, 0));

	//init
	dp[0][1] = -1 * prices[0];
	dp[0][3] = -1 * prices[0];
	//����ǰ�����зǷ����,��ʵ���ϲ�Ҫ��:)
	for (int i = 1; i < prices.size(); i++)
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
		dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
		dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
	}

	return max(dp[prices.size() - 1][0], max(dp[prices.size() - 1][2], dp[prices.size() - 1][4]));
}

int Solution::res = INT_MIN;

//����first:�Ƿ���˫�ڵ�
int Solution::iter_maxPathSum(TreeNode* root)
{
	//ע�⵽:������һ���ڵ�,�������·��������,��ô����:�������������� ���� ��������/������ ���ϸ�����
	if (root == nullptr) return 0;
	int left = max(0, iter_maxPathSum(root->left));  //����������Ǹ���,��ô�ͱ��������
	int right = max(0, iter_maxPathSum(root->right));  //����������Ǹ���,��ô�ͱ��������
	res = max(res, left + right + root->val);   //����,��������ж�һ�ε�ǰroot�������������ǲ�������!!!!!!!
	return max(left, right) + root->val;
}

int Solution::maxPathSum(TreeNode * root)
{
	//���õݹ���
	iter_maxPathSum(root);
	return res;
}

bool Solution::isPalindrome(string s)
{
	//����ͬʱ���м�ɨ

	int left = 0;
	int right = s.size() - 1;

	while (left < right)
	{
		if (!(((s[left] <= '9') && (s[left] >= '0')) || ((s[left] >= 'A') && (s[left] <= 'Z')) || ((s[left] >= 'a') && (s[left] <= 'z'))))
			left++;
		else if (!(((s[right] <= '9') && (s[right] >= '0')) || ((s[right] >= 'A') && (s[right] <= 'Z')) || ((s[right] >= 'a') && (s[right] <= 'z'))))
			right--;
		else
		{
			if ((s[left] <= '9') && (s[left] >= '0'))
				if (s[left] != s[right]) return false;
				else
				{
					left++;
					right--;
				}
			else if ((s[left] <= 'Z') && (s[left] >= 'A'))
				if (s[left] == s[right])
				{
					left++;
					right--;
				}
				else if (s[left] == (s[right]) - ('a' - 'A'))
				{
					left++;
					right--;
				}
				else return false;
			else
				if (s[left] == s[right])
				{
					left++;
					right--;
				}
				else if (s[left] == (s[right]) - ('A' - 'a'))
				{
					left++;
					right--;
				}
				else return false;
		}
	}
	return true;
}

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{

	if (wordList.size() = 0) return 0;

	//�����������,ת����ͼ
	//ʹ���ڽ��б���ͼ�ṹ
	unordered_map(string, vector<string>) graph;
	int wsize = wordList[0].size();
	bool isdifferent;

	//����ͼ�ṹ
	for (int i = 0; i < wordList.size(); i++)
	{
		vector<string> nodes{};
		for (int j = 0; j < wordList.size(); j++)
		{
			if (j == i) continue;
			isdifferent = false; //true��ʾ�в�ͬ��,trueʱ����ٲ�ͬ��������ǰѭ��
			for (int k = 0; k < wsize; k++)
			{
				if (wordList[i][k] != wordList[j][k])
				{
					if (isdifferent) goto smallbreak;
					else isdifferent = true;
				}
			}
			//�������ʾ�����ڵ���������
			nodes.push_back(wordList[j]);
		smallbreak:;
		}
		graph[wordList[i]] = nodes;
	}

	//�����������
	vector<pair<string, int>> stack; //��������ڵ�
	//�������
	vector<string> initnodes{};
	for (int j = 0; j < wordList.size(); j++)
	{
		isdifferent = false; //true��ʾ�в�ͬ��,trueʱ����ٲ�ͬ��������ǰѭ��
		for (int k = 0; k < wsize; k++)
		{
			if (beginWord[k] != wordList[j][k])
			{
				if (isdifferent) goto smallbreak2;
				else isdifferent = true;
			}
		}
		//�������ʾ�����ڵ���������
		initnodes.push_back(wordList[j]);
	smallbreak2:;
	}

	vector<string> usednodes = initnodes;
	stack.push_back(initnodes);
	int step = 1;
	while (!stack.empty())
	{
		//д������......
	}

	return 0;
}

#else
#endif
