#include "public.h"

//52ms, 5.80%
//为了代码方便起见: 冒泡排序

class Solution {
private:
	//注意: l1一定下标在l2左边
	//返回true: l1 < l2
	bool msort(const string& l1, const string& l2)
	{
		//分辨是数字还是字母
		int loc1 = 0;
		bool isnum1 = true;
		while (l1[loc1] != ' ') loc1++;
		loc1++;
		if (!isdigit(l1[loc1])) isnum1 = false;

		int loc2 = 0;
		bool isnum2 = true;
		while (l2[loc2] != ' ') loc2++;
		loc2++;
		if (!isdigit(l2[loc2])) isnum2 = false;

		if (isnum1 && isnum2) return true;
		else if (isnum1 && !isnum2) return false;
		else if (!isnum1 && isnum2) return true;
		else
		{
			while (loc1 < l1.size() && loc2 < l2.size())
			{
				//突进扫描:
				int len1 = 1;
				int len2 = 1;
				while ((loc1 + len1) < l1.size() && l1[loc1 + len1] != ' ') len1++;
				while ((loc2 + len2) < l2.size() && l2[loc2 + len2] != ' ') len2++;
				string s1 = l1.substr(loc1, len1);
				string s2 = l2.substr(loc2, len2);
				if (s1 < s2) return true;
				else if (s1 > s2) return false;
				else
				{
					loc1 += (len1 + 1);
					loc2 += (len2 + 1);
				}
			}
			if (loc1 == l1.size()) return true;
			else return false;
		}
	}

public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		//冒泡
		for (int i = 0; i < logs.size() - 1; ++i)
		{
			for (int start = 0; start < logs.size() - 1 - i; ++start)
			{
				if (!msort(logs[start], logs[start + 1]))
					swap(logs[start], logs[start + 1]);
			}
		}
		return logs;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> logs = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" };
	auto res = s->reorderLogFiles(logs);
	return 0;
}
*/
