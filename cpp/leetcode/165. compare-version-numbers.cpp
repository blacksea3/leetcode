#include "public.h"

//状态机, 0ms, 100%

class Solution {
public:
	int compareVersion(string version1, string version2) {
		//按顺序遍历,每次遍历一个有效数字
		//按题目意思,不会输入空字符串

		int sloc1 = 0;
		int sloc2 = 0;
		int maxsloc1 = version1.size();
		int maxsloc2 = version2.size();
		bool isn1_equal0 = false;
		bool isn2_equal0 = false;
		int oldsloc1 = 0;
		int oldsloc2 = 0;
		int n1, n2;

		while (true)
		{
			if (!isn1_equal0)
			{
				int oldsloc1 = sloc1;
				while ((sloc1 != maxsloc1) && (version1[sloc1++] != '.'));
				n1 = atoi(version1.substr(oldsloc1, sloc1 - oldsloc1).c_str());
			}
			else n1 = 0;

			if (!isn2_equal0)
			{
				int oldsloc2 = sloc2;
				while ((sloc2 != maxsloc2) && (version2[sloc2++] != '.'));
				n2 = atoi(version2.substr(oldsloc2, sloc2 - oldsloc2).c_str());
			}
			else n2 = 0;

			if (n1 > n2)
				return 1;
			else if (n1 < n2)
				return -1;
			else
			{
				if ((sloc1 != maxsloc1) && (sloc2 != maxsloc2))
					continue;
				else if ((sloc1 == maxsloc1) && (sloc2 == maxsloc2)) return 0;
				else if (sloc1 == maxsloc1) isn1_equal0 = true;
				else isn2_equal0 = true;
			}
		}
		return -999; //dump return
	}
};