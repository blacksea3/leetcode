#include "public.h"

//
//暴力, 来回取
//TLE, 待优化

class Solution {
private:
	bool isgood = false;
	double gblav;
	void DFS(vector<int> sortedv, double leftsum, double rightsum, double leftlen, double rightlen)
	{
		double leftav = leftsum / leftlen;
		if (leftav == gblav)
		{
			isgood = true;
			return;
		}
		if (isgood) return;
		if (sortedv.size() == 1) return;

		if (leftav > gblav)
		{
			int oldval = -1;
			for (int i = 0; i < sortedv.size(); ++i)
			{
				if (oldval == sortedv[i]) continue;
				else oldval = sortedv[i];
				if (sortedv[i] > gblav) return;
				int temp = sortedv[i];
				sortedv.erase(sortedv.begin() + i);
				DFS(sortedv, leftsum + temp, rightsum - temp, leftlen + 1, rightlen - 1);
				sortedv.insert(sortedv.begin() + i, temp);
				if (isgood) return;
			}
		}
		else
		{
			int oldval = -1;
			for (int i = 0; i < sortedv.size(); ++i)
			{
				if (oldval == sortedv[i]) continue;
				else oldval = sortedv[i];
				if (sortedv[i] < gblav) continue;
				int temp = sortedv[i];
				sortedv.erase(sortedv.begin() + i);
				DFS(sortedv, leftsum + temp, rightsum - temp, leftlen + 1, rightlen - 1);
				sortedv.insert(sortedv.begin() + i, temp);
				if (isgood) return;
			}
		}
	}

public:
	bool splitArraySameAverage(vector<int>& A) {
		if (A.size() == 1) return false;

		double sum = accumulate(A.begin(), A.end(), 0.0);
		double average = sum / (double)A.size();
		gblav = average;

		sort(A.begin(), A.end());

		int oldval = -1;
		for (int i = 0; i < A.size(); ++i)
		{
			if (oldval == A[i]) continue;
			else oldval = A[i];
			if (A[i] > average) return false;
			int temp = A[i];
			A.erase(A.begin() + i);
			DFS(A, temp, sum - temp, 1, A.size() - 1);
			A.insert(A.begin() + i, temp);
			if (isgood) return true;
		}
		return false;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 1,2,3,4,5,6,7,8 };
	//auto res = s->splitArraySameAverage(A);
	vector<int> A = { 3, 1 };
	auto res = s->splitArraySameAverage(A);
	return 0;
}