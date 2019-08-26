#include "public.h"

//764ms, 22.45%
//求出所有的质数
//然后初始化所有A至单独的group中, 大家都整除质数们, 若两个数可以整除同一个质数, 那么合并两个group
//最终求的最大的group
//group就是并查集

class Solution {
private:
	unordered_map<int, int> um;

	void init(vector<int>& vals)
	{
		for (auto& s : vals)
		{
			um[s] = s;
		}
	}

	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}

	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}

	vector<int> primes(const size_t n) {
		vector<bool> prime(n, true);
		prime[0] = false;
		prime[1] = false;
		for (size_t i = 2; i < n; ++i)
			prime[i] = true;
		for (size_t i = 2; i < n; ++i) {
			if (prime[i])
				for (size_t j = i * i; j < n; j += i)
					prime[j] = false;
		}
		vector<int> res;
		for (size_t i = 2; i < n; ++i) {
			if (prime[i])
				res.push_back(i);
		}
		return res;
	}

	unordered_set<int> getprimes(int a)
	{
		unordered_set<int> res;
		int d = 2;
		int x = a;
		while (d * d <= x) {
			if (x % d == 0) {
				while (x % d == 0)
					x /= d;
				res.insert(d);
			}
			d++;
		}
		if (x > 1 || res.empty())
			res.insert(x);
		return res;
	}

public:
	int largestComponentSize(vector<int>& A) {
		if (A.empty()) return 0;
		init(A); //初始化并查集

		//获取所有可能的质数
		//直接质因数分解
		unordered_map<int, unordered_set<int>> umv;
		for (auto& a : A)
			umv[a] = getprimes(a);

		//记录所有的质因数以及某个包含他(其实就是第一个包含他)的数字
		unordered_map<int, int> primes_num;

		for (auto& iumv : umv)
		{
			for (auto& pri : iumv.second)
			{
				if (primes_num.find(pri) == primes_num.end())
				{
					primes_num[pri] = iumv.first;
				}
			}
		}

		//连接这些数字, 如果相同公共因数(质数)则连接
		for (auto& iumv : umv)
		{
			for (auto& pri : iumv.second)
			{
				Merge(iumv.first, primes_num[pri]);
			}
		}
		//查看最大的并查集大小
		unordered_map<int, int> union_size; //father: unionsize
		for (auto& a : A)
		{
			union_size[GetFather(a)]++;
		}

		int res = 0;
		for (auto& iun : union_size)
		{
			res = max(res, iun.second);
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = {4, 6, 15, 35};
	cout << s->largestComponentSize(A);
	return 0;
}
