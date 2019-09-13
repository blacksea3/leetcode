#include "public.h"

//88ms, 97.99%
//���ݷ�

class Solution {
private:
	vector<vector<int>> res;

	//startn: ��ʼn; totaln: ���n; remainn: ʣ�����ָ���; prev:��ǰ����
	void backTrack(int startn, int totaln, int remainn, vector<int>& prev)
	{
		for (int i = startn; i <= (totaln - remainn + 1); ++i)
		{
			prev.emplace_back(i);
			if (remainn == 1) res.push_back(prev);
			else backTrack(i + 1, totaln, remainn - 1, prev);
			prev.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) 
	{
		vector<int> nums;
		backTrack(1, n, k, nums);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> res = s->combine(1, 1);
	return 0;
}
*/