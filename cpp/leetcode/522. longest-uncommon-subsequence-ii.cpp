#include "public.h"

//4ms, 89.80%
//���ȣ����ս��һ����ĳ���ַ�����������ǣ���ô��ǰ�����ڵĸ��ַ���һ��Ҳ���������У�����Ҫ����
//��˷������Ǹ��ַ�������������Ȼ�����ַ�����ʼ�ж�
//O(n^2)

class Solution {
private:
	static bool msort(const string& s1, const string& s2)
	{
		return s1.size() > s2.size();
	}
	bool isSubsequence(string s, string t) {
		int sloc = 0;
		int tloc = 0;

		while (sloc < s.size() && tloc < t.size())
		{
			if (t[tloc] == s[sloc])
			{
				tloc++;
				sloc++;
			}
			else tloc++;
		}
		if (sloc == s.size()) return true;
		else return false;
	}

public:
	int findLUSlength(vector<string>& strs) {
		sort(strs.begin(), strs.end(), msort);

		for (int index = 0; index < strs.size(); ++index)
		{
			string preStr = strs[index];

			bool isSpecial = true;
			for (int next = 0; next < strs.size(); ++next)
			{
				if (strs[next].size() < preStr.size()) break;
				else if (next == index) continue;
				else
				{
					if (isSubsequence(preStr, strs[next]))
					{
						isSpecial = false;
						break;
					}
				}
			}
			if (isSpecial) return preStr.size();
		}
		return -1;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> strs = { "aba","cdc","eae" };
	cout << s->findLUSlength(strs);
	return 0;
}
