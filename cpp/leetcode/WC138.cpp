#include "public.h"

class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		//silder window

		//sum all satisfied customer (if X == 0)

		int res = 0;
		for (int i = 0; i < customers.size(); i++)
			if (grumpy[i] == 0) res += customers[i];

		//init silder window
		int startloc = 0;
		int maxaddcus = 0;
		int preaddcus = 0;
		int endloc = startloc + X - 1;

		for (int i = 0; i <= endloc; i++)
			if (grumpy[i] == 1) preaddcus += customers[i];
		maxaddcus = preaddcus;

		//main silder window
		while (endloc < customers.size() - 1)
		{
			int abscus = 0;
			if (grumpy[startloc] == 1) abscus -= customers[startloc];
			if (grumpy[endloc + 1] == 1) abscus += customers[endloc + 1];
			preaddcus += abscus;
			maxaddcus = max(maxaddcus, preaddcus);
			startloc++;
			endloc++;
		}

		return res + maxaddcus;
	}

	vector<int> prevPermOpt1(vector<int>& A) {
		//from back to front, find the first not decremently item.

		bool isalldecrement_reverse = true;
		int targetloc = 0;
		for (int i = A.size() - 2; i >= 0; --i)
			if (A[i] > A[i + 1])
			{
				targetloc = i;
				isalldecrement_reverse = false;
				break;
			}

		if (isalldecrement_reverse) return A;
		else
		{
			//brute force
			bool isfind_loc = false;
			for (int j = targetloc + 2; j < A.size(); ++j)
				if (A[j] >= A[targetloc])
				{
					//swap: j-1 and targetloc
					int temp = A[targetloc];
					A[targetloc] = A[j - 1];
					A[j - 1] = temp;
					isfind_loc = true;
					break;
				}
			if (!isfind_loc)
			{
				//swap: last and targetloc
				int temp = A[targetloc];
				A[targetloc] = A[A.size() - 1];
				A[A.size() - 1] = temp;
			}
			return A;
		}
	}

	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		//FUCK input
		if (barcodes.size() <= 2) return barcodes;
		
		//caculate
		unordered_map<int, int> um = {};
		for (auto barcode : barcodes)
			um[barcode]++;

		map<int, vector<int>, std::greater<int>> nums = {};  //key:times, value:value

		unordered_map<int, vector<int>>::iterator it;
		for (unordered_map<int, int>::iterator iter = um.begin(); iter != um.end(); iter++)
			if (nums.find(iter->second) != nums.end())
			{
				nums[iter->second].push_back(iter->first);
			}
			else nums[iter->second].push_back(iter->first);

		vector<int> res = {};

		while (nums.size() >= 1)
		{
			map<int, vector<int>>::iterator its = nums.begin();
			int count1 = its->first;
			int num1 = its->second[0];
			if (its->second.size() > 1)
				nums[count1].erase(nums[count1].begin());
			else
			{
				nums.erase(its);
			}
			
			if (nums.size() == 0)
			{
				int abs = 0;
				if (res[0] == num1)
					abs++;

				//≤Â»Î
				for (int i = 0; i < count1; ++i)
				{
					while ( ((abs>0) && (res[abs + 2 * i - 1] == num1)) || (res[abs + 2 * i] == num1))
					{
						abs++;
						if (abs == res.size()) break;
					}
					res.insert(res.begin() + abs + i * 2, num1);
				}
					
				break;



			}

			its = nums.begin();
			int count2 = its->first;
			int num2 = its->second[0];
			if (its->second.size() > 1)
				nums[count2].erase(nums[count2].begin());
			else
			{
				nums.erase(its);
			}

			for (int i = 0; i < count2; i++)
			{
				res.push_back(num1);
				res.push_back(num2);
			}
			if (count1 > count2)
			{
				nums[count1 - count2].push_back(num1);
			}
		}
		return res;
	}

};


int main()
{
	vector<int> customers = { 1,0,1,2,1,1,7,5 };
	vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
	Solution* s = new Solution();
	//cout << s->maxSatisfied(customers, grumpy, 3);
	vector<int> A = { 27,11,36,57,87 };
	//vector<int> res = s->prevPermOpt1(A);

	vector<int> barcodes = { 7,7,7,7,8,8,8,8,2,2 };
	//barcodes = { 1,1,2 };
	//barcodes = { 51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51,51,51,51,40,51,83,51,83,51,51,40,51,40,51,40,51,40,40,51,51,51,40,51,83,51,51,51,40,51,51,40,40 };
	barcodes = { 1 };
	vector<int> res = s->rearrangeBarcodes(barcodes);
	return 0;
}

