#include "include.h"

#ifdef LEETCODE_181_190
#include "public.h"
#include "leetcode.h"

string Solution::extract_40_bits_187(long long num)
{
	string res;
	for (int i = 0; i < 10; i++)
	{
		num >>= 4;
		char temp = num & 0x0000000f;
		if (temp == 0x01)
			res.insert(res.begin(), 'A');
		else if (temp == 0x03)
			res.insert(res.begin(), 'C');
		else if (temp == 0x07)
			res.insert(res.begin(), 'G');
		else
			res.insert(res.begin(), 'T');
	}
	//��ô��������long�ĵ�20��60λ�������Ч������
	return res;
}

long long  Solution::generate_40_bits_187(string s)
{
	long long  res1 = 0;
	for (auto is : s)
	{
		res1 |= (((is & 0x10) >> 1) + (is & 0x07));
		res1 <<= 4;
	}
	//��ô��������long�ĵ�20��60λ�������Ч������
	return res1;
}


vector<string> Solution::findRepeatedDnaSequences(string s)
{
	//��������,λ����
	//A 0x41; C 0x43; G 0x47; T 0x54;
	//A 01000001 C 01000011 G 01000111 T 01010100

	//ȡ��4/6/7/8λ,Ȼ��һ���������ڶ�Ӧһ��40λΨһ������
	//�ƶ���������ʱͬʱ�ƶ����������
	//40λ��Ҫһ��long

	int ssize = s.size();
	if (ssize <= 10) return vector<string> {};

	//init
	unordered_set<long long > his;
	his.insert(generate_40_bits_187(s.substr(0, 10)));
	vector<string> res;

	for (int i = 1; i <= ssize - 10; i++)
	{
		long long ltemp = generate_40_bits_187(s.substr(i, 10));
		if (his.find(ltemp) != his.end())
		{
			string stemp = extract_40_bits_187(ltemp);
			vector<string>::iterator itea = find(res.begin(), res.end(), stemp);
			if (itea == res.end())
				res.push_back(stemp);
		}	
		else
			his.insert(ltemp);
	}
	return res;
}

int Solution::maxProfit(int k, vector<int>& prices)
{
	//Ūһ���޴��dp
	//dp[i][j]
	// 0 <= i < prices.size()
	// 0 <= j <= 2*k,  jΪż��:��ʾĿǰδ�ֲ�, jΪ������ʾĿǰ�ֲ�, (j+1)/2 ��ʾ������ǰ,�ѽ��е���������
	//����: j = 1��2 ��ʾ��ǰ�ǵ�һ������
	// k���=0 ,����0

	//ע�������������ڴ�ᱬ
	//����Ҫ����ĳһ�������Ϳ�����
	//��˲���Ҫi���ά��

	//ע��k,��Ч��k�����ܱ�prices.size() - 1��Ҫ��
	//����ע��,k >= prices.size()/2ʱ,����̰�ķ���,���Խ�ʡʱ��,����ʱ��ᱬ
	//������Ϊ,ֻҪ�������۹ɼ���α仯,ֻ��Ҫ��������Ϳ�����

	if (k == 0) return 0;
	if (prices.size() == 1) return 0;

	//����k
	if (k >= prices.size() / 2)
	{
		int res = 0;
		int old = INT_MAX;
		for (auto price : prices)
		{
			if (price > old) res += price - old;
			old = price;
		}
		return res;
	}
	else
	{
		vector<int> dp(2 * k + 1, 0);

		//����ǰ�����зǷ����,��ʵ���ϲ�Ҫ��:)  (����ͳ�������������,��������û�д���)
		for (int j = 0; j < k; j++)
			dp[2 * j + 1] = -1 * prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			for (int j = 0; j < k; j++)
			{
				dp[2 * j + 1] = max(dp[2 * j] - prices[i], dp[2 * j + 1]);
				dp[2 * j + 2] = max(dp[2 * j + 1] + prices[i], dp[2 * j + 2]);
			}
		}

		//Ŀǰδ�ֲֵ����ֵ
		int res = 0;
		for (int j = 0; j <= k; j++)
			res = max(dp[2 * j], res);

		return res;
	}
}

void Solution::rotate(vector<int>& nums, int k)
{
	if (nums.size() == 0) return;  //dump

	//�ȵ�֪��Ч���ƶ�����
	k = k % nums.size();
	if (k == 0) return;  //����Ҫ��ת

	//�����۵ķ���,ʱ�临�Ӷ�O(n)
	//��תǰ�벿��,��벿��,ȫ��,  ���Ӷȿ�����Ϊ��O(2*n) = O(n)

	reverse(nums.begin(), nums.begin() + nums.size() - k);
	reverse(nums.begin() + nums.size() - k, nums.end());
	reverse(nums.begin(), nums.end());

}

uint32_t Solution::reverseBits(uint32_t n)
{
	//���ص�λ����

	uint32_t res = 0;
	for (int i = 0; i < 32; i++)
	{
		res <<= 1;
		if (n & 0x00000001)
			res |= 0x00000001;
		n >>= 1;
	}
	return res;
}

#else
#endif
