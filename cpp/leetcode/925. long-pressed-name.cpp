#include "public.h"

//0ms, 100%
//两个一起数相同字符个数, 需要每次都是同一个字母而且出现次数都是typed>name, 而且最后要一起结束

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int nloc = 0;
		int tloc = 0;

		char nc = '!';
		char tc = '!';
		int nt = 1;
		int tt = 1;
		while (nloc < name.size() && tloc < typed.size())
		{
			if (nc == '!')
			{
				nc = name[nloc];
				tc = typed[tloc];
				nloc++;
				tloc++;
				if (nc == tc) continue;
				else return false;
			}
			else
			{
				while (nloc < name.size() && name[nloc] == nc)
				{
					nloc++;
					nt++;
				}
				while (tloc < typed.size() && typed[tloc] == nc)
				{
					tloc++;
					tt++;
				}
				if (nt <= tt)
				{
					nc = '!';
					tc = '!';
					nt = 1;
					tt = 1;
					continue;
				}
				else return false;
			}
		}
		while (nloc < name.size() && name[nloc] == nc)
		{
			nloc++;
			nt++;
		}
		while (tloc < typed.size() && typed[tloc] == nc)
		{
			tloc++;
			tt++;
		}
		if (nt > tt)
		{
			return false;
		}
		return nloc == name.size() && tloc == typed.size();
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->isLongPressedName("alex", "alleex");
	cout << s->isLongPressedName("vtkgn", "vttkgnn");
	return 0;
}
*/
