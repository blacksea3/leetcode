#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_61_70
ListNode * Solution::rotateRight(ListNode * head, int k)
{
	//Ϊ�˴���/˼·���,����Ч��
	//�ȸ����ListNode�ж೤

	int length = 1;
	ListNode* lastln = head;
	if (lastln == NULL) return nullptr;

	while (lastln->next != NULL)
	{
		lastln = lastln->next;
		length++;
	}

	//�������Ҫ�ƶ���Զ
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

		//��ָ���ƶ�
		lastln->next = dump->next;
		dump->next = anoln->next;
		anoln->next = NULL;
		return dump->next;
	}
}

int Solution::uniquePaths(int m, int n)
{
	//m��n��

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
	//�������
	int n = obstacleGrid.size();
	if (n == 0) return 0;
	int m = obstacleGrid[0].size();
	if (m == 0) return 0;
	if (obstacleGrid[0][0] == 1) return 0;

	//m��n��

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
	//�������
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	if (m == 0) return 0;

	//m��n��

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
	//ȥ����ͷ�Ŀո�
	int slen = s.size();
	if (slen == 0) return false;
	int loc = 0;


	while (s[loc] == ' ')
	{
		if (loc == slen - 1) return false;  //ȫ�ǿո�
		loc++;
	}

	//ȥ��ĩβ�ո�
	int last = slen - 1;
	while (s[last] == ' ') last--;

	int state = 0;   //0:�ȴ����ֻ���Ż���С����, 1:(���˷���)�ȴ�һ�����ֻ���С����, 2:������Ч����/�������
	//�ȴ����ܵ�С����/'e'������������(���߱�������),
	//3:����С����,�ȴ�e������������(���߱�������, 4:����e,�ȴ��������ֻ��߷���,(��������ֱ�ӽ���)
	//5:����e�Լ�����,�ȴ���������,(��������ֱ�ӽ���)
	//6:����e,�ȴ���������(���߱�������)

	bool no_number_before_point = false;   //���С����ǰ��û������,Ҫ�Ǻ���Ҳû�������򷵻�false
	loc -= 1;

	//ע��������Щ����,�Ҹ�loc�ȼ���1,���ر���Ҫע��for��ѭ������
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
	//���Ƿǿ�����,������0��ͷ
	//�������
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
	//�ǿ��ַ���
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

	//ĳ���ַ�������������
	if (aloc == -1)
		if (bloc == -1)
			;
		else  //a������
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
	//������ÿո���
	int length = 0;
	for (auto word : words) length += word.size();
	int totalspace = maxlength - length;
	int spacegroupnum = words.size() - 1;
	if (spacegroupnum == 0)  //�����һ������,������������
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
	//����һ��״̬��
	//���ٰ���һ������
	//���ʳ���<=�г���

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
	//x�Ǹ�����
	//ţ�ٵ�����
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
	//emmmm,����,���Ƕ�̬�滮

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
