#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_51_60

vector<string> Solution::generate_Queens_string(vector<int> input)
{
	int isize = input.size();
	string dumpstr = "";
	for (int i = 0; i < isize; i++)
	{
		dumpstr += ".";
	}
	vector<string> returnstr(isize, dumpstr);
	for (int i = 0; i < isize; i++)
	{
		returnstr[i][input[i]] = 'Q';
	}
	return returnstr;
}

vector<int> Solution::generate_Queens_nextlineloc(vector<int> input, int n)
{
	vector<int> returnv = {};
	int isize = input.size();
	for (int i = 0; i < n; i++)
	{
		returnv.push_back(i);
	}

	//������б����
	for (int i = 0; i < isize; i++)
	{
		vector<int>::iterator it = find(returnv.begin(), returnv.end(), input[i]);
		if (it != returnv.end()) returnv.erase(it);

		it = find(returnv.begin(), returnv.end(), input[i] - (isize - i));
		if (it != returnv.end()) returnv.erase(it);

		it = find(returnv.begin(), returnv.end(), input[i] + (isize - i));
		if (it != returnv.end()) returnv.erase(it);
	}
	return returnv;
}

vector<vector<string>> Solution::solveNQueens(int n)
{
	//ֱ��/б�������һ���ʺ�
	//�����㷨

	//ʵ����,ֻҪÿһ�ж����˻ʺ�,��ô�����һ����
	//����Ӧ��"����"�������

	//���б���δ��������λ��,��i���±��ʾ��i+1�е�λ��
	//�б���������,���չ������ӿ��ܵ�λ��

	vector<vector<int>> stack = {};
	vector<int> fullloc = {};
	vector<vector<string>> total_res = {};
	vector<int> pre_res = {}; //loc:(y) range:[0,n-1], ע�⵽��i�±��ʾ��i+1��
	int count = 0;

	for (int i = 0; i < n; i++) fullloc.push_back(i);

	bool need_recall = false;

	if (n >= 2)
	{
		//init stack
		stack.push_back(fullloc);

		//����
		while ((stack.size() > 1) || (stack[0].size() > 0))
		{
			if (stack[count].size() > 0)   //��ǰ��λ��,�������
			{
				//�����λ��,��ʱ��λ��һ���ǺϷ���,��Ϊ�Ǵ�ջ��ȡ����
				//���µ������߼���count��־��pre_res������±���stack������±�
				pre_res.push_back(stack[count][0]);
				stack[count].erase(stack[count].begin());
				//�ƶ�count
				count++;

				if (count == n) //������!
				{
					total_res.push_back(generate_Queens_string(pre_res));
					//ɾ����ǰλ��,����һ�������Ի�ȡ��������λ��
					pre_res.pop_back();
					count--;
				}
				else
				{
					//Ѱ�ҿ��ÿ�λ,
					vector<int> possible_loc = generate_Queens_nextlineloc(pre_res, n);
					//�����,��stack��Ԫ��,����ѭ��
					if (possible_loc.size() > 0)
						stack.push_back(possible_loc);
					//����ɾ����ǰλ��,����һ�������Ի�ȡ��������λ��
					else
					{
						pre_res.pop_back();
						count--;
					}
				}
			}
			else  //ɾ����ǰ������,�ص���һ��
			{
				stack.pop_back();
				pre_res.pop_back();
				count--;
			}
		}
		return total_res;
	}
	else return vector<vector<string>> { {"Q"}};
}

int Solution::totalNQueens(int n)
{
	//ֱ��/б�������һ���ʺ�
	//�����㷨

	//ʵ����,ֻҪÿһ�ж����˻ʺ�,��ô�����һ����
	//����Ӧ��"����"�������

	//���б���δ��������λ��,��i���±��ʾ��i+1�е�λ��
	//�б���������,���չ������ӿ��ܵ�λ��

	vector<vector<int>> stack = {};
	vector<int> fullloc = {};
	int total_res = 0;
	vector<int> pre_res = {}; //loc:(y) range:[0,n-1], ע�⵽��i�±��ʾ��i+1��
	int count = 0;

	for (int i = 0; i < n; i++) fullloc.push_back(i);

	bool need_recall = false;

	if (n >= 2)
	{
		//init stack
		stack.push_back(fullloc);

		//����
		while ((stack.size() > 1) || (stack[0].size() > 0))
		{
			if (stack[count].size() > 0)   //��ǰ��λ��,�������
			{
				//�����λ��,��ʱ��λ��һ���ǺϷ���,��Ϊ�Ǵ�ջ��ȡ����
				//���µ������߼���count��־��pre_res������±���stack������±�
				pre_res.push_back(stack[count][0]);
				stack[count].erase(stack[count].begin());
				//�ƶ�count
				count++;

				if (count == n) //������!
				{
					total_res++;
					//ɾ����ǰλ��,����һ�������Ի�ȡ��������λ��
					pre_res.pop_back();
					count--;
				}
				else
				{
					//Ѱ�ҿ��ÿ�λ,
					vector<int> possible_loc = generate_Queens_nextlineloc(pre_res, n);
					//�����,��stack��Ԫ��,����ѭ��
					if (possible_loc.size() > 0)
						stack.push_back(possible_loc);
					//����ɾ����ǰλ��,����һ�������Ի�ȡ��������λ��
					else
					{
						pre_res.pop_back();
						count--;
					}
				}
			}
			else  //ɾ����ǰ������,�ص���һ��
			{
				stack.pop_back();
				pre_res.pop_back();
				count--;
			}
		}
		return total_res;
	}
	else return 1;
}

int Solution::maxSubArray(vector<int>& nums)
{
	int res = nums[0];
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum > 0) sum += nums[i];
		else sum = nums[i];
		res = (res < sum) ? sum : res;
	}
	return res;
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
	//�ĸ��������
	int dir = 0; //0�� 1�� 2�� 3:��

	int m = matrix.size();
	if (m == 0) return vector<int>{};
	int n = matrix[0].size();
	if (n == 0) return vector<int>{};

	//�ĸ��������
	int left_border = 0;
	int right_border = n - 1;
	int up_border = 0;
	int down_border = m - 1;
	int prex = 0;
	int prey = 0;
	vector<int> res(m*n, 0);
	int count = 0;
	while ((right_border >= left_border) && (down_border >= up_border))
	{
		switch (dir)
		{
		case 0:
		{
			res[count++] = matrix[prex][prey];
			if (prey == right_border)
			{
				dir = 1;
				prex++;
				up_border++;
			}
			else prey++;
			break;
		}
		case 1:
		{
			res[count++] = matrix[prex][prey];
			if (prex == down_border)
			{
				dir = 2;
				prey--;
				right_border--;
			}
			else prex++;
			break;
		}
		case 2:
		{
			res[count++] = matrix[prex][prey];
			if (prey == left_border)
			{
				dir = 3;
				prex--;
				down_border--;
			}
			else prey--;
			break;
		}
		case 3:
		{
			res[count++] = matrix[prex][prey];
			if (prex == up_border)
			{
				dir = 0;
				prey++;
				left_border++;
			}
			else prex--;
			break;
		}
		default: break;
		}
	}
	return res;
}

bool Solution::canJump(vector<int>& nums)
{
	//�Ӻ����,����������������ǰλ�õ�ǰ��ڵ�,����º��յ�ڵ�(��ǰ�ڵ�)�ٴα���,
	//ֱ��������ͷ��!,�鿴��ǰ�ڵ�������

	if (nums.size() == 1) return true;

	int preloc = nums.size() - 1;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if ((nums[i] + i) >= preloc) preloc = i;
	}
	return (preloc == 0);
}

bool Solution::LessEqSort(vector<int> a, vector<int> b)
{
	return (a[0] <= b[0]);
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	//�������
	if (intervals.size() == 0) return vector<vector<int>>{};

	//��߽�����
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> res = { intervals[0] };

	for (int i = 1; i < intervals.size(); i++)
	{
		if (res[res.size() - 1][1] >= intervals[i][0])
			res[res.size() - 1][1] = (intervals[i][1] >= res[res.size() - 1][1]) ? intervals[i][1] : res[res.size() - 1][1];
		else
			res.push_back(intervals[i]);
	}
	return res;
}

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
	vector<vector<int>> res;
	bool merge = false;
	for (auto & i : intervals) {
		if (i[1] < newInterval[0]) {
			res.push_back(i);
		}
		else if (i[0] > newInterval[1]) {
			if (!merge) {
				merge = true;
				res.push_back(newInterval);
			}
			res.push_back(i);
		}
		else {
			newInterval[0] = min(i[0], newInterval[0]);
			newInterval[1] = max(i[1], newInterval[1]);
		}
	}
	if (!merge) res.push_back(newInterval);
	return res;
}

int Solution::lengthOfLastWord(string s)
{
	//ȥ��ĩβ�ո�
	int ssize = s.size();
	int loc = ssize - 1;
	int res = 0;

	while (loc >= 0)
	{
		if (s[loc] != ' ') break;
		loc--;
	}

	if (loc == -1) return 0;
	else
	{
		while (loc >= 0)
		{
			if (s[loc] == ' ') break;
			loc--;
			res++;
		}
	}
	return res;
}

vector<vector<int>> Solution::generateMatrix(int n)
{
	//��������

	int up_border = 0;
	int down_border = n - 1;
	int left_border = 0;
	int right_border = n - 1;
	int dir = 0;

	vector<vector<int>> res(n, vector<int>(n, 0));
	int count = 1;
	int prex = 0;
	int prey = 0;

	while ((right_border >= left_border) && (down_border >= up_border))
	{
		switch (dir)
		{
		case 0:
		{
			res[prex][prey] = count++;
			if (prey == right_border)
			{
				dir = 1;
				prex++;
				up_border++;
			}
			else prey++;
			break;
		}
		case 1:
		{
			res[prex][prey] = count++;
			if (prex == down_border)
			{
				dir = 2;
				prey--;
				right_border--;
			}
			else prex++;
			break;
		}
		case 2:
		{
			res[prex][prey] = count++;
			if (prey == left_border)
			{
				dir = 3;
				prex--;
				down_border--;
			}
			else prey--;
			break;
		}
		case 3:
		{
			res[prex][prey] = count++;
			if (prex == up_border)
			{
				dir = 0;
				prey++;
				left_border++;
			}
			else prex--;
			break;
		}
		default: break;
		}
	}
	return res;

}

string Solution::getPermutation(int n, int k)
{
	if (n == 1) return "1";
	if (n == 2) return (k == 1) ? "12" : "21";

	//n:3   2=1*2+0*1

	//ע�⵽n��Χ��1��9
	vector<int> factorial = { 1,1,2,6,24,120,720,5040,40320 };
	vector<int> res(n - 1, 0);

	//k = A*(n-1)! + B*(n-2)! + ....
	int countloc = 0;
	for (int i = n - 1; i >= 2; i--)
	{
		res[countloc] = (k - 1) / factorial[i];
		k -= res[countloc] * factorial[i];
		countloc++;
	}
	res[countloc] = k-1;

	string returns = "";
	vector<char> nums = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < n - 1; i++)
	{
		returns += nums[res[i]];
		nums.erase(nums.begin() + res[i]);
	}
	returns += nums[0];

	return returns;
}

#else
#endif


