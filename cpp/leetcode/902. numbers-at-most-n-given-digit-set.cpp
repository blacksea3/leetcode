#include "public.h"

//8ms, 38.64%
//��ѧ:
//����С��N��λ����

class Solution {
private:
	//����ֵ��һ����<cp�ĸ���, �ڶ�������û��=cp��
	pair<int, bool> getsmaller(vector<string>& D, int cp)
	{
		int loc = 0;

		for (; loc < D.size(); ++loc)
		{
			if ((D[loc][0] - '0') >= cp) break;
		}

		if (loc < D.size() && (D[loc][0] - '0') == cp) return { loc, true };
		else return { loc, false };
	}

public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
		int dsize = D.size();
		int locs = 0;
		int cpN = N;
		vector<int> nums;
		while (cpN > 0)
		{
			locs++;
			nums.insert(nums.begin(), cpN % 10);
			cpN /= 10;
		}

		int res = 0;

		//λ��С��
		for (int i = 1; i <= locs - 1; ++i)
		{
			res += pow(dsize, i);
		}

		//λ����ȵ�
		for (int i = 0; i < locs; ++i)
		{
			pair<int, bool> temp = getsmaller(D, nums[i]);
			res += temp.first*pow(dsize, locs - i - 1);
			if (!temp.second) break;
			else if (i == locs - 1) res++;
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> D = { "1","3","5","7" };
	cout << s->atMostNGivenDigitSet(D, 133);
	return 0;
}
