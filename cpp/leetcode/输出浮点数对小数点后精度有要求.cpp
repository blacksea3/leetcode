#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
int main()
{
	{
		string s;
		cin >> s;
		char oldChar = s[0];
		int sSize = s.size();
		int differents = 0;

		for (int index = 1; index < sSize; ++index)
		{
			if (s[index] != oldChar)
			{
				differents++;
				oldChar = s[index];
			}
		}
		differents++;
		cout.setf(ios_base::fixed, ios_base::floatfield);	//使用定点计数法，精度指的是小数点后面的位数，而不是总位数
		cout.setf(ios_base::showpoint);					//显示小数点后面的0	
		cout.precision(2);				//使用定点计数法，显示小数点后面位数精度
		cout << sSize / (double)differents << endl;
	}
	return 0;
}
*/
