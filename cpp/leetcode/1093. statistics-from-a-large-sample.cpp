#include "public.h"

//8ms, 65.60%
//easy problem, but code is very hard

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		vector<double> res(5, 0.0);
		double rmin = INT_MAX;
		double rmax = INT_MIN;
		double sum = 0.0;
		double nums = 0.0;
		double famous = 0;
		int mostnums = 0;
		for (int i = 0; i <= 255; ++i)
		{
			if (count[i] > 0)
			{
				if (rmin == INT_MAX) rmin = i;
				rmax = max(rmax, (double)i);
				sum += i * count[i];
				nums += count[i];
				if (count[i] > mostnums)
				{
					mostnums = count[i];
					famous = i;
				}
			}
		}

		res[0] = rmin;
		res[1] = rmax;
		res[2] = sum / nums;
		res[4] = famous;

		double mediumnum = 0.0;
		int presum = 0;
		if ((int)nums % 2 == 1)  //ÆæÊý
		{
			for (int i = 0; i < 256; ++i)
			{
				if ((presum + count[i]) >= (nums / 2 + 1))
				{
					mediumnum = (double)i;
					break;
				}
				else
					presum += count[i];
			}
		}
		else
		{
			bool waitnext = false;
			double mediumsum2 = 0.0;
			for (int i = 0; i < 256; ++i)
			{
				if (!waitnext)
				{
					if ((presum + count[i]) > (nums / 2))
					{
						mediumnum = (double)i;
						break;
					}
					else if ((presum + count[i]) == (nums / 2))
					{
						waitnext = true;
						mediumsum2 = (double)i;
					}
					else
						presum += count[i];
				}
				else
				{
					if (count[i] > 0)
					{
						mediumsum2 += (double)i;
						break;
					}
				}
			}
			if (waitnext) mediumnum = mediumsum2 / 2;
		}
		res[3] = mediumnum;

		return res;

	}
};
