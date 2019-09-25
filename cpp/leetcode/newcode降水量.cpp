#include <iostream>
#include <fstream>
#include <vector>
//#include <algorithm>
#include <numeric>

using namespace std;

int getRainPool(vector<int> heights)
{
	//双向单调栈
	//然后生成整个大小, 再减掉heights之和

	vector<pair<int, int>> left;
	vector<pair<int, int>> right;
	int hsize = heights.size();

	int his = 0; //历史高度

	for (int index = 0; index < hsize; ++index)
	{
		if (heights[index] > his)
		{
			left.emplace_back(pair<int, int>{ heights[index], index });
			his = heights[index];
		}
	}

	his = 0;
	for (int index = hsize - 1; index >= 0; --index)
	{
		if (heights[index] > his)
		{
			right.emplace_back(pair<int, int>{ heights[index], index });
			his = heights[index];
		}
	}

	//计算
	int total = 0;
	int his_height = 0;
	int his_index = -1;
	for (auto& l : left)
	{
		total += his_height * (l.second - his_index);
		his_height = l.first;
		his_index = l.second;
	}

	his_height = 0;
	his_index = heights.size();
	for (auto& r : right)
	{
		total += his_height * (his_index - r.second);
		his_height = r.first;
		his_index = r.second;
	}

	total += left[left.size() - 1].first * (right[right.size() - 1].second - left[left.size() - 1].second + 1);

	return total - accumulate(heights.begin(), heights.end(), 0);
}

/*
int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\jiangshuiliang.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		int n;
		cin >> n;

		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		cout << getRainPool(v);
	}
}
*/
