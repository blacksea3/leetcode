#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_81_90

//nums[startloc, endloc]可能是有序数组,也可能不是的,里面都有处理,但最多由两个有序数组组成
//且符合题目规定
int Solution::iter_search_81(vector<int>& nums, int target, int startloc, int endloc)
{
	//二分拆分
	int nsize = endloc - startloc;
	if (nsize < 0) return -1;
	if (nsize == 0)
	{
		if (nums[startloc] == target) return startloc;
		else return -1;
	}
	else
	{
		int mid = (startloc + endloc) / 2;   //here mid must < endloc
		//显式分割成了[startloc,mid],  [mid+1,endloc]

		//有一种特殊情况下,尽管nums[startloc] <= nums[mid],他也不是升序数列
		//例如1 3 1 1 1
		//这个时候应当首先判断首位是否相同,然后往中间搜,直接遍历搜索吧

		bool is_lefthalf_sorted = true;

		if (nums[startloc] != nums[endloc])
		{
			is_lefthalf_sorted = (nums[startloc] <= nums[mid]);
			//若[0,mid]不是升序排序数列,则[mid+1,endloc]必为升序排序数列
		}
		else
		{
			//搞清楚到底[startloc,mid]是不是升序数列
			if (nums[startloc] < nums[mid]) is_lefthalf_sorted = true;
			else
			{
				//如果左半边只有一个元素,那么is_lefthalf_sorted会采用默认值true
				for (int i = (startloc + 1); i <= mid; i++)
					if (nums[i] != nums[startloc]) is_lefthalf_sorted = false;
			}
		}
		if (is_lefthalf_sorted)
		{
			if (nums[startloc] <= target)
				if (target <= nums[mid])
					return binary_search_81(nums, target, startloc, mid);
				else //可能在后半段
				{
					//后半段不一定是升序排序数列
					bool is_righthalf_sorted = true;  //思路和左半段的一致
					if (nums[mid + 1] < nums[endloc]) is_righthalf_sorted = true;
					else
					{
						//如果右半边只有一个元素,那么is_righthalf_sorted会采用默认值true
						for (int i = (mid + 2); i <= endloc; i++)
							if (nums[i] != nums[mid + 1]) is_righthalf_sorted = false;
					}

					if (is_righthalf_sorted)     //[mid+1,endloc]为升序排序数列
						return binary_search_81(nums, target, mid + 1, endloc);
					else
						return iter_search_81(nums, target, mid + 1, endloc);
				}
			else
				return iter_search_81(nums, target, mid + 1, endloc);
		}
		else
		{
			if (nums[mid + 1] <= target)
				if (target <= nums[endloc])
					return binary_search_81(nums, target, mid + 1, endloc);
				else
					return iter_search_81(nums, target, startloc, mid);
			else
				return iter_search_81(nums, target, startloc, mid);
		}

	}
}

int Solution::binary_search_81(vector<int>& nums, int target, int startloc, int endloc)
{
	int left = startloc;
	int right = endloc;
	if (right < left) return -1;
	if (right == left)
	{
		if (nums[left] == target) return left;
		else return -1;
	}
	else
	{
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else if (nums[mid] > target) right = mid - 1;
			else return mid;
		}
	}
	return -1;
}

bool Solution::search_81(vector<int>& nums, int target)
{
	int nsize = nums.size();
	if (nsize == 0) return false;
	if (nsize == 1)
	{
		if (nums[0] == target) return true;
		else return false;
    }

	//以下为nsize >= 2情形,递归
	if (iter_search_81(nums, target, 0, nsize - 1) == -1)
		return false;
	else return true;
}

ListNode * Solution::deleteDuplicates(ListNode * head)
{
	if (head == nullptr) return nullptr;

	//一轮遍历
	//双指针
	ListNode* dump = new ListNode(0);
	dump->next = head;
	ListNode* loc = dump;
	ListNode *left, *right;

	//1->1->2->2->3

	while (loc->next)
	{
		left = loc->next;
		right = left;
		while (right->next && right->next->val == left->val)
			right = right->next;
		if (left == right) loc = loc->next;
		else loc->next = right->next;
	}
	return dump->next;
}

ListNode * Solution::deleteDuplicates_83(ListNode * head)
{
	ListNode *dump = new ListNode(0);
	dump->next = head;

	ListNode *left, *right;
	ListNode *loc = head;

	while (loc)
	{
		left = loc;
		right = loc->next;
		while (right && (right->val == left->val)) right = right->next;
		if (left->next == right) loc = loc->next;
		else loc->next = right;
	}
	return dump->next;
}

int Solution::largestRectangleArea(vector<int>& heights)
{
	//单调栈
	//来自https://blog.csdn.net/lv1224/article/details/79974175

	//算法太高端了:)

	vector<int> stack = {};
	int hsize = heights.size();
	int maxArea = 0;
	if (hsize == 0) return 0;

	for (int i = 0; i < hsize; i++)
	{
		if (stack.empty() || heights[stack[stack.size() - 1]] <= heights[i]) stack.push_back(i);
		else
		{
			while (!stack.empty() && heights[stack[stack.size() - 1]] > heights[i])
			{
				int top = stack[stack.size() - 1];
				stack.pop_back();
				if (stack.empty()) maxArea = max(heights[top] * i, maxArea);
				else maxArea = max(heights[top] * (i - stack[stack.size() - 1] - 1), maxArea);
			}
			stack.push_back(i);
		}
	}

	while (!stack.empty())
	{
		int top = stack[stack.size() - 1];
		stack.pop_back();
		if (stack.empty()) maxArea = max(heights[top] * (hsize), maxArea);
		else maxArea = max(heights[top]* (hsize - stack[stack.size() - 1] - 1), maxArea);
	}
	return maxArea;
}

int Solution::maximalRectangle(vector<vector<char>>& matrix)
{
	//按行看,往上衍生出的连续1的数量就是高度,那么就变成寻找每行的最大矩阵面积(上一题),
	//然后从m行(m个)数据中找出最大的

	//m行n列
	int m = matrix.size();
	if (m == 0) return 0;
	int n = matrix[0].size();
	if (n == 0) return 0;

	vector<vector<int>> heights(m, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
		heights[0][j] = (matrix[0][j] == '1') ? 1 : 0;

	for (int i = 1; i < m; i++)
		for (int j = 0; j < n; j++)
			heights[i][j] = (matrix[i][j] == '1') ? heights[i - 1][j] + 1 : 0;

	int maxsize = 0;

	for (int i = 0; i < m; i++)
		maxsize = max(maxsize, largestRectangleArea(heights[i]));

	return maxsize;
}

ListNode * Solution::partition(ListNode * head, int x)
{
	//最简单的办法,合成两个新建的链表

	ListNode *leftdump = new ListNode(0);
	ListNode *rightdump = new ListNode(0);
	ListNode *left = leftdump;
	ListNode *right = rightdump;

	while (head != nullptr)
	{
		if (head->val < x)
		{
			left->next = new ListNode(head->val);
			left = left->next;
		}
		else
		{
			right->next = new ListNode(head->val);
			right = right->next;
		}
		head = head->next;
	}

	if (leftdump->next)
	{
		left->next = rightdump->next;
		return leftdump->next;
	}
	else return rightdump->next;
}

bool Solution::isScramble(string s1, string s2)
{
	//判断s2是否能够通过s1的特定次数的子字符串交换得到,这两个用于交换的子字符串必须连续,
	//每交换一次,s1被更新        

	//递归太暴力了,依次缩短字符串,停止条件是两个字符串完全相同
	//递归时按照切开字符串的下标递归,人工实现各种位置的交换!

	//动态规划 https://blog.csdn.net/linhuanmars/article/details/24506703

	//动态规划dp[i][j][len_m1]表示s1.substr(i,len_m1+1)与s2.substr(j,len_m1+1)是否
	//为扰乱字符串,len_m1表示长度减一(这是由于下标从0开始)...
	//i是0~s1.size()-1;  j是0~s2.size()-1

	//len_m1=0时可以简单求得
	//len_m1>0时,emmmmm分为正序和乱序
	//正序:s1从i开始的某个长度与s2从j开始的某个长度相同,并且之后的那段长度也对应相同
	//乱序:s1从i开始的某个长度与s2的倒数某个长度相同,并且s2从j开始的另一段长度与s1的倒数另一段长度相同

	//注意不是所有dp元素都合法,随着len_m1的增大,i与j的上限降低
	int lens = s1.size();
	if (lens == 0) return true;  //空字符串>.<
	//注意外部确保输入长度相同
	vector<vector<vector<bool>>> dp(lens, vector<vector<bool>>(lens, vector<bool>(lens, false)));

	for (int i = 0; i < lens; i++)
		for (int j = 0; j < lens; j++)
			dp[i][j][0] = (s1[i] == s2[j]);

	//核心dp
	for (int lenm1 = 1; lenm1 < lens; lenm1++)   //实际长度减1
	{
		for (int i = 0; i < lens - lenm1; i++)
			for (int j = 0; j < lens - lenm1; j++)
			{
				//有些情况下直接跳跃,不需要遍历求解|=位或
				//正序
				for (int klenm1 = 0; klenm1 < lenm1; klenm1++)  //左部分实际长度减1
					if (dp[i][j][klenm1] && dp[i + klenm1 + 1][j + klenm1 + 1][lenm1 - klenm1 - 1])
					{
						dp[i][j][lenm1] = true;
						goto end;
					}
				//乱序
				for (int klenm1 = 0; klenm1 < lenm1; klenm1++)  //左部分实际长度减1
					if (dp[i][j + lenm1 - klenm1][klenm1] && dp[i + klenm1 + 1][j][lenm1 - klenm1 - 1])
					{
						dp[i][j][lenm1] = true;
						goto end;
					}
			end:;
			}
	}

	return dp[0][0][lens - 1];
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	//二者都是一轮遍历

	int pre_loc = m + n - 1;
	int m_loc = m - 1;
	int n_loc = n - 1;

	while ((m_loc > -1) && (n_loc > -1))
	{
		if (nums1[m_loc] >= nums2[n_loc]) nums1[pre_loc--] = nums1[m_loc--];
		else nums1[pre_loc--] = nums2[n_loc--];
	}

	if (m_loc == -1)
		while (n_loc > -1) nums1[pre_loc--] = nums2[n_loc--];

}

vector<int> Solution::grayCode(int n)
{
	//迭代获得格雷编码

	//获得n之前要获得n-1的
	//n=1直接给出,n=0为特殊情况

	//两个数组来回操作

	if (n == 0) return vector<int> {0};
	if (n == 1) return vector<int> {0, 1};

	vector<int> left = { 0,1 };
	vector<int> right;
	bool is_left_useful = true;

	for (int i = 2; i <= n; i++)
	{
		if (is_left_useful)
		{
			right.clear();
			right.resize(left.size() * 2);
			for (int j = 0; j < left.size(); j++)
				right[j] = left[j];
			int abs = 1 << (i - 1);
			for (int j = left.size(); j < 2 * left.size(); j++)
				right[j] = left[2 * left.size() - j - 1] + abs;
			is_left_useful = false;
		}
		else
		{
			left.clear();
			left.resize(right.size() * 2);
			for (int j = 0; j < right.size(); j++)
				left[j] = right[j];
			int abs = 1 << (i - 1);
			for (int j = right.size(); j < 2 * right.size(); j++)
				left[j] = right[2 * right.size() - j - 1] + abs;
			is_left_useful = true;
		}
	}
	return (is_left_useful) ? left : right;
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
	//回溯
	//初始化:numdict:nums字典计数
	//length:nums长度
	//uniquenums:去重nums

	//维护:stack:未来可以用到的数字
	//prelength:当前长度
	//predict:当前数字字典
	//prenums:当前数字vector
	//res:返回值

	//初始化过程
	int length = nums.size();
	if (length == 0) return vector<vector<int>>{ {}};
	if (length == 1) return vector<vector<int>>{ {}, nums};

	unordered_map<int, int> numdict;
	for (auto num : nums) numdict[num]++;

	unordered_map<int, int>::iterator it;
	vector<int> uniquenums;
	for (it = numdict.begin(); it != numdict.end(); it++) {
		if (find(uniquenums.begin(), uniquenums.end(), it->first) == uniquenums.end())
			uniquenums.push_back(it->first);
	}
	sort(uniquenums.begin(), uniquenums.end());

	vector<vector<int>> stack = { uniquenums };
	int prelength = 0;
	unordered_map<int, int> predict;
	vector<int> prenums;
	vector<vector<int>> res = { {} };

	//回溯过程
	while ((stack.size() > 1) || (stack[0].size() >= 1))
	{
		if (stack[stack.size() - 1].size() > 0)
		{
			int pre_num = stack[stack.size() - 1][0];
			stack[stack.size() - 1].erase(stack[stack.size() - 1].begin());
			prenums.push_back(pre_num);
			predict[pre_num]++;
			prelength++;
			res.push_back(prenums);

			if (prelength == length) continue; //别查找了,数字满了

			//查找随后可能的数字
			vector<int> temp = {};
			for (auto tempnum : uniquenums)
				if (tempnum < pre_num)
					temp.push_back(tempnum);
			//对于重复数字,特别处理
			if (predict[pre_num] < numdict[pre_num]) temp.push_back(pre_num);
			stack.push_back(temp);
		}
		else
		{
			int last_num = prenums[prenums.size() - 1];
			predict[last_num]--;
			prenums.pop_back();
			prelength--;
			stack.pop_back();
		}
	}
	return res;
}



#else
#endif
