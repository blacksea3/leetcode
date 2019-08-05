#include "public.h"

//4ms, 93.89%
//暴力DFS

class Solution {
private:
	//特别注意, 函数内部实现:查看num1+num2是否溢出
	vector<int> res;
	bool isfind = false;
	void DFS(const string& S, int start, int num1, int num2, vector<int>& pres)
	{
		long long target = (long long)num1 + num2;
		if (target > INT_MAX) return;
		int len = 0;
		int cpt = target;
		if (cpt == 0) len = 1;
		else
		{
			while (cpt > 0)
			{
				len++;
				cpt /= 10;
			}
		}
		//S往后len长度
		if (S.substr(start, len) == to_string(target))
		{
			pres.push_back(target);
			if ((len + start) == S.size())
			{
				res = pres;
				isfind = true;
				return;
			}
			else DFS(S, start + len, num2, target, pres);
		}
		else return;
	}

public:
	vector<int> splitIntoFibonacci(string S) {
		int left = 0;
		for (int mid = 1; mid < min(10, (int)S.size() - 1); ++mid)
		{
			for (int right = mid + 1; right < min(mid + 10, (int)S.size()); ++right)
			{
				if (isfind) return res;
				//0开头或溢出, 则continue
				if (mid != 1 && S[left] == '0') continue;
				if (right != mid + 1 && S[right] == '0') continue;
				long long num1 = stoll(S.substr(left, mid));
				if (num1 > INT_MAX) continue;
				long long num2 = stoll(S.substr(mid, right - mid));
				if (num2 > INT_MAX) continue;

				vector<int> temp;
				temp.push_back(num1);
				temp.push_back(num2);
				DFS(S, right, num1, num2, temp);
			}
		}
		return {};
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->splitIntoFibonacci("0000");
	return 0;
}
*/
