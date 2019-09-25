#include "public.h"


/*
//数据文件夹 D:\PC\GitFiles\leetcode\cpp\data

int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\dancinixu.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}

	//从这里开始复制
	std::string strLine;
	for (int i = 0; i < 1; ++i)  //1行
	{
		getline(cin, strLine);
		//cout << strLine << endl;
	}

	vector<string> v;
	int index = 0;
	string temp;
	while (index < strLine.size())
	{
		if (strLine[index] == ' ')
		{
			if (temp.size() > 0) v.emplace_back(temp);
			temp = "";
		}
		else
		{
			temp.push_back(strLine[index]);
		}
		index++;
	}
	v.emplace_back(temp);

	string res;
	for (int vindex = v.size() - 1; vindex >= 0; --vindex) res += (v[vindex] + " ");
	res.pop_back();
	cout << res << endl;
}
*/
