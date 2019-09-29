#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//统计词频, 然后排序

pair<int, int> interestingNumber(map<int, int>& numbers)
{
	if (numbers.size() == 1)
	{
		int unin = numbers.begin()->second;
		return pair<int, int>{unin*(unin - 1) / 2, unin*(unin - 1) / 2};
	}
	else
	{
		map<int, int>::iterator gre = numbers.begin();
		gre++;
		map<int, int>::iterator les = numbers.begin();

		int minv = gre->first - les->first;
		int minr = gre->second * les->second;
		gre++;
		les++;

		while (gre != numbers.end())
		{
			if ((gre->first - les->first) < minv)
			{
				minv = gre->first - les->first;
				minr = gre->second * les->second;
			}
			else if ((gre->first - les->first) == minv)
			{
				minr += gre->second * les->second;
			}
			gre++;
			les++;
		}

		int anominr = 0;
		for (auto& n : numbers)
		{
			minr += n.second*(n.second - 1) / 2;
		}

		gre = numbers.begin();
		int maxr = les->second * gre->second;
		return pair<int, int>{minr, maxr};
	}
}

/*
int main()
{
	{
		int n;
		cin >> n;
		map<int, int> numbers;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			numbers[temp]++;
		}
		pair<int, int> res = interestingNumber(numbers);
		cout << res.first << ' ' << res.second << endl;
	}
}
*/
