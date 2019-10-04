#include "public.h"

//44ms, 98.37%
//����300.����������� DP+���� O(nlogn)
//�ȶ��ŷ�����: �������, �߶Ƚ���
//�ر�ע��: �߶Ƚ����Ŀ����:
//  ���� [3,5], [6,8], [6,9] ���ǰ��ո߶������, ����Ը߶�����Ӧ�������������, ��ô������������, �ⲻ�������˹���޵�˫���ϸ����
// �����Ϊ�Կ����ͬ��, �߶Ƚ�������, ʹ��[6,9]��[6,8]ǰ��, ������Զ�����໥����

class Solution {
private:
	static bool msort(vector<int> const& v1, vector<int> const& v2)
	{
		if (v1[0] < v2[0]) return true;
		else if (v1[0] > v2[0]) return false;
		else return v1[1] > v2[1];
	}

	int lengthOfLIS(vector<vector<int>>& nums) {
		vector<int> dp;

		for (auto& num : nums)
		{
			vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), num[1]);
			if (iter == dp.end()) dp.emplace_back(num[1]);
			else dp[iter - dp.begin()] = num[1];
		}
		return dp.size();
	}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), msort);

		return lengthOfLIS(envelopes);
	}
};

/*
//688ms, 58.51%
//O(n^2) DP�ⷨ
//��¼ǰ�������ŷ���, �����ִ�ķ������

class Solution {
private:
	//������ѯ���ϣ�������VS2015�ж����ϸ�Ƚϵģ��������Ԫ����ȣ����뷵��false���ʸĳ����´��룬����ͨ�����
	static bool msort(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[0] < v2[0];
	}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		vector<int> dp(envelopes.size(), 0);

		sort(envelopes.begin(), envelopes.end(), msort);

		for (int i = 0; i < envelopes.size(); ++i)
		{
			int res = 1;
			for (int j = 0; j < i; ++j)
			{
				if ((envelopes[j][0] < envelopes[i][0]) && (envelopes[j][1] < envelopes[i][1]))
					res = max(res, dp[j] + 1);
			}
			dp[i] = res;
		}

		int rmax = 0;
		for (auto& idp : dp) rmax = max(idp, rmax);
		return rmax;
	}
};
*/

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> envelopes = { {5, 4},{6, 4},{6, 7},{2, 3} };
	cout << s->maxEnvelopes(envelopes);
	return 0;
}
*/
