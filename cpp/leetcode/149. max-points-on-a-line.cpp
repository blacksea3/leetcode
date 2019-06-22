#include "public.h"

//32ms, 51.38%

class Solution {
private:
	//շת�����,��������������������С�����Լ��Ϊ1
	//��һ���������Ǹ���
	pair<int, int> iter_gcd(pair<int, int> input)
	{
		//�������,md
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
		//��ĳ��������,�����е�ɨһ�ν���Ψһ�Լ�¼:����б�ʼ�¼
		//��¼��ֵ����һ��pair<int a,int b>��ʾ a/b (a��������������,bֻ����������)
		//init:extra = 0
		//������������ظ��ĵ�,extra+=1(ע��,���ֵ�ض�>=1��Ϊ���е�����Ǹ�������)
		//Ȼ����ڴ�����б��,�ҵ�������ߵľͿ�����
		int psize = points.size();
		if (psize <= 2) return psize;
		map<pair<int, int>, int> slice_dict;
		int maxpoints = 0;

		//��ʽ����
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
			//ɨһ��slice_dict
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
