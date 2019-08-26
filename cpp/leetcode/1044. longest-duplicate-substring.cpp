#include "public.h"

//后缀数组不行, 内存超出FUCK

//2672ms, 35.51%
//二分+rabin-Karp
//此题C++语言不合适, 代码极其难写

//来自https://leetcode.com/problems/longest-duplicate-substring/discuss/291316/C%2B%2B-O(NlogN)-binary-search-%2B-double-checking-Rabin-Karp-unlike-other-RK-solutions-replying-on-luck

class Solution {
public:
	string longestDupSubstring(string &s) {
		// binary search on length of duplicate substring
		int n = s.size();
		int lo = 0, hi = n - 1, mid;
		int startIndex = -1, k = 0;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			int index = check(s, mid);
			if (index != -1) {
				// record
				startIndex = index;
				k = mid;
				// update search range
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}

		if (k == 0) {
			return "";
		}
		return s.substr(startIndex, k);
	}
private:
	// check if there exists two same substring of length k
	// Rabin-Karp, rolling hash
	// time O(N), space O(N)
	int check(string &s, int k) {
		int n = s.size();
		// all prime of the form 6k + 1, 6k - 1
		int q = 6 * (1 << 20) + 1;
		// base
		int b = 31;
		// precompute power = b^(k-1)
		int power = 1;
		for (int i = 1; i < k; i++) {
			power = (power * b) % q;
		}
		// double check by using hash table (key=hash code, value={startIndex})
		unordered_map<int, vector<int>> seen;
		// initialize
		int hash = 0;
		for (int i = 0; i < k; i++) {
			hash = (hash * b % q + s[i]) % q;
		}
		seen[hash].push_back(0);

		// rolling hash, Rabin-Karp
		for (int i = k; i < n; i++) {
			// remove old value
			hash = (hash - power * s[i - k] % q + q) % q;
			// add new value
			hash = (hash * b % q + s[i]) % q;
			if (seen.count(hash)) {
				// double check, key point!
				for (int &index : seen[hash]) {
					if (s.substr(index, k) == s.substr(i - k + 1, k)) {
						return index;
					}
				}
			}
			// add to hash table
			seen[hash].push_back(i - k + 1);
		}

		// does not find
		return -1;
	}
};
