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

	//按列与斜线找
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
	//直线/斜线上最多一个皇后
	//回溯算法

	//实际上,只要每一行都放了皇后,那么这就是一个解
	//我们应该"遍历"所有情况

	//用列表存放未遍历到的位置,第i个下标表示第i+1行的位置
	//列表新增内容,按照规则增加可能的位置

	vector<vector<int>> stack = {};
	vector<int> fullloc = {};
	vector<vector<string>> total_res = {};
	vector<int> pre_res = {}; //loc:(y) range:[0,n-1], 注意到第i下标表示第i+1行
	int count = 0;

	for (int i = 0; i < n; i++) fullloc.push_back(i);

	bool need_recall = false;

	if (n >= 2)
	{
		//init stack
		stack.push_back(fullloc);

		//此外
		while ((stack.size() > 1) || (stack[0].size() > 0))
		{
			if (stack[count].size() > 0)   //当前有位置,无需回溯
			{
				//放入此位置,此时的位置一定是合法的,因为是从栈中取出的
				//以下的两句逻辑上count标志着pre_res的最大下标与stack的最大下标
				pre_res.push_back(stack[count][0]);
				stack[count].erase(stack[count].begin());
				//移动count
				count++;

				if (count == n) //放满了!
				{
					total_res.push_back(generate_Queens_string(pre_res));
					//删掉当前位置,在下一迭代尝试获取本层其他位置
					pre_res.pop_back();
					count--;
				}
				else
				{
					//寻找可用空位,
					vector<int> possible_loc = generate_Queens_nextlineloc(pre_res, n);
					//如果有,给stack加元素,接着循环
					if (possible_loc.size() > 0)
						stack.push_back(possible_loc);
					//否则删掉当前位置,在下一迭代尝试获取本层其他位置
					else
					{
						pre_res.pop_back();
						count--;
					}
				}
			}
			else  //删除当前空数组,回到上一层
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
	//直线/斜线上最多一个皇后
	//回溯算法

	//实际上,只要每一行都放了皇后,那么这就是一个解
	//我们应该"遍历"所有情况

	//用列表存放未遍历到的位置,第i个下标表示第i+1行的位置
	//列表新增内容,按照规则增加可能的位置

	vector<vector<int>> stack = {};
	vector<int> fullloc = {};
	int total_res = 0;
	vector<int> pre_res = {}; //loc:(y) range:[0,n-1], 注意到第i下标表示第i+1行
	int count = 0;

	for (int i = 0; i < n; i++) fullloc.push_back(i);

	bool need_recall = false;

	if (n >= 2)
	{
		//init stack
		stack.push_back(fullloc);

		//此外
		while ((stack.size() > 1) || (stack[0].size() > 0))
		{
			if (stack[count].size() > 0)   //当前有位置,无需回溯
			{
				//放入此位置,此时的位置一定是合法的,因为是从栈中取出的
				//以下的两句逻辑上count标志着pre_res的最大下标与stack的最大下标
				pre_res.push_back(stack[count][0]);
				stack[count].erase(stack[count].begin());
				//移动count
				count++;

				if (count == n) //放满了!
				{
					total_res++;
					//删掉当前位置,在下一迭代尝试获取本层其他位置
					pre_res.pop_back();
					count--;
				}
				else
				{
					//寻找可用空位,
					vector<int> possible_loc = generate_Queens_nextlineloc(pre_res, n);
					//如果有,给stack加元素,接着循环
					if (possible_loc.size() > 0)
						stack.push_back(possible_loc);
					//否则删掉当前位置,在下一迭代尝试获取本层其他位置
					else
					{
						pre_res.pop_back();
						count--;
					}
				}
			}
			else  //删除当前空数组,回到上一层
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
	//四个方向遍历
	int dir = 0; //0右 1下 2左 3:上

	int m = matrix.size();
	if (m == 0) return vector<int>{};
	int n = matrix[0].size();
	if (n == 0) return vector<int>{};

	//四个方向遍历
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
	//从后遍历,若碰到可以跳至当前位置的前面节点,则更新后终点节点(当前节点)再次遍历,
	//直至遍历到头了!,查看当前节点在哪里

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
	//特殊情况
	if (intervals.size() == 0) return vector<vector<int>>{};

	//左边界排序
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
	//去掉末尾空格
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
	//正常生成

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

	//注意到n范围是1至9
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


