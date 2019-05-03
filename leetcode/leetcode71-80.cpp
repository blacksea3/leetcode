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

string Solution::minWindow(string s, string t)
{
	//��������,һ�ֵ���

	//����
	unordered_map<char, int> ts;  //t�ڵ��ַ����ɵ��ֵ�
	for (auto tc : t)
		ts[tc]++;
	int tsize = t.size();        //t����

	//��������tֻ��һ���ַ������
	if (tsize == 1)
	{
		for (auto sc : s)
			if (sc == t[0]) return t;
		return "";
	}

	//t����һ���ַ������,��������
	unordered_map<char, int> ps;  //��ǰ�ֵ�
	int left = 0;                //�������±�
	int precount = 0;            //��ǰƥ���ַ�����

	int minlength = 0;           //��С�Ӵ�����
	int start = 0;               //��ʼ
	int end = 0;                 //����,ע���Ӵ���[start,end]˫�պ�����

	for (int right = 0; right < s.size(); right++)
	{
		char sc = s[right];
		if (ts.find(sc) != ts.end()) //�ҵ���
		{
			if (precount == 0)  //������״��ҵ���,�ƶ�left
				left = right;

			if (ps.find(sc) == ps.end())
			{
				precount++;
				ps[sc] = 1;
			}
			else if (ps[sc] >= ts[sc])     //������ps[sc]��������precount
			{
				ps[sc]++;
			}
			else
			{
				ps[sc]++;
				precount++;
			}
			//����Ѿ�ȫ��
			if (precount == tsize)
			{
				//�ڵ�ǰ��Χ�ڻ�ȡ����Ӵ�
				while (true)
				{
					if (ts.find(s[left]) != ts.end())
						if (ps[s[left]] > ts[s[left]])
							ps[s[left]]--;
						else
							break;
					left++;
				}
				if (minlength == 0)
				{
					minlength = (right - left + 1);
					start = left;
					end = right;
				}
				else
				{
					if (minlength > (right - left + 1))
					{
						minlength = (right - left + 1);
						start = left;
						end = right;
					}
				}
				//�ƶ�left
				ps[s[left]]--;
				left++;
				precount--;
				while (ts.find(s[left]) == ts.end()) left++;
			}
		}
	}
	if (minlength == 0) return "";
	else return s.substr(start, (end - start + 1));
}

vector<vector<int>> Solution::combine(int n, int k)
{
	//����

	if (k == 1)
	{
		vector<vector<int>> res(n, vector<int>{});
		for (int i = 1; i <= n; i++)
			res[i - 1].push_back(i);
		return res;
    }

	//init
	//int result_numbers = 1;
	//for (int i = 0; i < k; i++)
	//{
	//	if (n == (i + 1)) break;
	//	result_numbers *= (n - i - 1);
	//}
	vector<vector<int>> res{};
	int preloc = 0;
	vector<vector<int>> stack(1, vector<int>{});
	for (int i = 1; i <= (n-k+1); i++)
		stack[0].push_back(i);
	vector<int> pre_numbers = {};
	int pre_length = 0;

	//��ʽ����
	while ((stack.size() > 1) || (stack[0].size() >= 1))
	{
		if (stack[stack.size() - 1].size() > 0)
		{
			int num = stack[stack.size() - 1][0];
			stack[stack.size() - 1].erase(stack[stack.size() - 1].begin());
			pre_length++;
			pre_numbers.push_back(num);
			if (pre_length == k)
			{
				res.push_back(pre_numbers);
				pre_length--;
				pre_numbers.pop_back();
			}
			else
			{
				vector<int> remaining_nums = {};
				for (int i = num + 1; i <= min(n,n-k+1+pre_length); i++)
				{
					vector<int>::iterator location_index;
					location_index = find(pre_numbers.begin(), pre_numbers.end(), i);
					if (location_index == pre_numbers.end())
						remaining_nums.push_back(i);
				}
				stack.push_back(remaining_nums);
			}
		}
		else
		{
			stack.pop_back();
			pre_length--;
			pre_numbers.pop_back();
		}
	}
	return res;
}

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
	//����nums.size()��bitλ,1��ʾѡȡĳ���±��num,0��ѡȡ

	int nsize = nums.size();

	if (nsize == 0) return vector<vector<int>> {};

	int length = (int)pow(2, nsize);

	vector<vector<int>> res(length, vector<int> {});

	for (int i = 0; i < length; i++)
	{
		vector<int> temp = {};
		for (int j = 0; j < nsize; j++)
		{
			if ((i >> j) % 2 == 1) temp.push_back(nums[j]);
		}
		res[i] = temp;
	}
	return res;
}

vector<pair<int, int>> Solution::get_possible_locations(vector<vector<char>>& board, vector<vector<bool>>& boolboard, int m, int n, int i, int j, char ch)
{
	vector<pair<int, int>> res = {};
	if (i != 0) if ((board[i - 1][j] == ch) && (boolboard[i - 1][j])) res.push_back(pair<int, int>(i - 1, j));
	if (j != 0) if ((board[i][j - 1] == ch) && (boolboard[i][j - 1])) res.push_back(pair<int, int>(i, j - 1));
	if (i != m - 1) if ((board[i + 1][j] == ch) && (boolboard[i + 1][j])) res.push_back(pair<int, int>(i + 1, j));
	if (j != n - 1) if ((board[i][j + 1] == ch) && (boolboard[i][j + 1])) res.push_back(pair<int, int>(i, j + 1));
	return res;
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	//�����������,����

	//ά��һ����ǰboard״̬,�ں��Ѿ��߹���·��,ά��һ���Ѿ��߹��ĳ���
	//ά��һ��pre_locֱ�Ӱ����Ѿ��߹�������
	//ά��һ��stack��ʾ���ߵ�����

	//m��n��
	int m = board.size();
	if (m == 0) return false;
	int n = board[0].size();
	if (n == 0) return false;

	int wsize = word.size();
	vector<vector<bool>> boolboard(m, vector<bool>(n, true));
	int length = 0;
	vector<vector<pair<int, int>>> stack = {};   //����ӵڶ���λ�ÿ�ʼ
	vector<pair<int, int>> pre_loc = {};

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == word[0])
			{
				if (wsize == 1) return true;
				//init
				boolboard[i][j] = false;
				length = 1;
				vector<pair<int, int>> res = get_possible_locations(board, boolboard, m, n, i, j, word[length]);
				if (res.size() == 0)
				{
					boolboard[i][j] = true;
					length = 0;
					continue;
				}
				stack.push_back(res);
				pre_loc = { pair<int,int>(i,j) };

				//�Դ�Ϊ��㿪ʼ����
				while ((stack.size() > 1) || (stack[0].size() >= 1))
				{
					if (stack[stack.size() - 1].size() == 0)
					{
						pair<int, int> temp = pre_loc[pre_loc.size() - 1];
						boolboard[temp.first][temp.second] = true;
						pre_loc.pop_back();
						length--;
						stack.pop_back();
					}
					else
					{
						if (length == (wsize - 1)) return true;
						pair<int, int> temp = stack[stack.size() - 1][stack[stack.size() - 1].size()-1];
						stack[stack.size() - 1].pop_back();
						boolboard[temp.first][temp.second] = false;
						length++;
						pre_loc.push_back(temp);
						vector<pair<int, int>> res = get_possible_locations(board, boolboard, m, n, temp.first, temp.second, word[length]);
						stack.push_back(res);
					}
				}
				//û�ѵ�
				pair<int, int> temp = pre_loc[pre_loc.size() - 1];
				boolboard[temp.first][temp.second] = true;
				pre_loc.pop_back();
				length--;
				stack.pop_back();
			}
		}
	return false;
}

#else
#endif
