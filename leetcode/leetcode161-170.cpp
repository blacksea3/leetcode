#include "include.h"

#ifdef LEETCODE_161_170
#include "public.h"
#include "leetcode.h"

int Solution::findPeakElement(vector<int>& nums)
{
	//��������
	//ע�⵽:   nums[mid] < nums[mid+1]   1 4 3 2 1  �������, �ܻ���mid+1��end���ַ�ֵԪ��
	//������Ϊmid+1��end���������˶���
	//����start��midһ����Ԫ��

	//ע�����ڵ�Ԫ�ز�ͬ

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
	//��������
	//���ǷǸ�����!
	if (nums.size() <= 1) return 0;
	else
	{
		int nmax = 0;
		//�ȸ��������
		for (auto num : nums)
			nmax = max(num, nmax);

		//�������������ж���λ,������order10_value�����10
		int order10_value = 0;
		while (nmax > 0)
		{
			nmax /= 10;
			order10_value++;
		}

		//�������,ȫ0?????
		if (order10_value == 0)
			return 0;
		else
		{
			//��ʽ��������
			vector<queue<int>> base(10, queue<int>{});
			vector<int> constants = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

			for (int i = 1; i <= order10_value; i++)  //i��λ��
			{
				for (auto num : nums)
				{
					if (i < 10)
						base[num%constants[i] / constants[i - 1]].push(num);
					else
						base[num / constants[i - 1]].push(num);
				}
				//�ϲ���nums
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

			//�������,��������ֵ
			int maxdiff = 0;
			for (int i = 1; i < nums.size(); i++)
				maxdiff = max(nums[i] - nums[i - 1], maxdiff);

			return maxdiff;
		}
	}
}

int Solution::compareVersion(string version1, string version2)
{
	//��˳�����,ÿ�α���һ����Ч����
	//����Ŀ��˼,����������ַ���

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
	//����ȥ
	//����0��ǿ���˳�
	//����ȴ������ظ���ѭ��С��

	long long fnumerator = numerator;
	long long fdenominator = denominator;
	//ɵ�ƴ�����
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
					//������
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
	//���ֲ���,����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ��
	//�±��1��ʼ
	//����һ�����ҵ���??
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
	//��ͣ�س���26
	//����������!
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
	//���Ǵ���
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
