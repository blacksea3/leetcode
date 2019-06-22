#include "public.h"

//32ms, 51.38%

class Solution {
private:
	//辗转相除法,将两个数等整数比例缩小至最大公约数为1
	//第一个数可能是负的
	pair<int, int> iter_gcd(pair<int, int> input)
	{
		//害怕溢出,md
		long num1;
		long num2;
		bool isexchange = false;
		if (abs(input.first) < abs(input.second))
		{
			int temp = input.first;
			input.first = input.second;
			input.second = temp;
			isexchange = true;
		}

		if (input.first > 0)
		{
			num1 = (long)input.first;
		}
		else
		{
			num1 = -1 * (long)input.first;
		}
		if (input.second > 0)
		{
			num2 = (long)input.second;
		}
		else
		{
			num2 = -1 * (long)input.second;
		}
		long max_yueshu;
		while (true)
		{
			max_yueshu = num1 % num2;
			num1 = num2;
			num2 = max_yueshu;
			if (max_yueshu == 0) break;
		}
		if (!isexchange)
		{
			long res1 = (long)(input.first) / num1;
			long res2 = (long)(input.second) / num1;
			return pair<int, int> {int(res1), (int)res2};
		}
		else
		{
			long res1 = (long)(input.second) / num1;
			long res2 = (long)(input.first) / num1;
			return pair<int, int> {int(res1), (int)res2};
		}
	}

	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}

public:
	int maxPoints(vector<vector<int>>& points) {
		//对某个给定点,对所有点扫一次进行唯一性记录:按照斜率记录
		//记录的值将是一个pair<int a,int b>表示 a/b (a可能是任意整数,b只能是正整数)
		//init:extra = 0
		//对于与给定点重复的点,extra+=1(注意,这个值必定>=1因为所有点包含那个给定点)
		//然后对于大量的斜率,找到数量最高的就可以了
		int psize = points.size();
		if (psize <= 2) return psize;
		map<pair<int, int>, int> slice_dict;
		int maxpoints = 0;

		//正式计算
		for (int i = 0; i < psize; i++)
		{
			int extra = 0;
			int tempmaxpoints = 0;
			slice_dict.clear();
			for (int j = 0; j < psize; j++)
			{
				if ((points[i][0] == points[j][0]) && (points[i][1] == points[j][1]))
					extra++;
				else
				{
					int dx = points[i][0] - points[j][0];
					int dy = points[i][1] - points[j][1];
					if (dx == 0)
					{
						slice_dict[pair<int, int>(1, 0)] += 1;
					}
					else if (dy == 0)
					{
						slice_dict[pair<int, int>(0, 1)] += 1;
					}
					else
					{
						int c = gcd(dy, dx);
						slice_dict[pair<int, int>{dy / c, dx / c}] += 1;
					}
				}
			}
			//扫一遍slice_dict
			for (map<pair<int, int>, int>::iterator iter = slice_dict.begin(); iter != slice_dict.end(); iter++)
			{
				tempmaxpoints = max(tempmaxpoints, iter->second);
			}
			tempmaxpoints += extra;
			maxpoints = max(maxpoints, tempmaxpoints);
		}
		return maxpoints;
	}
};
