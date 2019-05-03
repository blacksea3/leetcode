#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_61_70
ListNode * Solution::rotateRight(ListNode * head, int k)
{
	//为了代码/思路简洁,牺牲效率
	//先搞清楚ListNode有多长

	int length = 1;
	ListNode* lastln = head;
	if (lastln == NULL) return nullptr;

	while (lastln->next != NULL)
	{
		lastln = lastln->next;
		length++;
	}

	//计算出来要移动多远
	k -= ((k / length) * length);
	if (k == 0)
	{
		return head;
	}
	else
	{
		ListNode* dump = new ListNode(0);
		dump->next = head;
		ListNode* anoln = dump;

		int absdis = 1;
		while (absdis <= (length - k))
		{
			anoln = anoln->next;
			absdis++;
		}

		//三指针移动
		lastln->next = dump->next;
		dump->next = anoln->next;
		anoln->next = NULL;
		return dump->next;
	}
}

int Solution::uniquePaths(int m, int n)
{
	//m列n行

	vector<vector<int>> dp(n, vector<int>(m, 0));

	dp[0][0] = 1;

	for (int j = 1; j < m; j++) dp[0][j] = 1;
	for (int i = 1; i < n; i++) dp[i][0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[n - 1][m - 1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	//极端情况
	int n = obstacleGrid.size();
	if (n == 0) return 0;
	int m = obstacleGrid[0].size();
	if (m == 0) return 0;
	if (obstacleGrid[0][0] == 1) return 0;

	//m列n行

	vector<vector<long>> dp(n, vector<long>(m, 0));

	dp[0][0] = 1;

	for (int j = 1; j < m; j++)
	{
		if (obstacleGrid[0][j] == 1) break;
		dp[0][j] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (obstacleGrid[i][0] == 1) break;
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
		{
			if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	return (int)dp[n - 1][m - 1];
}

int Solution::minPathSum(vector<vector<int>>& grid)
{
	//极端情况
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	if (m == 0) return 0;

	//m列n行

	vector<vector<long>> dp(n, vector<long>(m, 0));

	dp[0][0] = grid[0][0];

	for (int j = 1; j < m; j++)
	{
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	return dp[n - 1][m - 1];
}

bool Solution::isNumber(string s)
{
	//去除开头的空格
	int slen = s.size();
	if (slen == 0) return false;
	int loc = 0;


	while (s[loc] == ' ')
	{
		if (loc == slen - 1) return false;  //全是空格
		loc++;
	}

	//去掉末尾空格
	int last = slen - 1;
	while (s[last] == ' ') last--;

	int state = 0;   //0:等待数字或符号或者小数点, 1:(有了符号)等待一个数字或者小数点, 2:已有有效数字/符号组合
	//等待可能的小数点/'e'或者其他数字(或者遍历结束),
	//3:已有小数点,等待e或者其他数字(或者遍历结束, 4:已有e,等待其他数字或者符号,(遍历不能直接结束)
	//5:已有e以及符号,等待其他数字,(遍历不能直接结束)
	//6:已有e,等待其他数字(或者遍历结束)

	bool no_number_before_point = false;   //如果小数点前面没有数字,要是后面也没有数字则返回false
	loc -= 1;

	//注意这里有些技巧,我给loc先减了1,则特别需要注意for的循环次数
	for (int i = loc; i < last; i++)
	{
		loc++;
		switch (state)
		{
		case 0:
		{
			if ((s[loc] == '+') || (s[loc] == '-')) state = 1;
			else if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
			else if (s[loc] == '.')
			{
				state = 3;
				no_number_before_point = true;
			}
			else return false;
			break;
		}
		case 1:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
			else if (s[loc] == '.')
			{
				state = 3;
				no_number_before_point = true;
			}
			else return false;
			break;
		}
		case 2:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0'));
			else if (s[loc] == '.') state = 3;
			else if (s[loc] == 'e') state = 4;
			else return false;
			break;
		}
		case 3:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0')) no_number_before_point = false;
			else if (s[loc] == 'e')
			{
				if (no_number_before_point) return false;
				state = 4;
			}
			else return false;
			break;
		}
		case 4:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
			else if ((s[loc] == '+') || (s[loc] == '-')) state = 5;
			else return false;
			break;
		}
		case 5:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
			else return false;
			break;
		}
		case 6:
		{
			if ((s[loc] <= '9') && (s[loc] >= '0'));
			else return false;
			break;
		}
		}
		}

	switch (state)
	{
	case 0:
	case 1:
	case 4:
	case 5:
		return false;
	case 2:
	case 6:
		return true;
	case 3:
		return !(no_number_before_point);
	default:
		return false;
	}
}

vector<int> Solution::plusOne(vector<int>& digits)
{
	//这是非空数组,不会以0开头
	//倒序遍历
	bool isCarry = true;
	vector<int> res = {};

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (isCarry)
		{
			if (digits[i] == 9) res.insert(res.begin(), 0);
			else
			{
				res.insert(res.begin(), digits[i] + 1);
				isCarry = false;
			}
		}
		else
		{
			res.insert(res.begin(), digits[i]);
		}
	}
	if (isCarry) res.insert(res.begin(), 1);
	return res;
}

string Solution::addBinary(string a, string b)
{
	//非空字符串
	int asize = a.size();
	int bsize = b.size();
	int aloc = asize - 1;
	int bloc = bsize - 1;
	bool carry = false;
	string res = "";

	while ((aloc >= 0) && (bloc >= 0))
	{
		if (!carry)
		{
			if (a[aloc] == b[bloc])
			{
				res = "0" + res;
				if (a[aloc] == '0');
				else carry = true;
			}
			else
			{
				res = "1" + res;
			}
		}
		else
		{
			if (a[aloc] == b[bloc])
			{
				res = "1" + res;
				if (a[aloc] == '0') carry = false;
				else;
			}
			else
			{
				res = "0" + res;
			}
		}
		aloc--;
		bloc--;
	}

	//某个字符串遍历结束了
	if (aloc == -1)
		if (bloc == -1)
			;
		else  //a结束了
		{
			int bloc2 = bloc;
			while (bloc2 >= 0)
			{
				if (!carry)
				{
					if (b[bloc2] == '1') res = "1" + res;
					else res = "0" + res;
				}
				else
				{
					if (b[bloc2] == '1') res = "0" + res;
					else
					{
						res = "1" + res;
						carry = false;
					}
				}
				bloc2--;
			}
		}
	else
	{
		int aloc2 = aloc;
		while (aloc2 >= 0)
		{
			if (!carry)
			{
				if (a[aloc2] == '1') res = "1" + res;
				else res = "0" + res;
			}
			else
			{
				if (a[aloc2] == '1') res = "0" + res;
				else
				{
					res = "1" + res;
					carry = false;
				}
			}
			aloc2--;
		}
	}

	if (carry) res = "1" + res;
	return res;
}

string Solution::genstring_fullJustify(vector<string> words, int maxlength)
{
	//计算可用空格数
	int length = 0;
	for (auto word : words) length += word.size();
	int totalspace = maxlength - length;
	int spacegroupnum = words.size() - 1;
	if (spacegroupnum == 0)  //如果就一个单词,按照左对齐进行
		return genlaststring_fullJustify(words, maxlength);
	int upper_space = totalspace / spacegroupnum;
	int remaining_space = totalspace % spacegroupnum;

	string returns = words[0];
	for (int i = 1; i < (spacegroupnum + 1); i++)
	{
		if (i <= remaining_space)
			for (int j = 0; j < (upper_space + 1); j++)
				returns += " ";
		else
			for (int j = 0; j < upper_space; j++)
				returns += " ";
		returns += words[i];
	}
	return returns;
}

string Solution::genlaststring_fullJustify(vector<string> words, int maxlength)
{
	string returns = words[0];
	for (int i = 1; i < words.size(); i++)
	{
		returns += " ";
		returns += words[i];
	}

	int leftspace = maxlength - returns.size();

	for (int i = 0; i < leftspace; i++)
		returns += " ";
	return returns;
}

vector<string> Solution::fullJustify(vector<string>& words, int maxWidth)
{
	//就是一个状态机
	//至少包含一个单词
	//单词长度<=行长度

	int wsize = words.size();

	vector<string> pre_words = {};
	int pre_length = 0;
	vector<string> res = {};

	for (int i = 0; i < wsize; i++)
	{
		if ((words[i].size() + pre_length) <= maxWidth)
		{
			pre_words.push_back(words[i]);
			pre_length += words[i].size() + 1;
		}
		else
		{
			res.push_back(genstring_fullJustify(pre_words, maxWidth));
			pre_words.clear();
			pre_words.push_back(words[i]);
			pre_length = words[i].size() + 1;
		}
	}

	res.push_back(genlaststring_fullJustify(pre_words, maxWidth));
	return res;
}

int Solution::mySqrt(int x)
{
	//x非负整数
	//牛顿迭代法
	//f(r) = r^2 - x = 0

	//r(n+1) = r(n) - f(r(n))/f'(r(n)) => r(n+1) = r(n) - (r(n)*r(n) - x)/(2*r(n))
	//=> r(n+1) = (r(n)+x/r(n))/2

	if (x <= 1) return x;

	int r = x;
	while (r > x / r)
		r = (int)(((long)r + x / r) / 2);

	return r;
}

int Solution::climbStairs(int n)
{
	//emmmm,迭代,就是动态规划

	if (n == 1) return 1;
	if (n == 2) return 2;

	bool is_n1_smaller = true;
	int n1 = 1;
	int n2 = 2;
	for (int i = 2; i < n; i++)
	{
		if (is_n1_smaller) n1 = (n1 + n2);
		else n2 = (n1 + n2);
		is_n1_smaller = !is_n1_smaller;
	}

	return (is_n1_smaller) ? n2 : n1;
}
#else
#endif
