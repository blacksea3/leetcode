#include "include.h"

#ifdef LEETCODE_11_20
#include "public.h"
#include "leetcode.h"

int Solution::maxArea(vector<int>& height)
{
	//init, Ĭ�����־�>=0,����������Ԫ��
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
	//��˳��һ��һ�����ֿ�����, num = [1,3999]
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
	//��������Ϸ�
	unordered_map<string, int> um = { {"I",1}, {"V", 5}, {"X", 10},{"L",50},{"C",100},{"D",500},
									{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CM",900},
									{"CD",400} };
	//©�����һ���ַ�,���while��һ�ο����ַ���!
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

//��������:[startloc, endloc]�Ƿ�Ϊ�����ַ���
//return <true, end> �ǹ����ַ���
//return <false, x> ���±�Ϊx��ʼ�Ͳ�����,����ȫ������,��x=start-1
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
	//�������
	if (strs.size() == 1) return strs[0];
	else if (strs.size() == 0) return "";

	//�ҳ���̵�
	unsigned int minlen = UINT_MAX;
	for (vector<string>::const_iterator iter = strs.cbegin(); iter < strs.cend(); iter++)
	{
		minlen = ((*iter).size() < minlen) ? (*iter).size() : minlen;
	}

	if (minlen == 0) return "";

	//���ֲ���
	unsigned int left = 0;
	unsigned int right = minlen - 1;
	unsigned int mid;

	pair<bool, int> tempres;

	while (left <= right)
	{
		mid = (left + right) / 2;
		tempres = FindCommonPrefix(strs, left, mid);  //ע�������left, mid���±겻�ǳ���
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
	int oldnum = 99;         //����һ������0�����Ϳ���,���������һ��dump��ʼ��
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

	//��Ϊ��Ŀ����nums��������Ԫ��,������Ŀ��ͨ
	//�������
	int nsize = nums.size();
	if ((nums[0] + nums[1] + nums[2]) >= target) return (nums[0] + nums[1] + nums[2]);
	if ((nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]) <= target) return (nums[nsize - 1] + nums[nsize - 2] + nums[nsize - 3]);

	//��ʽѭ��,˫ָ����������м��
	int oldnum = nums[0] + 1;   //������outer_loc�������ѭ����һ��oldlocʧЧ,���ʹ��nums[0] + 1��Ϊ��ʼ��dumpֵ���ж� nums[loc] = oldnum?
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
	vector<string> returns1 = {};     //��vector,��������
	vector<string> returns2 = {};
	bool is_s1_vaild = true;

	//��û��δ��ʼ������vector�Ĵ�С!
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

	int oldnum = nums[startloc] + 1;         //����һ������0�����Ϳ���,���������һ��dump��ʼ��
	for (int i = startloc; i <= endloc-2; i++)  //iֻ��Ҫ������endloc - 2�Ϳ���
	{
		if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;       //�Ҳ�����,nums[i] + nums[i + 1] + nums[i+2]�ǵ�ǰ��С�Ŀ��ܺ�
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
	//���Ǹ�����֮��������һ��ѭ���

	//������
	std::sort(nums.begin(), nums.end());
	int nlen = nums.size();

	//��,��Ȼ����Ŀ��Ҫ�ж�����4��Ԫ�ص����
	if (nlen < 4) return vector<vector<int>> {};

	//�������
	if (nums[0] + nums[1] + nums[2] + nums[3] > target) return vector<vector<int>> {};
	if (nums[nlen - 1] + nums[nlen - 2] + nums[nlen - 3] + nums[nlen - 4] < target) return vector<vector<int>> {};

	int oldnum = nums[0] + 1;    //dump init value,ֻҪ�õ�һ����ѭ��i=0ʱnums[i] != oldnum�Ϳ�����
	vector<vector<int>> returnv;

	for (int i = 0; i < nlen - 2; i++)    //����������������,i��nlen-3�Ϳ�����
	{
		if (nums[i] == oldnum) continue;
		vector<vector<int>> three_sum_res;
		//three_sum_target�����Ĳ���:nums����,˫ָ��������ʼ�±�,˫ָ�����������±�
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
	//˫ָ��
	ListNode* dump = new ListNode(0);
	dump->next = head;

	ListNode* first = dump;
	ListNode* second = dump;

	//�Ȱ�second�ƶ�n��
	for (int i = 0; i < n; ++i)
	{
		second = second->next;
	}

	//�ж���ֹ����
	while ((second->next) != NULL)
	{
		first = first->next;
		second = second->next;
	}

	//��ֹʱfirst->next��ΪҪɾ���Ľڵ�
	first->next = first->next->next;

	return dump->next;
}

bool Solution::isValid(string s)
{
	//��Ϊ��Ŀ�����s�����������ְ������ַ�
	unordered_map<char, char> cmp = { {')', '('}, {']', '['}, {'}', '{'} };

	//��Ҫһ��ջ�ṹ
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
