#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <algorithm> //find

using namespace std;

void getAllPemulation(unordered_set<char>& v, unordered_set<string>& total, string& pre)
{
	if (v.size() == 0) total.insert(pre);
	else
	{
		unordered_set<char> cpv = v;
		for (auto& iterv : cpv)
		{
			v.erase(iterv);
			pre.push_back(iterv);
			getAllPemulation(v, total, pre);
			pre.pop_back();
			v.insert(iterv);
		}
	}
}

string getLackPemulation(vector<string>& has)
{
	int total = has[0].size();  //total >=2, total <= 10;
	//暴力生成全排列
	unordered_set<string> stotal;
	unordered_set<char> group;
	for (auto& iter_c : has[0]) group.insert(iter_c);
	string pre = "";
	getAllPemulation(group, stotal, pre);

	for (auto& iter_total : stotal)
	{
		if (find(has.begin(), has.end(), iter_total) == has.end())
			return iter_total;
	}
	return "DUMP!!";
}


/*
int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\zifuchuanquanpailie.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; ++i)
		{
			string temp;
			cin >> temp;
			v.emplace_back(temp);
		}
		cout << getLackPemulation(v);
	}
}
*/
