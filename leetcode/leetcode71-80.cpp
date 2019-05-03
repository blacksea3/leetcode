#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_71_80
string Solution::simplifyPath(string path)
{
	vector<string> stack = {};

	//˳�����path
	//ע�⵽����·��,��ô�����Է�б�ܿ�ͷ
	//��Ϊ�����ǺϷ���:��������ĸ�����ߵ���һ������ߵ�����������ڶ�����������ķ�б���м�
	//�ҿ����ɲ��������ķ�б�ܵķ�б�ܽ�β,����ֱ�ӽ�β
	//ĩβ�ĵ�������������Ҳ������,��ʹû���Է�б�ܽ�β

	int state = 0; //0:ǰ���Ƿ�б��,׼����ȡ��ĸ/�� 1:ǰ���ǵ����� 2:ǰ���������� 3:ǰ������ĸ

	if (path.size() == 1) return path;  //��ֻ�����ǵ�����б��

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
	//ע�⵽���������һ���ַ�:��word1[0:i]�䵽word2[0:j]�����ַ���

	//���word1[i] == word2[j] ����Ҫword[0:i-1]�䵽word[0:j-1]��
	//������Ҫword[0:i-1]�䵽word[0:j-1]�ټ�һ��,(word1[i] -> word2[j])

	//������word[0:i]�䵽word[0:j-1]֮��Ĳ�������word[j]����һ��

	//������ɾ��word1[i]��һ��Ȼ�����word[0:i-1]�䵽word[0:j]֮��Ĳ���

	//��̬�滮,ѡȡi,j�±꼴��
	//ע��ѡȡ��i,j�±�����ʵ�±�+1,ѡȡ��ij�±�Ϊ0��ʾ���ַ���!

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
	//ʹ�þ���ĵ�һ�к͵�һ�д洢��Ҫ����0������������

	//m��n��

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
	//���ζ��ֲ���
	//m��n��
	int m = matrix.size();
	if (m == 0) return false;
	int n = matrix[0].size();
	if (n == 0) return false;

	//�����ڵڼ���
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

	//�����ڵڼ���
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
	//��·����
	int nsize = nums.size();
	if (nsize == 0) return;

	int number_0loc = 0;   //��һ��0������
	int number_2loc = nsize - 1;  //��һ��2������

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
