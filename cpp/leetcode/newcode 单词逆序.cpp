#include "public.h"


/*
//�����ļ��� D:\PC\GitFiles\leetcode\cpp\data

int main()
{
	ifstream cin;  //����ȫ��std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\dancinixu.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}

	//�����￪ʼ����
	std::string strLine;
	for (int i = 0; i < 1; ++i)  //1��
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
