#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_71_80
string Solution::simplifyPath(string path)
{
	vector<string> stack = {};

	//顺序遍历path
	//注意到绝对路径,那么总是以反斜杠开头
	//认为输入是合法的:总是有字母串或者单独一个点或者单独两个点夹在多个不定数量的反斜杠中间
	//且可能由不定数量的反斜杠的反斜杠结尾,或者直接结尾
	//末尾的单个点与两个点也起作用,即使没有以反斜杠结尾

	int state = 0; //0:前面是反斜杠,准备获取字母/点 1:前面是单个点 2:前面是两个点 3:前面是字母

	if (path.size() == 1) return path;  //这只可能是单个反斜杠

	string prestr = "";
	for (int i = 1; i < path.size(); i++)
	{
		switch (state)
		{
		case 0:
		{
			if (path[i] == '/');
			else if (path[i] == '.') state = 1;
			else
			{
				prestr = path[i];
				state = 3;
			}
			break;
		}
		case 1:
		{
			if (path[i] == '/') state = 0;
			else if (path[i] == '.') state = 2;
			else
			{
				prestr = ".";
				prestr += path[i];
				state = 3;
			}
			break;
		}
		case 2:
		{
			if (path[i] == '/')
			{
				if (stack.size() != 0) stack.pop_back();
				state = 0;
			}
			else
			{
				prestr = "..";
				prestr += path[i];
				state = 3;
			}
			break;
		}
		case 3:
		{
			if (path[i] == '/')
			{
				stack.push_back(prestr);
				prestr = "";
				state = 0;
			}
			else prestr += path[i];
			break;
		}
		default:
		{
			break;
		}
		}
	}

	switch (state)
	{
	case 0:
	case 1:
		break;
	case 2:
	{
		if (stack.size() != 0) stack.pop_back();
		break;
	}
	case 3:
		stack.push_back(prestr);
	}

	if (stack.size() == 0) return "/";

	string returns = "";
	for (int i = 0; i < stack.size(); i++)
	{
		returns += "/";
		returns += stack[i];
	}
	return returns;
}

int Solution::minDistance(string word1, string word2)
{
	//注意到仅操纵最后一个字符:从word1[0:i]变到word2[0:j]有三种方法

	//如果word1[i] == word2[j] 则需要word[0:i-1]变到word[0:j-1]步
	//否则需要word[0:i-1]变到word[0:j-1]再加一步,(word1[i] -> word2[j])

	//或者是word[0:i]变到word[0:j-1]之后的步数加上word[j]的这一步

	//或者是删掉word1[i]这一步然后加上word[0:i-1]变到word[0:j]之后的步数

	//动态规划,选取i,j下标即可
	//注意选取的i,j下标是真实下标+1,选取的ij下标为0表示空字符串!

	int size1 = word1.size();
	int size2 = word2.size();

	vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

	for (int i = 0; i <= size1; i++)
		dp[i][0] = i;
	for (int j = 0; j <= size2; j++)
		dp[0][j] = j;

	for (int i = 1; i <= size1; i++)
		for (int j = 1; j <= size2; j++)
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

	return dp[size1][size2];
}

void Solution::setZeroes(vector<vector<int>>& matrix)
{
	//使用矩阵的第一行和第一列存储需要调到0的列数和行数

	//m行n列

	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();
	if (n == 0) return;

	bool isrow0_needset0 = false;
	bool iscolumn0_needset0 = false;
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			iscolumn0_needset0 = true;
			break;
		}
	}

	for (int j = 0; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			isrow0_needset0 = true;
			break;
		}
	}

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}

	for (int i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
			for (int j = 1; j < n; j++)
				matrix[i][j] = 0;
	}

	for (int j = 1; j < n; j++)
	{
		if (matrix[0][j] == 0)
			for (int i = 1; i < m; i++)
				matrix[i][j] = 0;
	}

	if (isrow0_needset0)
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;

	if (iscolumn0_needset0)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	//两次二分查找
	//m行n列
	int m = matrix.size();
	if (m == 0) return false;
	int n = matrix[0].size();
	if (n == 0) return false;

	//查找在第几行
	int up = 0;
	int down = m - 1;
	int mid = 0;
	while (up <= down)
	{
		mid = (up + down) / 2;
		if (matrix[mid][0] < target) up = mid + 1;
		else if (matrix[mid][0] > target) down = mid - 1;
		else return true;
	}

	if (down == -1) return false;

	//查找在第几列
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (matrix[down][mid] < target) left = mid + 1;
		else if (matrix[down][mid] > target) right = mid - 1;
		else return true;
	}
	return false;
}

void Solution::sortColors(vector<int>& nums)
{
	//三路排序
	int nsize = nums.size();
	if (nsize == 0) return;

	int number_0loc = 0;   //下一个0的坐标
	int number_2loc = nsize - 1;  //下一个2的坐标

	int loc = 0;
	while (loc <= number_2loc)
	{
		while (nums[loc] != 1)
		{
			if (nums[loc] == 0)
				if (loc != number_0loc)
				{
					int temp = nums[number_0loc];
					nums[number_0loc] = 0;
					nums[loc] = temp;
					number_0loc++;
				}
				else break;
			else
			{
				if (loc != number_2loc)
				{
					int temp = nums[number_2loc];
					nums[number_2loc] = 2;
					nums[loc] = temp;
					number_2loc--;
				}
				else break;
			}
		}
		loc++;
	}
}

#else
#endif
