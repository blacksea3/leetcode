#include "public.h"

//4ms, 75.96%
//DFS

class Solution {
public:
	bool isAdditiveNumber(string num) {
		int nSize = num.size();
		if (nSize <= 2) return false;
		for (int i = 1; 2 * i <= nSize; i++) {
			for (int j = 1; i + 2 * j <= nSize; j++) {
				if (dfs(num, str2int(num.substr(0, i)), str2int(num.substr(i, j)), i + j, j))
					return true;
			}
			if (num[0] == '0') break;
		}
		return false;
	}
private:
	bool dfs(string const& num, long pre, long prepre, int i, int len) {
		int nSize = num.size();
		if (i == nSize) return true;
		if (i > nSize) return false;
		for (int j = len; j <= nSize; j++) {
			long cur = str2int(num.substr(i, j));
			if (cur == -1) return false;
			if (cur == pre + prepre && dfs(num, prepre, cur, i + j, j))
				return true;
		}
		return false;
	}

	long str2int(string const& s) {
		if (s.size() > 1 && s[0] == '0') return -1;
		long sum = 0;
		for (auto& c : s) {
			if (sum >= LONG_MAX / 10) return -1;
			sum = sum * 10 + c - '0';
		}
		return sum;
	}
};
