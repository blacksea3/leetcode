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

	//�ӵ���Ŀ������д


	long long fnumerator = numerator;
	long long fdenominator = denominator;

	if ((fnumerator == INT_MIN) && (fdenominator == -1))
		return "2147483648";
	else if (fnumerator%fdenominator == 0)
		return to_string(fnumerator / fdenominator);
	else
	{
		string res1 = to_string(fnumerator / fdenominator);
		string res2 = "";
		fnumerator %= fdenominator;

		while (true)
		{
			fnumerator *= 10;
			res2 += to_string(fnumerator / fdenominator);
			if (fnumerator%fdenominator == 0)
				return res1 + "." + res2;
			else
			{
				int res2size = res2.size();
				//O(n)��������
				for (int i = res2size % 2; i <= res2size - 2; i += 2)
				{
					//�ж��ǲ���ȫ��0
					bool isallzero = true;
					for (auto ch : res2.substr(i, (res2size - i) / 2))
					{
						if (ch != '0')
						{
							isallzero = false;
							break;
						}
					}
					if (isallzero) continue;
					if (res2.substr(i, (res2size - i) / 2).compare(res2.substr(i + (res2size - i) / 2)) == 0)
						return res1 + "." + res2.substr(0, i) + "(" + res2.substr(i, (res2size - i) / 2) + ")";
				}
				fnumerator %= fdenominator;
			}
		}
		return "";  //dump
	}
}

#else
#endif
