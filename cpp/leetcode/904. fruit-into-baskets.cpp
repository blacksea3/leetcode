#include "public.h"

//212ms, 45.78%
//滑动窗口
//找到最长的窗口能够包含的数字种类<=2

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int preloc = 0;
		int leftloc = -1;

		int num1 = -1;
		int num2 = -1;
		int num1maxloc = -1;
		int num2maxloc = -1;

		int res = -1;

		while (preloc < tree.size())
		{
			if (num1 == tree[preloc])
			{
				num1maxloc = preloc;
				preloc++;
			}
			else if (num2 == tree[preloc])
			{
				num2maxloc = preloc;
				preloc++;
			}
			else if (num1 == -1)
			{
				num1maxloc = preloc;
				num1 = tree[preloc];
				preloc++;
			}
			else if (num2 == -1)
			{
				num2maxloc = preloc;
				num2 = tree[preloc];
				preloc++;
			}
			else
			{
				res = max(res, preloc - leftloc - 1);
				if (num1maxloc > num2maxloc)
				{
					num2 = -1;
					leftloc = num2maxloc;
					num2maxloc = -1;
				}
				else
				{
					num1 = -1;
					leftloc = num1maxloc;
					num1maxloc = -1;
				}
			}
			
		}
		res = max(res, preloc - leftloc - 1);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> tree1 = { 3,3,3,1,2,1,1,2,3,3,4 };
	cout << s->totalFruit(tree1);
	vector<int> tree2 = { 0, 1, 1, 4, 3 };
	cout << s->totalFruit(tree2);
	vector<int> tree3 = { 1, 0, 1, 4, 1, 4, 1, 2, 3 };
	cout << s->totalFruit(tree3);
	return 0;
}
*/
