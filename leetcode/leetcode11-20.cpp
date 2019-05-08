#include "include.h"

#ifdef LEETCODE_11_20
#include "public.h"
#include "leetcode.h"

int Solution::maxArea(vector<int>& height)
{
	//init, 默认数字均>=0,至少有两个元素
	bool isLeftHigher;
	int left = 0;
	int right = height.size() - 1;
	int maxarea = 0;
	int pre_left_height = height[0];
	int pre_right_height = height[right];

	int temp;

	if (pre_left_height >= pre_right_height)
	{
		isLeftHigher = true;
		maxarea = right * height[right];
		right--;
	}
	else
	{
		isLeftHigher = false;
		maxarea = right * height[0];
		left++;
	}

	while (left < right)
	{
		if (isLeftHigher)
		{
			if (height[right] > pre_right_height)
			{
				pre_right_height = height[right];
				if (pre_right_height < pre_left_height)
				{
					temp = (right - left)*pre_right_height;
					if (maxarea < temp) maxarea = temp;
					right--;
				}
				else
				{
					temp = (right - left)*pre_left_height;
					if (maxarea < temp) maxarea = temp;
					isLeftHigher = false;
					left++;
				}
			}
			else right--;
		}
		else
		{
			if (height[left] > pre_left_height)
			{
				pre_left_height = height[left];
				if (pre_left_height < pre_right_height)
				{
					temp = (right - left)*pre_left_height;
					if (maxarea < temp) maxarea = temp;
					left++;
				}
				else
				{
					temp = (right - left)*pre_right_height;
					if (maxarea < temp) maxarea = temp;
					right--;
					isLeftHigher = true;
				}
			}
			else left++;
		}
	}
	return maxarea;
}


//num should >= 0, return (string)"c"*num like python do!
string Solution::stringMultiple(char c, int num)
{
	string returnstring = "";
	while (num > 0)
	{
		returnstring += c;
		num--;
	}
	return returnstring;
}

string Solution::intToRoman(int num)
{
	//按顺序一个一个数字扣下来, num = [1,3999]
	int son;
	string returns;
	son = num % 10;
	if (son == 9) returns = "IX";
	else if (son == 4) returns = "IV";
	else if (son > 4) returns = "V" + stringMultiple('I', son-5);
	else returns = stringMultiple('I', son);
	num /= 10;

	son = num % 10;
	if (num == 0) return returns;
	else if (son == 9) returns = "XC" + returns;
	else if (son == 4) returns = "XL" + returns;
	else if (son > 4) returns = "L" + stringMultiple('X', son - 5) + returns;
	else returns = stringMultiple('X', son) + returns;
	num /= 10;

	son = num % 10;
	if (num == 0) return returns;
	else if (son == 9) returns = "CM" + returns;
	else if (son == 4) returns = "CD" + returns;
	else if (son > 4) returns = "D" + stringMultiple('C', son - 5) + returns;
	else returns = stringMultiple('C', son) + returns;
	num /= 10;

son = num % 10;
if (num == 0) return returns;
else return stringMultiple('M', son) + returns;
}

int Solution::romanToInt(string s)
{
	//假设输入合法
	unordered_map<string, int> um = { {"I",1}, {"V", 5}, {"X", 10},{"L",50},{"C",100},{"D",500},
									{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CM",900},
									{"CD",400} };
	//漏过最后一个字符,这个while会一次扣俩字符的!
	unsigned int loc = 0;
	unordered_map<string, int>::iterator iter;
	int returnres = 0;
	while (loc < s.size() - 1)
	{
		if ((iter = um.find(s.substr(loc, 2))) != um.end())
		{
			returnres += iter->second;
			loc += 2;
		}
		else
		{
			returnres += um.find(s.substr(loc, 1))->second;
			loc++;
		}
	}
	if (loc == s.size() - 1)
	{
		returnres += um.find(s.substr(loc, 1))->second;
	}
	return returnres;
}

//查找区间:[startloc, endloc]是否为公共字符串
//return <true, end> 是公共字符串
//return <false, x> 从下标为x开始就不是了,若完全不公共,则x=start-1
pair<bool, int> Solution::FindCommonPrefix(vector<string>& strs, int start, int end)
{
	vector<string>::const_iterator iter = strs.cbegin();
	int temploc;
	string tempstr;
	int raw_end = end;
	for (iter++; iter < strs.cend(); iter++)
	{
		temploc = start;
		tempstr = (*iter);
		while (temploc <= end)
		{
			if (tempstr[temploc] != strs[0][temploc])
			{
				if (temploc != start)
				{
					end = temploc - 1;
					break;
				}
				else
				{
					return pair<bool, int>({ false, start - 1 });
				}
			}
			temploc++;
		}
	}
	if (end == raw_end) return pair<bool, int>({ true, end });
	else return pair<bool, int>({ false, end });
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	//特殊情况
	if (strs.size() == 1) return strs[0];
	else if (strs.size() == 0) return "";

	//找出最短的
	unsigned int minlen = UINT_MAX;
	for (vector<string>::const_iterator iter = strs.cbegin(); iter < strs.cend(); iter++)
	{
		minlen = ((*iter).size() < minlen) ? (*iter).size() : minlen;
	}

	if (minlen == 0) return "";

	//二分查找
	unsigned int left = 0;
	unsigned int right = minlen - 1;
	unsigned int mid;

	pair<bool, int> tempres;

	while (left <= right)
	{
		mid = (left + right) / 2;
		tempres = FindCommonPrefix(strs, left, mid);  //注意这里的left, mid是下标不是长度
		if( tempres.first == true)
		{
			left = tempres.second + 1;
		}
		else
		{
			return strs[0].substr(0, tempres.second + 1);
		}
	}
	return strs[0].substr(0, minlen);
}

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	vector<vector<int>> returnv = {};

	std::sort(nums.begin(), nums.end());

	int startloc = 0;
	int size = nums.size();
	int oldnum = 99;         //任意一个大于0的数就可以,这里仅仅是一个dump初始化
	for (int i = 0; i < size; i++)
	{
		if (nums[i] > 0) break;
		if (nums[i] == oldnum) continue;
		int target = -1 * nums[i];
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			if ((nums[left] + nums[right]) < target) left++;
			else if ((nums[left] + nums[right]) > target) right--;
			else
			{
				vector<int> temp = { nums[i], nums[left], nums[right] };
				returnv.push_back(temp);
				while ((left < right) && (nums[left] == nums[left + 1])) left++;
				while ((left < right) && (nums[right] == nums[right - 1])) right--;
				left++; right--;
			}
		}
		oldnum = nums[i];
	}
	return returnv;
}

int Solution::threeSumClosest(vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());

	//认为题目给的nums至少三个元素,否则题目不通
	//特殊情况
	int nsize = nums.size();
	if ((nums[0] + nums[1] + nums[2]) >= target) return (nums[0] + nums[1] + nums[2]);
	if ((nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]) <= target) return (nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]);

	//正式循环,双指针从两边往中间夹
	int oldnum = nums[0] + 1;   //我想让outer_loc所在外层循环第一次oldloc失效,因此使用nums[0] + 1作为初始的dump值来判断 nums[loc] = oldnum?
	int sign_diff_closest_sum = target - (nums[0] + nums[1] + nums[2]);  //dump init value
	for (int outer_loc = 0; outer_loc < nsize; outer_loc++)
	{
		int new_target = target - nums[outer_loc];
		int left = outer_loc + 1;
		int right = nsize - 1;
		int temp_diff_closest_sum = target - (nums[0] + nums[1] + nums[2]);  //dump init value
		while (left < right)
		{
			if ((nums[left] + nums[right] - new_target) < 0)
			{
				if ((new_target - nums[left] - nums[right]) < abs(temp_diff_closest_sum))
				{
					temp_diff_closest_sum = new_target - nums[left] - nums[right];
				}
				while ((left < right) && (nums[left] == nums[left + 1])) left++;  //merge left++ and dump move left one line
				left++;
			}
			else if ((nums[left] + nums[right] - new_target) > 0)
			{
				if ((nums[left] + nums[right] - new_target) < abs(temp_diff_closest_sum))
				{
					temp_diff_closest_sum = new_target - nums[left] - nums[right];
				}
				while ((left < right) && (nums[right] == nums[right - 1])) right--; //merge right-- and dump move right one line
				right--;
			}
			else
			{
				return target;
			}
			if (abs(sign_diff_closest_sum) > abs(temp_diff_closest_sum)) sign_diff_closest_sum = temp_diff_closest_sum;
		}
	}
	return (target - sign_diff_closest_sum);
}

vector<string> Solution::letterCombinations(string digits)
{
	unordered_map<char, vector<string>> um = { 
		{'2',{"a","b","c"}},{'3',{"d","e","f"}},{'4',{"g","h","i"}},{'5',{"j","k","l"}},{'6',{"m","n","o"}},{'7',{"p","q","r","s"}},{'8',{"t","u","v"}},{'9',{"w","x","y","z"}}
	};

	int ssize = digits.size();
	if (ssize == 1) return vector<string> { um[digits[0]] };     //single char
	vector<string> returns1 = {};     //俩vector,反复横跳
	vector<string> returns2 = {};
	bool is_s1_vaild = true;

	//我没有未初始化返回vector的大小!
	for (int i = 0; i < um[digits[0]].size(); i++)
	{
		returns1.push_back(um[digits[0]][i]);
	}

	for (int i = 1; i < ssize; i++)
	{
		if (is_s1_vaild)
		{
			returns2.clear();
			for (int j = 0; j < returns1.size(); j++)
			{
				for (int k = 0; k < um[digits[i]].size(); k++)
				{
					returns2.push_back(returns1[j] + um[digits[i]][k]);
				}
			}
			is_s1_vaild = false;
		}
		else
		{
			returns1.clear();
			for (int j = 0; j < returns2.size(); j++)
			{
				for (int k = 0; k < um[digits[i]].size(); k++)
				{
					returns1.push_back(returns2[j] + um[digits[i]][k]);
				}
			}
			is_s1_vaild = true;
		}
	}
	return (is_s1_vaild) ? returns1 : returns2;
}

vector<vector<int>> Solution::three_sum_target(vector<int>& nums, int target, int startloc, int endloc)
{
	vector<vector<int>> returnv = {};

	int oldnum = nums[startloc] + 1;         //任意一个大于0的数就可以,这里仅仅是一个dump初始化
	for (int i = startloc; i <= endloc-2; i++)  //i只需要迭代到endloc - 2就可了
	{
		if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;       //找不到了,nums[i] + nums[i + 1] + nums[i+2]是当前最小的可能和
		if (nums[i] == oldnum) continue;
		int iter_target = target - nums[i];
		int left = i + 1;
		int right = endloc;
		while (left < right)
		{
			if ((nums[left] + nums[right]) < iter_target) left++;
			else if ((nums[left] + nums[right]) > iter_target) right--;
			else
			{
				vector<int> temp = { nums[i], nums[left], nums[right] };
				returnv.push_back(temp);
				while ((left < right) && (nums[left] == nums[left + 1])) left++;
				while ((left < right) && (nums[right] == nums[right - 1])) right--;
				left++; right--;
			}
		}
		oldnum = nums[i];
	}
	return returnv;
}

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	//就是给三数之和外面套一个循环啵

	//先排序
	std::sort(nums.begin(), nums.end());
	int nlen = nums.size();

	//日,居然破题目还要判断少于4个元素的情况
	if (nlen < 4) return vector<vector<int>> {};

	//特殊情况
	if (nums[0] + nums[1] + nums[2] + nums[3] > target) return vector<vector<int>> {};
	if (nums[nlen - 1] + nums[nlen - 2] + nums[nlen - 3] + nums[nlen - 4] < target) return vector<vector<int>> {};

	int oldnum = nums[0] + 1;    //dump init value,只要让第一次外循环i=0时nums[i] != oldnum就可以了
	vector<vector<int>> returnv;

	for (int i = 0; i < nlen - 2; i++)    //得至少留三个数吧,i到nlen-3就可以了
	{
		if (nums[i] == oldnum) continue;
		vector<vector<int>> three_sum_res;
		//three_sum_target函数的参数:nums数组,双指针搜索起始下标,双指针搜索结束下标
		three_sum_res = three_sum_target(nums, target - nums[i], i + 1, nlen - 1);

		for (int j = 0; j < three_sum_res.size(); j++)
		{
			three_sum_res[j].insert(three_sum_res[j].begin(), nums[i]);
			returnv.push_back(three_sum_res[j]);
		}
		oldnum = nums[i];
	}
	return returnv;
}

ListNode * Solution::removeNthFromEnd(ListNode * head, int n)
{
	//双指针
	ListNode* dump = new ListNode(0);
	dump->next = head;

	ListNode* first = dump;
	ListNode* second = dump;

	//先把second移动n次
	for (int i = 0; i < n; ++i)
	{
		second = second->next;
	}

	//判断终止条件
	while ((second->next) != NULL)
	{
		first = first->next;
		second = second->next;
	}

	//终止时first->next即为要删除的节点
	first->next = first->next->next;

	return dump->next;
}

bool Solution::isValid(string s)
{
	//认为题目输入的s仅可能是六种半括号字符
	unordered_map<char, char> cmp = { {')', '('}, {']', '['}, {'}', '{'} };

	//需要一个栈结构
	int slen = s.size();
	vector<char> stack = {};

	for (int i = 0; i < slen; ++i)
	{
		switch (s[i])
		{
		case '(':
		case '[':
		case '{':
		{
			stack.push_back(s[i]);
			break;
		}
		case ')':
		case ']':
		case '}':
		{
			if (stack.empty()) return false;
			if (stack[stack.size()-1] != cmp[s[i]]) return false;
			else stack.pop_back();
			break;
		}
		default:
			break;
		}
	}
	return (stack.empty()) ? true : false;
}
#else
#endif
