#include "public.h"

//764ms, 22.45%
//������е�����
//Ȼ���ʼ������A��������group��, ��Ҷ�����������, ����������������ͬһ������, ��ô�ϲ�����group
//�����������group
//group���ǲ��鼯

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
		init(A); //��ʼ�����鼯

		//��ȡ���п��ܵ�����
		//ֱ���������ֽ�
		unordered_map<int, unordered_set<int>> umv;
		for (auto& a : A)
			umv[a] = getprimes(a);

		//��¼���е��������Լ�ĳ��������(��ʵ���ǵ�һ��������)������
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

		//������Щ����, �����ͬ��������(����)������
		for (auto& iumv : umv)
		{
			for (auto& pri : iumv.second)
			{
				Merge(iumv.first, primes_num[pri]);
			}
		}
		//�鿴���Ĳ��鼯��С
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
