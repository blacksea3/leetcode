#include "include.h"

#ifdef LEETCODE_41_50
#include "public.h"
#include "leetcode.h"
int Solution::firstMissingPositive(vector<int>& nums)
{
	//�����㷨,������ҵ�py3ʵ��
	//���ֲ���
	//����:��nums�Ŀռ���������,ʹ�ÿռ�ʹ��Ϊ������

	int nsize = nums.size();

	int loc = 0;
	while (loc < nsize)
	{
		if ((nums[loc] > 0) && (nums[loc] <= nsize))
		{
			if (nums[loc] != (loc + 1))
			{
				if (nums[nums[loc] - 1] != nums[loc])
				{
					int temp = nums[nums[loc] - 1];
					nums[nums[loc] - 1] = nums[loc];
					nums[loc] = temp;
				}
				else nums[loc] = -1;
			}
			else loc++;
		}
		else loc++;
	}

	for (int i = 0; i < nsize; i++)
	{
		if (nums[i] != (i + 1)) return (i + 1);
	}
	return nsize + 1;
}

int Solution::trap(vector<int>& height)
{
	int hsize = height.size();
	if (hsize <= 2) return 0;

	//����ͷ���м���� ���������ˮ�������� ��ȥԭ���ӵ������ ��Ĩȥ��ߵ㣩,���α���
	int res = 0;
	int left = 0;
	int right = hsize - 1;
	int pre_height = 0;
	int max_height = 0;

	while (left < right)
	{
		if ((height[left] > pre_height) && (height[right] > pre_height))
		{
			if (height[left] <= height[right])
			{
				res += (right - left + 1)*(height[left] - pre_height);
				pre_height = height[left];
				max_height = height[right];
			}
			else
			{
				res += (right - left + 1)*(height[right] - pre_height);
				pre_height = height[right];
				max_height = height[left];
			}
		}

		if (height[left] <= pre_height) left++;
		if (height[right] <= pre_height) right--;
	}

	if (height[left] > max_height) max_height = height[left];
	if (height[right] > max_height) max_height = height[right];

	int sum_height = 0;
	for (int i = 0; i < hsize; i++)
	{
		sum_height += height[i];
	}

	return res - sum_height + max_height - pre_height;
}

string Solution::multiply(string num1, string num2)
{
	//Ϊ�˷�ֹ���,ÿ��ȡnum1��4λ��num2��4λ����
	// aaaabbbb * ccccdddd :
	//1-4λ=bbbb*dddd%10000; ��17-9λ=aaaa*cccc; �����Ǽ�һ��

	//4λ4λ�ػ�ȡ����,��һ�³��Ⱦ�֪��Ӧ����ô����:)

	//�������
	if ((num1 == "0") || (num2 == "0")) return "0";

	int n1size = num1.size();  //must >= 1
	int n2size = num2.size();  //must >= 1
	int n1time_4 = (n1size - 1) / 4 + 1;
	int n2time_4 = (n2size - 1) / 4 + 1;
	bool n1time_4_le_n2time_4 = true;

	if (n1time_4 > n2time_4)
	{
		num1.swap(num2);
		int temp;
		temp = n1size;
		n1size = n2size;
		n2size = temp;
	}
	string res = "";

	//n1size/4 = 2; n2size/4 = 3    1:1 1:2 2:1 1:3 2:2 3:1

	int carry = 0;
	int nine_digit = 0;
	for (int sum = 2; sum <= (n1time_4 + n2time_4); sum++)
	{
		nine_digit = carry;   //ÿ��ѭ���ľ�λ����ʼ��
		for (int n1loc = 1; n1loc <= min(n1time_4, sum - 1); n1loc++)
		{
			//�Ӻ���ȡ��λ��
			int tempint1 = 0;
			if ((n1size - 1 - 4 * n1loc) >= 0)
				for (int j = (n1size - 4 * n1loc); j < (n1size - 4 * n1loc + 4); j++)
					tempint1 = tempint1 * 10 + (num1[j] - '0');
			else
				for (int j = 0; j < (n1size - 4 * n1loc + 4); j++)
					tempint1 = tempint1 * 10 + (num1[j] - '0');

			int tempint2 = 0;
			if ((n2size - 1 - 4 * (sum - n1loc)) >= 0)
				for (int j = (n2size - 4 * (sum - n1loc)); j < (n2size - 4 * (sum - n1loc) + 4); j++)
					tempint2 = tempint2 * 10 + (num2[j] - '0');
			else
				for (int j = 0; j < (n2size - 4 * (sum - n1loc) + 4); j++)
					tempint2 = tempint2 * 10 + (num2[j] - '0');
			nine_digit += tempint1 * tempint2;
		}
		string tempstr;
		tempstr = to_string((nine_digit) % 10000);
		//��ȫλ��
		while (tempstr.size() < 4) tempstr = "0" + tempstr;
		res = tempstr + res;
		carry = (nine_digit) / 10000;
	}



	if (carry != 0)
	{
		string tempstr;
		tempstr = to_string(carry);
		res = tempstr + res;
	}
	else
	{
		int loc = 0;
		while (res[loc] == '0')   //���õ����±�Խ��,��Ϊ���ȫΪ0��ֻ��"0",��ͷ�Ѿ��жϵ���
			loc++;
		res = res.substr(loc);
	}
	return res;
}

bool Solution::isMatch_44(string s, string p)
{
	//dp��̬�滮
	//if p[j] != '*' dp[i][j] = dp[i-1][j-1] && ((s[i] == p[j]) || (p[j] == '?'))
	//else dp[i][j] = dp[i][j-1] || dp[i-1][j]
	
	//dp[i][j]: s[0:i-1]��p[0:j-1]�Ƿ�ƥ�� i==0 or j==0��ʾ���ַ���,�����ַ�����ƥ���

	int ssize = s.size();
	int psize = p.size();

	bool **dp = new bool*[psize + 1];
	for (int i = 0; i <= psize; i++) {
		dp[i] = new bool[ssize + 1];
	}

	//vector<vector<bool>> dp(psize+1, vector<bool>(ssize+1, false));
	
	dp[0][0] = true;

	for (int j = 1; j <= ssize; j++)
		dp[0][j] = false;

	for (int i = 1; i <= psize; i++)
		dp[i][0] = dp[i - 1][0] && (p[i - 1] == '*');

	for (int i = 1; i <= psize; i++)
		for (int j = 1; j <= ssize; j++)
		{
			if (p[i-1] != '*')
				dp[i][j] = dp[i - 1][j - 1] && ((s[j - 1] == p[i - 1]) || (p[i - 1] == '?'));
			else
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
		}

	bool returnres = dp[psize][ssize];
	//if (dp[psize][ssize]) returnres = true;
	//else returnres = false;

	for (int i = 0; i <= psize; i++)
		delete[] dp[i];

	delete[] dp;

	return returnres;
}

int Solution::jump(vector<int>& nums)
{
	//�������ɨ��
	//���ڵ�ǰ�����������λ��,������һ������Զλ��,���Ǹ�����������һ����Զλ�õĵط���,��Ϊ
	//������һ������������

	int nsize = nums.size();
	//�������
	if (nsize == 1) return 0;
	if (nsize == 2) return 1;
	if (nums[0] >= nsize - 1) return 1;

	int startloc = 0;
	int maxdistance = 0;
	int maxloc = 0;
	int times = 0;
	//����������������β��
	while (true)
	{
		maxdistance = nums[startloc];
		maxdistance = 0;
		maxloc = 0;
		for (int i = 0; i < nums[startloc]; i++)
		{
			if ((i + nums[startloc + 1 + i]) > maxdistance)
			{
				maxdistance = i + nums[startloc + 1 + i];
				maxloc = startloc + 1 + i;
			}
		}
		times++;
		if ((maxloc + nums[maxloc]) >= nsize - 1) return (times + 1);
		else startloc = maxloc;
	}

	return times;
}

vector<vector<int>> Solution::permute(vector<int>& nums)
{
	//����

	int nsize = nums.size();
	if (nsize == 1) return vector<vector<int>> {nums};

	vector<vector<int>> nums1, nums2;
	bool isnums1 = true;
	nums1.push_back(vector<int> {});
	nums1[0].push_back(nums[0]);

	for (int i = 1; i < nsize; i++)
	{
		//��ǰһ��vector�����ϸ����ط�����
		if (isnums1)
		{
			nums2.clear();
			for (int j = 0; j <= i; j++) //��0��λ��i��λ����
			{
				for (int k = 0; k < nums1.size(); k++)
				{
					vector<int> temp = nums1[k];
					temp.insert(temp.begin() + j, nums[i]);
					nums2.push_back(temp);
				}
			}
			isnums1 = false;
		}
		else
		{
			nums1.clear();
			for (int j = 0; j <= i; j++) //��0��λ��i��λ����
			{
				for (int k = 0; k < nums2.size(); k++)
				{
					vector<int> temp = nums2[k];
					temp.insert(temp.begin() + j, nums[i]);
					nums1.push_back(temp);
				}
			}
			isnums1 = true;
		}
	}
	return (isnums1) ? nums1 : nums2;
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
	//������
	sort(nums.begin(), nums.end());


	int nsize = nums.size();
	if (nsize == 1) return vector<vector<int>> {nums};

	vector<vector<int>> nums1, nums2;
	bool isnums1 = true;
	nums1.push_back(vector<int> {});
	nums1[0].push_back(nums[0]);
	int oldnum = nums[0];   //��ʼ��oldnum

	//����
	for (int i = 1; i < nsize; i++)
	{
		bool need_if_unique = (oldnum == nums[i]);

		//��ǰһ��vector�����ϸ����ط�����
		if (isnums1)
		{
			nums2.clear();
			for (int j = 0; j <= i; j++) //��0��λ��i��λ����
			{
				for (int k = 0; k < nums1.size(); k++)
				{
					vector<int> temp = nums1[k];
					temp.insert(temp.begin() + j, nums[i]);
					if (!need_if_unique) nums2.push_back(temp);
					else if (find(nums2.begin(), nums2.end(), temp) == nums2.end())
						nums2.push_back(temp);
				}
			}
			isnums1 = false;
		}
		else
		{
			nums1.clear();
			for (int j = 0; j <= i; j++) //��0��λ��i��λ����
			{
				for (int k = 0; k < nums2.size(); k++)
				{
					vector<int> temp = nums2[k];
					temp.insert(temp.begin() + j, nums[i]);
					if (!need_if_unique) nums1.push_back(temp);
					else if (find(nums1.begin(), nums1.end(), temp) == nums1.end())
						nums1.push_back(temp);
				}
			}
			isnums1 = true;
		}
		oldnum = nums[i];
	}
	return (isnums1) ? nums1 : nums2;
}

void Solution::rotate(vector<vector<int>>& matrix)
{
	//����ô��ת��,һ�β���4����
	//������Ȧ��ʼ
	//���ǵ������n*n����
	int sidelength = matrix.size();

	for (int i = 0; i < sidelength / 2; i++)
	{
		for (int j = 0; j < (sidelength - 2 * i - 1); j++)
		{
			int temp = matrix[i][i + j];
			matrix[i][i + j] = matrix[sidelength - 1 - i - j][i];
			matrix[sidelength - 1 - i - j][i] = matrix[sidelength - 1 - i][sidelength - 1 - j - i];
			matrix[sidelength - 1 - i][sidelength - 1 - j - i] = matrix[i + j][sidelength - 1 - i];
			matrix[i + j][sidelength - 1 - i] = temp;
		}
	}
}


vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
	//����ĸ����

	unordered_map<string, vector<string>> allstrs = {};

	//һ�ֱ���
	for (int i = 0; i < strs.size(); i++)
	{
		//ͳ����ĸ����
		vector<int> pre_num(26, 0);

		for (int j = 0; j < strs[i].size(); j++)
			pre_num[strs[i][j] - 'a'] += 1;

		string key = "";
		for (int j = 0; j < 26; j++)
		{
			key += to_string(pre_num[j]);
			key += "#";
		}

		allstrs[key].push_back(strs[i]);
	}

	vector<vector<string>> returnres = {};
	for (unordered_map<string, vector<string>>::iterator iter = allstrs.begin(); iter != allstrs.end(); iter++){
		returnres.push_back(iter->second);
	}
	
	
	return returnres;
}

double Solution::myPow(double x, int n)
{
	double res = 1.0;
	bool sign = (n >= 0);

	while (n != 0)
	{
		if (n % 2 != 0)
			res *= x;
		x *= x;
		n /= 2;
	}

	return (sign) ? res : 1 / res;
}

#else
#endif


