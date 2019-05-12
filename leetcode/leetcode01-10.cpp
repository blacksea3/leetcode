#include "include.h"

#ifdef LEETCODE_01_10
#include "public.h"
#include "leetcode.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {
	//假设一定有解
	unordered_map<int, int> mdict;
	int loc = 0;
	for (vector<int>::const_iterator iter = nums.cbegin(); iter != nums.cend(); iter++)
	{
		if (mdict.find(target - (*iter)) == mdict.end())
		{
			mdict.insert(pair<int, int>{*iter, loc});
		}
		else
		{
			return vector<int> {mdict.find(target - (*iter))->second, loc};
		}
		loc++;
	}
	return vector<int> {-1, -1};
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	bool carry = false;
	ListNode* return_ln = new ListNode(NULL);
	ListNode* old_ln = return_ln;

	while ((l1 != NULL) || (l2 != NULL) || carry)
	{
		int new_res = 0;

		if (l1 != NULL)
		{
			new_res += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			new_res += l2->val;
			l2 = l2->next;
		}
		if (carry)
		{
			new_res += 1;
		}

		if (new_res >= 10)
		{
			new_res -= 10;
			carry = true;
		}
		else
		{
			carry = false;
		}

		ListNode* new_ln = new ListNode(new_res);
		old_ln->next = new_ln;
		old_ln = new_ln;
	}
	return return_ln->next;
}

int Solution::lengthOfLongestSubstring(string s)
{
	unsigned int iSize = s.size();
	unordered_map<char, unsigned int> um;
	unsigned int start_index = 0;   //开始下标
	unsigned int max_length = 0;
	for (unsigned int i = 0; i < iSize; i++)
	{
		if (um.find(s[i]) == um.end())
		{
			um.insert(pair<char, unsigned int>{s[i], i});
		}
		else
		{
			if (um.find(s[i])->second >= start_index)
			{
				max_length = ((i - start_index) > max_length) ? (i - start_index) : max_length;
				start_index = um.find(s[i])->second + 1;
				um[s[i]] = i;
			}
			else
			{
				um[s[i]] = i;
			}
		}
	}
	max_length = ((iSize - start_index) > max_length) ? (iSize - start_index) : max_length;

	return (int)max_length;
}

/*m, n = len(nums1), len(nums2)
#首先确保m<n否则交换nums1和nums2
#然后一般流程是用i与j把两个数列分开  i = (lower_border+upper_border+1)/2, 然后二分缩小范围

#奇偶上有四种情况，情况可以被合并，详情参考代码
#  a0 a1....ai-1, ai...am-1
#  b0 b1....bj-1, bj...bn-1
# 确保 i+j+1 = m-i+n-j  ij是整数
# => j=(m+n)/2-i
# 确保 ai-1 < bj+1; bj < ai; 这样可以得到中位数
*/
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m, n;
	m = nums1.size();
	n = nums2.size();
	vector<int> A;
	vector<int> B;
	if (m > n)
	{
		int temp = m;
		m = n;
		n = temp;
		A.assign(nums2.begin(), nums2.end());
		B.assign(nums1.begin(), nums1.end());
	}
	else
	{
		B.assign(nums2.begin(), nums2.end());
		A.assign(nums1.begin(), nums1.end());
	}


	int imin = 0;
	int imax = m;
	while (imin <= imax)
	{
		int max_left;
		int min_right;
		int i = (imin + imax) / 2;
		int j = (m + n + 1) / 2 - i;
		if ((i > 0) && (j < n) && (A[i - 1] > B[j]))
			imax = i - 1;
		else if ((j > 0) && (i < m) && (B[j - 1] > A[i]))
			imin = i + 1;
		else
		{
			if (i == 0) max_left = B[j - 1];
			else if (j == 0) max_left = A[i - 1];
			else max_left = (A[i - 1] >= B[j - 1]) ? A[i - 1] : B[j - 1];

			if (((m + n) % 2) == 1) return float(max_left);

			if (i == m) min_right = B[j];
			else if (j == n) min_right = A[i];
			else min_right = (A[i] <= B[j]) ? A[i] : B[j];
			return (max_left + min_right) / 2.0;
		}
	}
	return -999;
}


string Solution::longestPalindrome(string s)
{
	//Manacher algorithm
	//特别注意边界问题
	//https://mp.weixin.qq.com/s?__biz=MzIzMTE1ODkyNQ==&mid=2649410225&idx=1&sn=ed045e8edc3c49a436a328e5f0f37a55&chksm=f0b60f53c7c18645b4c04a69ad314723cce94ed56994d6f963c2275a2db8d85f973f15f508e4&mpshare=1&scene=23&srcid=1001JCsBlpxgUWjgixasChNQ#rd

	string newstr = string("#");
	unsigned int iSize = s.size();
	for (unsigned int i = 0; i < iSize; i++)
	{
		newstr += s[i];
		newstr += "#";
	}

	int new_len = newstr.size();
	vector<int> radius = {};
	int right_border = -1;
	int center_index = -1;
	int longest_radius = -1;
	int longest_center_index = -1;
	for (int index = 0; index < new_len; index++)
	{
		if (index > right_border)
		{
			//expand the right border
			int L = index;
			int R = index;
			while ((L >= 0) && (R < new_len) && (newstr[L] == newstr[R]))
			{
				L--;
				R++;
			}
			int newradius = (R - L + 1) / 2;    //此处将向下取整
			radius.insert(radius.end(), newradius);
			right_border = R - 1;
			center_index = index;
			if (newradius > longest_radius)
			{
				longest_radius = newradius;
				longest_center_index = index;
			}
		}
		else if ((index + radius[2 * center_index - index] - 1) >= right_border)
		{
			//also expand the right border
			int L = 2 * index - right_border;
			int R = right_border;
			while ((L >= 0) && (R < new_len) && (newstr[L] == newstr[R]))
			{
				L--;
				R++;
			}
			int newradius = (R - L + 1) / 2;    //此处将向下取整
			radius.insert(radius.end(), newradius);
			right_border = R - 1;
			center_index = index;
			if (newradius > longest_radius)
			{
				longest_radius = newradius;
				longest_center_index = index;
			}
		}
		else radius.insert(radius.end(), radius[2 * center_index - index]);
	}

	float real_index = (longest_center_index + 1) / 2.0 - 1;  //may be xxx.5  4->1.5 2->0.5, 3->1, 1->0
	float real_radius = (longest_radius) / 2.0 - 1;         //5 ->1.5,  3->0.5  4->1, 2->0

	//s.substr(开始下标,子串长度)!!!!!
	return s.substr(int(real_index - real_radius), int(2*real_radius + 1));
}

string Solution::convert(string s, int numRows)
{
	if (numRows == 1)
	{
		return s;
	}

	vector<string> group_s(numRows);
	int ssize = s.size();
	bool downdir = true;
	int line = 0;
	for (int i = 0; i < ssize; i++)
	{
		group_s[line] += s[i];
		if (downdir)
		{
			if (line == (numRows - 1))
			{
				downdir = false;
				line--;
			}
			else line++;
		}
		else
		{
			if (line == 0)
			{
				downdir = true;
				line++;
			}
			else line--;
		}
	}

	string returns;
	for (int i = 0; i < numRows; i++)
	{
		returns += group_s[i];
	}
	return returns;
}

int Solution::reverse(int x)
{
	bool positive;
	if (x > 0)
	{
		positive = true;
	}
	else
	{
		positive = false;
		x *= -1;                 //仅x==INT_MIN会溢出,但是通过一顿分析,不会影响结果
	}  

	int res = 0;
	int loc = 0;
	while (x > 0)
	{
		int son = x % 10;
		x /= 10;
		if (loc < 9)
		{
			res = res * 10 + son;
			loc++;
		}
		else
		{
			if (res > 214748364) return 0;
			else if (res < 214748364) return (positive) ? (res * 10 + son) : -1 * res * 10 - son;
			else
				if (positive) return (son > 7) ? 0 : (res * 10 + son);
				else return (son > 8) ? 0 : -1 * res * 10 - son;
		}
	}
	return (positive) ? res : -1 * res;
}

int Solution::myAtoi(string str)
{
	bool state = false;         //false:idle(need find sign or number), true:run(need find number)
	bool ispositive = true;

	int returnnum = 0;
	int num_times = 0;    //means returnnum的位数

	for (int loc = 0; loc < str.size(); loc++)
	{
		if (!state)
		{
			if ((str[loc] <= '9') && (str[loc] >= '0'))
			{
				state = true;
				returnnum = returnnum * 10 + (str[loc] - '0');  //char->int
				num_times++;
				if (returnnum == 0) num_times--;
			}
			else if (str[loc] == '-')
			{
				ispositive = false;
				state = true;
			}
			else if (str[loc] == '+')
			{
				state = true;
			}
			else if (str[loc] == ' ');
			else return 0;
		}
		else
		{
			if ((str[loc] <= '9') && (str[loc] >= '0'))
			{
				if (num_times == 9)
				{
					if (returnnum > 214748364) return (ispositive) ? INT_MAX : INT_MIN;
					else if (returnnum == 214748364)
					{
						if ((ispositive) && (str[loc] >= '7'))
							return INT_MAX;
						if ((!ispositive) && (str[loc] >= '8'))
							return INT_MIN;
					}
				}
				else if (num_times == 10) return (ispositive) ? INT_MAX : INT_MIN;
				returnnum = returnnum * 10 + (str[loc] - '0');  //char->int
				num_times++;
				if (returnnum == 0) num_times--;
			}
			else break;
		}

	}
	return (ispositive) ? returnnum : -1 * returnnum;
}

bool Solution::isPalindrome(int x)
{
	//边界情况
	if (x < 0) return false;
	if (x < 10) return true;
	if (x % 10 == 0) return false;

	int reverse = 0;
	int temp = 0;

	while (true)
	{
		temp = reverse * 10 + x % 10;
		if (reverse > (x / 10)) return false;
		else if (reverse == (x / 10)) return true;
		else
		{
			if (temp > (x / 10)) return false;
			else if (temp == (x / 10)) return true;
			else
			{
				reverse = temp;
				x /= 10;
			}
		}
	}
	return false;   //dump, code will not arrive here
}

//块匹配
bool Solution::isMatchBlock(string s, string p)
{
	unsigned int sleft = 0;
	unsigned int sright = s.size();
	unsigned int pleft = 0;
	unsigned int pright = p.size();
	while ((sleft < sright) && (pleft < pright))
	{
		if (pleft < (pright - 1))
			if (p[pleft + 1] == '*') break;
		if (!((s[sleft] == p[pleft]) || (p[pleft] == '.'))) return false;
		sleft++; pleft++;
	}
	while ((sleft < sright) && (pleft < pright))
	{
		if (p[pright - 1] == '*') break;
		if (!((s[sright - 1] == p[pright - 1]) || (p[pright - 1] == '.'))) return false;
		sright--; pright--;
	}

	if ((sleft == sright) && (isMatchSpace(p.substr(pleft, pright - pleft)))) return true;
	else if ((sleft == sright) || (pleft == pright)) return false;
	else return isMatchStar(s.substr(sleft, sright - sleft), shorter(p.substr(pleft, pright - pleft)));
	return false;
}

string Solution::shorter(string p)
{
	unsigned int loc = 0;
	bool sign = false;
	while (loc < p.size())
	{
		if ((p[loc] == '.') && (p[loc + 1]) == '*')
			sign = true;
		else if (p[loc + 1] != '*')
			break;
		loc += 2;
	}
	if (sign)
	{
		p = ".*" + p.substr(loc);
		sign = false;
	}
	loc = p.size() - 1;
	while (loc > 0)
	{
		if ((p[loc] == '.') && (p[loc - 1]) == '*')
			sign = true;
		else if (p[loc - 1] != '*')
			break;
		loc -= 2;
	}
	if (sign)
	{
		p = p.substr(0, loc + 1) + ".*";
		sign = false;
	}

	return p;
}

bool Solution::isMatchStar(string s, string p)
{
	unsigned x = 0;
	while (!(isMatchBlock(s.substr(x), p.substr(2))))
	{
		if ((x >= s.size()) || ((p[0] != '.') && p[0] != s[x])) return false;
		else x++;
	}
	return true;
}

bool Solution::isMatchSpace(string p)
{
	unsigned int plen = p.size();
	if ((plen % 2) == 1) return false;
	unsigned int loc = 0;
	while (loc < plen)
	{
		if (p[loc] == '*') return false;
		if (p[loc + 1] != '*') return false;
		else loc += 2;
	}
	return true;
}

bool Solution::isMatch(string s, string p)
{
	return new_isMatch(s, p);
}

bool Solution::new_isMatch(string s, string p)
{
	//对于特殊的?*组合,记录至stack中

	struct star { int sloc; int ploc; int number; };  //sloc:s的起始loc, ploc:?*组合的?处的p的loc, number:匹配掉多少个s中的?字符
	stack<star> recall = {};

	int sloc = 0;
	int ploc = 0;
	int ssize = s.size();
	int psize = p.size();

	bool isneedjudge = false;  //回溯用的判断

	while (true)
	{
		if (isneedjudge)
		{
			if (recall.empty()) return false;
			star last = recall.top();
			if (p[last.ploc] == '.')
			{
				//边界判断 //再次回溯
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
			}
			else
			{
				//边界判断 //再次回溯
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else if (s[last.sloc + last.number] == p[last.ploc])
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
				else //再次回溯
				{
					recall.pop();
					isneedjudge = true;
				}
			}
		}
		else
		{
			if (sloc == ssize)
			{
				if (ploc == psize)
					break;
				else
				{
					//判断p之后的内容
					if (isMatchSpace(p.substr(ploc))) break;
					else //回溯
						isneedjudge = true;
				}
			}
			else if (ploc == psize)
			{
				isneedjudge = true;
				//回溯
			}
			else
			{
				if ((p[ploc] <= 'z') && (p[ploc] >= 'a'))
				{
					//如果p这里正好有个?*组合,那么直接加入stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//生成栈
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else if (s[sloc] == p[ploc])
					{
						sloc++;
						ploc++;
					}
					else //回溯
					{
						isneedjudge = true;
					}
				}
				else if (p[ploc] == '.')
				{
					//如果p这里正好有个?*组合,那么直接加入stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//生成栈
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else
					{
						sloc++;
						ploc++;
					}
				}
				else  //有星号了
				{
					//判断星号合法性
					if (ploc == 0) return false;
					if (p[ploc - 1] == '*') return false;

					//生成栈
					star pre = star();
					pre.sloc = sloc - 1;
					pre.ploc = ploc - 1;
					pre.number = 0;
					recall.push(pre);
					sloc--;
					ploc++;
				}
			}
		}

	}

	return true;
}

#else

#endif