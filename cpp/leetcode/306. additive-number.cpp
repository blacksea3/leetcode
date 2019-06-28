#include "public.h"

//4ms, 91.58%
//DFS

class Solution {
public:
	bool isAdditiveNumber(string num) {
		if (num.size() <= 2) return false;
		for (int i = 1; 2 * i <= num.size(); i++) {
			for (int j = 1; i + 2 * j <= num.size(); j++) {
				if (dfs(num, str2int(num.substr(0, i)), str2int(num.substr(i, j)), i + j, j))
					return true;
			}
			if (num[0] == '0') break;
		}
		return false;
	}
private:
	bool dfs(const string& num, long pre, long prepre, int i, int len) {
		if (i == num.size()) return true;
		if ((i > num.size())) return false;
		for (int j = len; j <= num.size(); j++) {
			long cur = str2int(num.substr(i, j));
			if (cur == -1) return false;
			if (cur == pre + prepre && dfs(num, prepre, cur, i + j, j))
				return true;
		}
		return false;
	}

	long str2int(const string& s) {
		if (s.size() > 1 && s[0] == '0') return -1;
		long sum = 0;
		for (auto c : s) {
			if (sum >= LONG_MAX / 10) return -1;
			sum = sum * 10 + c - '0';
		}
		return sum;
	}
};
