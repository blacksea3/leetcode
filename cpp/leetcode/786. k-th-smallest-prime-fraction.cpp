#include "public.h"

//
//����, dp[i]:��ʾ��i-1������Ϊ��ĸʱ�ĵ�ǰ��С����, ��ôdp[0]��dump��, ����leetcode TLE, ����AC 1764ms, 25.13% 

class Solution {
public:
	vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		vector<pair<double, int>> dp(A.size()); //��ǰ����:������A�е��±�, ���dp���±���Ƿ�ĸ��A�е��±�
		map<double, int> mins; //����: ��ĸ��A�е��±�

		for (int i = 1; i < A.size(); ++i)
		{
			dp[i] = pair<double, int>{ 1 / (double)A[i], 0 };
			mins.insert({ dp[i].first , i });
		}

		int prek = 1;
		while (prek < K)
		{
			pair<double, int> pre = *mins.begin();
			mins.erase(mins.begin());
			int mother = pre.second;
			if (mother == dp[mother].second + 1)
			{
				dp[mother].second += 2;
			}
			else dp[mother].second += 1;
			if (dp[mother].second < A.size())
			{
				dp[mother].first = A[dp[mother].second] / (double)A[mother];
				mins.insert({ dp[mother].first, mother });
			}
			prek++;
		}
		return { A[dp[(*mins.begin()).second].second], A[(*mins.begin()).second] }  ;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,2,3,5 };
	auto res = s->kthSmallestPrimeFraction(A, 3);
	return 0;
}