#include "public.h"

//���TLE��
//��https://leetcode.com/problems/largest-component-size-by-common-factor/solution/��bellkross���ѽ���������
//������е�����
//Ȼ���ʼ������A��������group��, ��Ҷ�����������, ����������������ͬһ������, ��ô�ϲ�����group
//�����������group

class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		if (A.empty()) return 0;
		int max = maximum(A);
		vector<int> p = primes(max + 1);
		UF u(A);
		int prev = -1;
		for (int pr : p) {
			prev = -1;
			for (int a : A) {
				if (a % pr == 0) {
					if (prev == -1) {
						prev = a;
					}
					else {
						u.connect(prev, a);
						prev = a;
					}
				}
			}
		}
		return u.maxSize();
	}
private:
	class UF {
	public:
		UF(const vector<int>& vec) : mxSize(1) {
			for (int v : vec) {
				map[v] = v;
				sz[v] = 1;
			}
		}

		void connect(int a, int b) {
			if (isConnected(a, b)) return;
			int rta = root(a);
			int rtb = root(b);
			if (sz[rta] > sz[rtb]) {
				map[rtb] = rta;
				sz[rta] += sz[rtb];
			}
			else {
				map[rta] = rtb;
				sz[rtb] += sz[rta];
			}
		}

		bool isConnected(int a, int b) {
			return root(a) == root(b);
		}

		int maxSize() {
			for (auto it = sz.begin(); it != sz.end(); ++it) {
				if (it->second > mxSize) {
					mxSize = it->second;
				}
			}
			return mxSize;
		}
	private:
		unordered_map<int, int> map;
		unordered_map<int, int> sz;
		int mxSize;

		int root(int i) {
			while (i != map[i]) {
				map[i] = map[map[i]];
				i = map[i];
			}
			return i;
		}
	};

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

	int maximum(const vector<int>& vec) {
		int max = 0;
		for (int v : vec) {
			if (v > max) max = v;
		}
		return max;
	}
};