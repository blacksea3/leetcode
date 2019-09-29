#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//分组, 伪线段树
/*
int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\zuigaofenshiduoshao.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		const int BLOCK = 100;
		int n, m;
		while (cin >> n >> m)
		{
			//对学生按学号/100分组
			vector<int> all(n, 0);
			for (int i = 0; i < n; ++i) cin >> all[i];
			vector<int> maxMark(n / BLOCK, 0);

			for (int i = 0; i < n / BLOCK; ++i)
			{
				maxMark[i] = *max_element(all.begin() + i * BLOCK, all.begin() + (i + 1) * BLOCK);
			}
			//maxMark[n / BLOCK] = *max_element(all.begin() + n / BLOCK * BLOCK, all.end());

			int count = 0;

			for (int qi = 0; qi < m; ++qi)
			{
				char op;
				int para1, para2;
				cin >> op >> para1 >> para2;

				//手动调整编号从0开始
				para1--;
				if (para1 < 0) para1 = 0;

				if (op == 'U')
				{
					all[para1] = para2;
					if (para1 / BLOCK < n / BLOCK)
					{
						maxMark[para1 / BLOCK] = *max_element(all.begin() + para1 / BLOCK * BLOCK,
							all.begin() + (para1 / BLOCK + 1) * BLOCK);
					}
				}

				else
				{
					count++;
					if (count == 63)
						int i = 1;
					para2--;
					if (para2 >= n) para2 = n - 1;
					if (para1 > para2) swap(para1, para2);


					//考虑[para1, para2]的范围, 此时已经是下标了!
					if (para1 / BLOCK == para2 / BLOCK)
					{
						cout << *max_element(all.begin() + para1,
							all.begin() + para2 + 1) << endl;
					}
					else
					{
						//计算头尾, 暴力
						int resMax = *max_element(all.begin() + para1,
							all.begin() + (para1 / BLOCK + 1) * BLOCK);
						resMax = max(resMax, *max_element(all.begin() + (para2 / BLOCK) * BLOCK,
							all.begin() + para2 + 1));
						for (int maxMarkIndex = para1 / BLOCK + 1; maxMarkIndex <= para2 / BLOCK - 1; ++maxMarkIndex)
						{
							resMax = max(resMax, maxMark[maxMarkIndex]);
						}
						cout << resMax << endl;
					}

				}

			}
		}
		return 0;
	}
}
*/