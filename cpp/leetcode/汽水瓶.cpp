#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
int main()
{
	ifstream cin;  //¸²¸ÇÈ«¾Östd:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\qishuipin.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		vector<int> res;
		int pren;
		while(cin >> pren)
		{
			if (pren == 0) break;
			//Ä£Äâ
			int r = 0;
			while (pren >= 3)
			{
				r += pren / 3;
				pren -= (pren / 3) * 2;
			}
			if (pren == 2) r++;
			res.emplace_back(r);
		}

		for (auto& iterres : res) cout << iterres << endl;
	}
}
*/
