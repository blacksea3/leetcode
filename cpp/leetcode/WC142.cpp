#include "public.h"

class MountainArray {
public:
	vector<int> s;
	MountainArray(vector<int> para)
	{
		s = para;
	}

	int get(int index)
	{
		return s[index];
	}
	int length()
	{
		return s.size();
	}
	


};

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		double min = -1.0;
		double max = 257.0;
		for (int i = 0; i < 256; ++i)
		{
			if ((min == -1.0) && (count[i] > 0)) min = (double)i;
		}
		for (int i = 255; i >= 0; --i)
		{
			if ((max == 257.0) && (count[i] > 0)) max = (double)i;
		}

		vector<double> res(5, 0.0);
		res[0] = min;
		res[1] = max;
		double sum = 0.0;
		for (int i = 0; i < 256; ++i)
		{
			sum += (double)i*(double)count[i];
		}
		int nozero = 0;
		for (auto c : count)
			if (c != 0) nozero += c;

		res[2] = sum / (double)nozero;

		int totalsum = 0;
		for (auto c : count)
			totalsum += c;

		double mediumnum = 0.0;
		int presum = 0;
		if (totalsum % 2 == 1)  //ÆæÊı
		{
			for (int i = 0; i < 256; ++i)
			{
				if ((presum + count[i]) >= (totalsum / 2 + 1))
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
					if ((presum + count[i]) > (totalsum / 2))
					{
						mediumnum = (double)i;
						break;
					}
					else if ((presum + count[i]) == (totalsum / 2))
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

		double BIGnum = 0.0;
		int BIG_len = 0;
		for (int i = 0; i < 256; ++i)
		{
			if (count[i] != 0)
			{
				if (count[i] > BIG_len)
				{
					BIG_len = count[i];
					BIGnum = (double)i;
				}
			}

		}
		res[4] = BIGnum;

		return res;

	}


private:
	static bool cmp_startpre(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[1] < v2[1];
	}

	static bool cmp_endpre(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[2] < v2[2];
	}

public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		//sim

		vector<vector<int>> startpre(trips);
		vector<vector<int>> endpre(trips);

		sort(startpre.begin(), startpre.end(), cmp_startpre);
		sort(endpre.begin(), endpre.end(), cmp_endpre);

		int startloc = startpre[0][1];
		int endloc = endpre[endpre.size() - 1][2];

		int startsub = 0;
		int endsub = 0;
		int humannum = 0;

		for (int i = startloc; i <= endloc; ++i)
		{
			while ((endsub < endpre.size()) && (endpre[endsub][2]) == i)
			{
				humannum -= endpre[endsub][0];
				endsub++;
			}
			while ((startsub < startpre.size()) && (startpre[startsub][1]) == i)
			{
				humannum += startpre[startsub][0];
				if (humannum > capacity) return false;
				startsub++;
			}
		}
		return true;
	}


private:
	// [start,end], end >= start
	int binarysearch(int target, MountainArray &mountainArr, int start, int end, bool upmode)
	{
		if (end < start) return -1;
		else
		{
			if (!upmode)
			{
				int mid = (end + start) / 2;
				int midres = mountainArr.get(mid);
				if (midres == target) return mid;
				else if (midres < target)
				{
					return binarysearch(target, mountainArr, start, mid - 1, true);
				}
				else
				{
					return binarysearch(target, mountainArr, mid + 1, end, true);
				}
			}
			else
			{
				int mid = (end + start) / 2;
				int midres = mountainArr.get(mid);
				if (midres == target) return mid;
				else if (midres > target)
				{
					return binarysearch(target, mountainArr, start, mid - 1, true);
				}
				else
				{
					return binarysearch(target, mountainArr, mid + 1, end, true);
				}
			}
		}
	}

	// [start,end]
	int recu_findInMountainArray(int target, MountainArray &mountainArr, int start, int end) {

		if ((end - start) == 0)
		{
			if (mountainArr.get(end) == target) return start;
			return -1;
		}
		else if ((end - start) == 1)
		{
			if (mountainArr.get(end) == target) return end;
			if (mountainArr.get(start) == target) return start;
			return -1;
		}
		else if ((end - start) == 2)
		{
			if (mountainArr.get(end) == target) return end;
			if (mountainArr.get(start) == target) return start;
			if (mountainArr.get(start + 1) == target) return start + 1;
			return -1;
		}
		else
		{
			int mid = (end + start) / 2;
			int left = mountainArr.get(mid);
			int right = mountainArr.get(mid + 1);
			int resloc = -1;
			int resloc2 = -1;


			if (left == target)
			{
				resloc = mid;
			}

			if (right == target)
			{
				resloc = mid + 1;
			}

			if (left < right)
			{
				if (target < left)
				{
					int leftres = binarysearch(target, mountainArr, start, mid - 1, true);
					if (leftres >= 0) resloc2 = leftres;
				}
				int rightres = recu_findInMountainArray(target, mountainArr, mid + 2, end);
				if (rightres >= 0)
				{
					if (resloc2 == -1) resloc2 = rightres;
				}
			}
			else
			{
				int leftres = recu_findInMountainArray(target, mountainArr, start, mid - 1);
				if (leftres >= 0) resloc2 = leftres;
				if (target < right)
				{
					int rightres = binarysearch(target, mountainArr, mid + 2, end, false);
					if (rightres >= 0)
					{
						if (resloc2 == -1) resloc2 = rightres;
					}
				}
			}
			if ((resloc == -1) && (resloc2 == -1))
				return -1;

			if (resloc == -1)
			{
				resloc = 100000;
			}
			if (resloc2 == -1)
			{
				resloc2 = 100000;
			}

			return min(resloc, resloc2);
		}

	}

public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int n = mountainArr.length();

		//binary search, BIG
		return recu_findInMountainArray(target, mountainArr, 0, n - 1);
	}

};

int main()
{
	Solution* s = new Solution();
	//vector<int> count = {264, 912, 1416, 1903, 2515, 3080, 3598, 4099, 4757, 5270, 5748, 6451, 7074, 7367, 7847, 8653, 9318, 9601, 10481, 10787, 11563, 11869, 12278, 12939, 13737, 13909, 14621, 15264, 15833, 16562, 17135, 17491, 17982, 18731, 19127, 19579, 20524, 20941, 21347, 21800, 22342, 21567, 21063, 20683, 20204, 19818, 19351, 18971, 18496, 17974, 17677, 17034, 16701, 16223, 15671, 15167, 14718, 14552, 14061, 13448, 13199, 12539, 12265, 11912, 10931, 10947, 10516, 10177, 9582, 9102, 8699, 8091, 7864, 7330, 6915, 6492, 6013, 5513, 5140, 4701, 4111, 3725, 3321, 2947, 2357, 1988, 1535, 1124, 664, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//vector<double> res = s->sampleStats(count);

	//vector<vector<int>> trips = { {2,1,5 }, { 3,3,7 }};
	//cout <<	s->carPooling(trips, 4);
	
	//vector<int> v = {1, 4, 6, 8, 10, 3, 1};
	//MountainArray m = MountainArray(v);
	//cout << s->findInMountainArray(8, m);

	vector<int> v2 = { 1, 2, 3, 4, 5, 3, 1 };
	MountainArray m = MountainArray(v2);
	cout << s->findInMountainArray(1, m);

	vector<int> v3 = { 0,5,3,1 };
	MountainArray m = MountainArray(v3);
	cout << s->findInMountainArray(1, m);
	//vector<int> v2 = { 3,5,3,2, 0 };
	MountainArray m = MountainArray(v2);
	cout << s->findInMountainArray(1, m);
	return 0;
}

