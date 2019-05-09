#include "include.h"

#ifdef LEETCODE_121_130
#include "public.h"
#include "leetcode.h"

int Solution::maxProfit(vector<int>& prices)
{
	//一遍遍历,记住从下标1开始的所有元素之前的最小元素并且与当前元素比较即可

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
	//只要后一天比前一天价格高,就卖出
	int res = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
	}
	return res;
}

int Solution::maxProfit_123(vector<int>& prices)
{
	//参考别人的动态规划
	//只需要试图求出所有情况,按天遍历,按买卖股票次数遍历
	//dp[i][j]:第i+1天,股票操作次数(0:无,1仅买一次,2买卖一次,3买卖一次然后仅买一次,4买卖两次)的最大利润(这可能是负的,在买入情况时)

	if (prices.size() == 0) return 0;

	vector<vector<int>> dp(prices.size(), vector<int>(5, 0));

	//init
	dp[0][1] = -1 * prices[0];
	dp[0][3] = -1 * prices[0];
	//可能前几天有非法情况,这实际上不要紧:)
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

//返回first:是否是双节点
int Solution::iter_maxPathSum(TreeNode* root)
{
	//注意到:对任意一个节点,如果最大和路径包含它,那么可能:它加上左右子树 或者 它加上左/右子树 加上父亲们
	if (root == nullptr) return 0;
	int left = max(0, iter_maxPathSum(root->left));  //如果左子树是负的,那么就别包含它了
	int right = max(0, iter_maxPathSum(root->right));  //如果右子树是负的,那么就别包含它了
	res = max(res, left + right + root->val);   //核心,这里必须判断一次当前root加上左右子树是不是最大的!!!!!!!
	return max(left, right) + root->val;
}

int Solution::maxPathSum(TreeNode * root)
{
	//先用递归跑
	iter_maxPathSum(root);
	return res;
}

bool Solution::isPalindrome(string s)
{
	//左右同时向中间扫

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

vector<string> Solution::adjacent_string(string word, unordered_set<string>& wordList)
{
	int wsize = word.size();
	bool isdifferent;
	vector<string> res = {};
	auto iter = wordList.begin();
	while (iter != wordList.end())
	{
		isdifferent = false; //true表示有不同的,true时如果再不同则跳过当前循环
		for (int k = 0; k < wsize; k++)
		{
			if (word[k] != (*iter)[k])
			{
				if (isdifferent) goto smallbreak;
				else isdifferent = true;
			}
		}
		//到这里表示两个节点连起来了,应该记录
		res.push_back((*iter));
		iter = wordList.erase(iter);
		continue;
	smallbreak:
		//到这里表示两节点不能连起来
		iter++;
	}
	return res;
}

bool Solution::onechar_different(string note, unordered_set<string>& wordList)
{
	for (int i = 0; i < note.size(); i++)
	{
		string temp = note;
		for (char c = 'a'; c <= 'z'; c++)
		{
			temp[i] = c;
			if (wordList.find(temp) != wordList.end()) return true;
		}
	}
	return false;
}

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordDict(wordList.begin(), wordList.end());

	if (wordList.size() == 0) return 0;
	if (wordDict.find(endWord) == wordDict.end()) return 0;

	//广度优先搜索,转换成图
	//使用邻接列表创建图结构
	//unordered_map<string, vector<string>> graph;
	int wsize = wordList[0].size();
	bool isdifferent;

	//生成图结构
	//不要先完整生成图,而是应该动态生成图

	//广度优先搜索,双端搜索
	//vector<string> stack; //存放搜索节点
	//搜索起点
	unordered_set<string> beginset = { beginWord };
	unordered_set<string> endset = { endWord };

	int res = 2;
	while (!(beginset.empty()))
	{
		unordered_set<string> pre;
		for (auto note : beginset)
		{
			if (onechar_different(note, endset)) return res;
			vector<string> adjacentstring = adjacent_string(note, wordDict);

			for (auto tempstring : adjacentstring)
				pre.insert(tempstring);
		}
		if (pre.size() > endset.size())
		{
			beginset = endset;
			endset = pre;
		}
		else
		{
			beginset = pre;
		}
		res++;
	}
	return 0;
}

int Solution::longestConsecutive(vector<int>& nums)
{
	//对每个点都记录此点所在的最长连续序列的长度
	//注意在哈希表中,仅仅只有某最长连续序列的两个端点长度是有效的,中间点的长度实际上是错的,而且也用不着

	unordered_map<int, int> d;
	int maxlength = 0;
	for (auto num : nums)
	{
		if (d.find(num) == d.end() )
		{
			int left;
			int right;
			if (d.find(num - 1) == d.end())
				left = 0;
			else
				left = d[num - 1];
			if (d.find(num + 1) == d.end())
				right = 0;
			else
				right = d[num + 1];
			int curlength = 1 + left + right;
			maxlength = max(maxlength, curlength);
			d[num] = curlength;   
			d[num - left] = curlength;
			d[num + right] = curlength;
		}
	}
	return maxlength;
}

#else
#endif
