#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string isThreeIncreasingExist(vector<int>& num)
{
	int min = num[0];
	int mid = -1;

	int nSize = num.size();

	for (int index = 1; index < nSize; ++index)
	{
		if (mid == -1)
		{
			if (num[index] <= min)
			{
				min = num[index];
			}
			else
			{
				mid = num[index];
			}
		}
		else
		{
			if (num[index] > mid) return "true";
			else if (num[index] == mid) continue;
			else if (num[index] < mid)
			{
				if (num[index] <= min) min = num[index];
				else mid = num[index];
			}
		}
	}
	return "false";
}

/*
int main()
{
	{
		int n;
		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> num[i];
		}

		cout << isThreeIncreasingExist(num) << endl;

	}
}
*/
