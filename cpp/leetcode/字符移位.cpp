#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//类似冒泡排序
//原地算法
void moveChar(string& s)
{
	int sSize = s.size();
	for (int ri = sSize - 1; ri >= 1; --ri)
	{
		for (int le = 0; le < ri; ++le)
		{
			if (s[le] <= 'Z' && s[le + 1] >= 'a') swap(s[le], s[le + 1]);
		}
	}
}

/*
int main()
{
	{
		string s;
		while (cin >> s)
		{
			moveChar(s);
			cout << s << endl;
		}
	}
}
*/
