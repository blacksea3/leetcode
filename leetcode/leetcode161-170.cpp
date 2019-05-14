#include "include.h"

#ifdef LEETCODE_161_170
#include "public.h"
#include "leetcode.h"

int Solution::findPeakElement(vector<int>& nums)
{
	//二分搜索
	//注意到:   nums[mid] < nums[mid+1]   1 4 3 2 1  不管如何, 总会在mid+1至end出现峰值元素
	//这是因为mid+1至end比左右两端都大
	//否则start至mid一定有元素

	//注意相邻的元素不同

	int left = 0;
	int right = nums.size() - 1;
	int mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < nums[mid + 1])
			left = mid + 1;
		else
			right = mid;
	}

	return left;

}

int Solution::maximumGap(vector<int>& nums)
{
	//基数排序
	//都是非负整数!
	if (nums.size() <= 1) return 0;
	else
	{
		int nmax = 0;
		//先搞清楚最大的
		for (auto num : nums)
			nmax = max(num, nmax);

		//搞清楚这个最大的有多少位,理论上order10_value最大是10
		int order10_value = 0;
		while (nmax > 0)
		{
			nmax /= 10;
			order10_value++;
		}

		//特殊情况,全0?????
		if (order10_value == 0)
			return 0;
		else
		{
			//正式基数排序
			vector<queue<int>> base(10, queue<int>{});
			vector<int> constants = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

			for (int i = 1; i <= order10_value; i++)  //i是位数
			{
				for (auto num : nums)
				{
					if (i < 10)
						base[num%constants[i] / constants[i - 1]].push(num);
					else
						base[num / constants[i - 1]].push(num);
				}
				//合并至nums
				vector<int> newnums = {};
				for (int i = 0; i < 10; i++)
				{
					while (!base[i].empty())
					{
						newnums.push_back(base[i].front());
						base[i].pop();
					}
				}
				nums.clear();
				nums.assign(newnums.begin(), newnums.end());
			}

			//排序结束,查找最大差值
			int maxdiff = 0;
			for (int i = 1; i < nums.size(); i++)
				maxdiff = max(nums[i] - nums[i - 1], maxdiff);

			return maxdiff;
		}
	}
}

int Solution::compareVersion(string version1, string version2)
{
	//按顺序遍历,每次遍历一个有效数字
	//按题目意思,不会输入空字符串

	int sloc1 = 0;
	int sloc2 = 0;
	int maxsloc1 = version1.size();
	int maxsloc2 = version2.size();
	bool isn1_equal0 = false;
	bool isn2_equal0 = false;
	int oldsloc1 = 0;
	int oldsloc2 = 0;
	int n1, n2;

	while (true)
	{
		if (!isn1_equal0)
		{
			int oldsloc1 = sloc1;
			while ((sloc1 != maxsloc1) && (version1[sloc1++] != '.'));
			n1 = atoi(version1.substr(oldsloc1, sloc1 - oldsloc1).c_str());
		}
		else n1 = 0;

		if (!isn2_equal0)
		{
			int oldsloc2 = sloc2;
			while ((sloc2 != maxsloc2) && (version2[sloc2++] != '.'));
			n2 = atoi(version2.substr(oldsloc2, sloc2 - oldsloc2).c_str());
		}
		else n2 = 0;

		if (n1 > n2)
			return 1;
		else if (n1 < n2)
			return -1;
		else
		{
			if ((sloc1 != maxsloc1) && (sloc2 != maxsloc2))
				continue;
			else if ((sloc1 == maxsloc1) && (sloc2 == maxsloc2)) return 0;
			else if (sloc1 == maxsloc1) isn1_equal0 = true;
			else isn2_equal0 = true;
		}
	}
	return -999; //dump return
}

string Solution::fractionToDecimal(int numerator, int denominator)
{
	//除下去
	//出现0就强制退出
	//否则等待出现重复的循环小数

	long long fnumerator = numerator;
	long long fdenominator = denominator;
	//傻逼大数字
	if ((fnumerator == INT_MIN) && (fdenominator == -1))
		return "2147483648";
	else if (fnumerator%fdenominator == 0)
		return to_string(fnumerator / fdenominator);
	else
	{
		string res1 = "";
		if (double(numerator) / double(denominator) < 0)
		{
			if (numerator / denominator == 0)
				res1 += "-";
		}
		res1 += to_string(fnumerator / fdenominator);
		string res2 = "";
		fnumerator %= fdenominator;
		unordered_map<long long, int> his = {};
		his[fnumerator] = -1;
		int loc = 0;
		while (true)
		{
			fnumerator *= 10;
			long long yushu = fnumerator % fdenominator;
			if (yushu == 0)
			{
				res2 += to_string(abs(fnumerator / fdenominator));
				return res1 + "." + res2;
			}
			else
			{
				if (his.find(yushu) != his.end())
				{
					//结束了
					res2 += to_string(abs(fnumerator / fdenominator));
					return res1 + "." + res2.substr(0, his[yushu] + 1) + "(" + res2.substr(his[yushu] + 1) + ")";
				}
				else
				{
					res2 += to_string(abs(fnumerator / fdenominator));
					his[yushu] = loc++;
					fnumerator = yushu;
				}
			}
		}
		return "";  //dump
	}
}

pair<bool, int> Solution::iter_two_search_find_167(vector<int>& numbers, int target, int startloc, int endloc)
{
	if (startloc > endloc)
		return pair<bool, int> {false, 0};
	else if (startloc == endloc)
		if (numbers[startloc] == target)
			return pair<bool, int> {true, startloc};
		else
			return pair<bool, int> {false, 0};
	else
	{
		int mid = (startloc + endloc) / 2;
		if (numbers[mid] < target)
			return iter_two_search_find_167(numbers, target, mid + 1, endloc);
		else if (numbers[mid] > target)
			return iter_two_search_find_167(numbers, target, startloc, mid - 1);
		else
			return pair<bool, int> {true, mid};
	}
}

vector<int> Solution::twoSum_167(vector<int>& numbers, int target)
{
	//二分查找,你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素
	//下标从1开始
	//好像一定能找到答案??
	int nsize_m1 = numbers.size() - 1;

	for (int i = 0; i <= nsize_m1; i++)
	{
		if ((numbers[i] + numbers[nsize_m1]) < target)
			continue;
		else
		{
			pair<bool, int> res = iter_two_search_find_167(numbers, target - numbers[i], i + 1, numbers.size());
			if (res.first)
				return vector<int> {i + 1, res.second + 1};
			else
				continue;
		}
	}
	return vector<int> {};  //dump
}

string Solution::convertToTitle(int n)
{
	//不停地除以26
	//这是正整数!
	string res = "";
	while (n > 0)
	{
		res.insert(res.begin(), n % 26 + 'A' - 1);
		n /= 26;
	}
	return res;
}

int Solution::majorityElement(vector<int>& nums)
{
	//总是存在
	//O(n)
	int nsize = nums.size();
	unordered_map<int, int> m;
	for (auto num : nums)
	{
		m[num]++;
		if (m[num] > nsize / 2)
			return num;
	}
	//dump
	return -999;
}

#else
#endif
