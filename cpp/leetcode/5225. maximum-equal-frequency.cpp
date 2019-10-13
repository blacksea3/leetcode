#include "public.h"

//
//unordered_map±©Á¦

class Solution {
public:
	int maxEqualFreq(vector<int>& nums) {
		int nSize = nums.size();
		int res;
		if (nSize >= 2) res = 2;
		else res = 1;

		unordered_map<int, int> count;
		unordered_map<int, unordered_set<int>> counttime_countcontent;

		for (int index = 0; index < nums.size(); ++index)
		{
			int num = nums[index];
			if (count.find(num) == count.end())
			{
				count[num] = 1;
				counttime_countcontent[1].insert(num);
			}
			else
			{
				counttime_countcontent[count[num]].erase(num);
				if (counttime_countcontent[count[num]].empty())
					counttime_countcontent.erase(count[num]);
				count[num]++;
				counttime_countcontent[count[num]].insert(num);
			}
			if (counttime_countcontent.size() == 1)
			{
				int size1;
				int len1;
				unordered_map<int, unordered_set<int>>::iterator iter = counttime_countcontent.begin();
				size1 = iter->second.size();
				len1 = iter->first;
				if (len1 == 1)
				{
					res = index + 1;
					goto end;
				}
				if (size1 == 1)
				{
					res = index + 1;
					goto end;
				}
			}

			if (counttime_countcontent.size() == 2)
			{
				int size1, size2;
				int len1, len2;
				unordered_map<int, unordered_set<int>>::iterator iter = counttime_countcontent.begin();
				size1 = iter->second.size();
				len1 = iter->first;
				iter++;
				size2 = iter->second.size();
				len2 = iter->first;

				if (len1 == (len2 + 1))
				{
					if (size1 == 1)
					{
						res = index + 1;
						goto end;
					}
				}
				if (len2 == (len1 + 1))
				{
					if (size2 == 1)
					{
						res = index + 1;
						goto end;
					}
				}
				if (len1 == 1)
				{
					if (size1 == 1)
					{
						res = index + 1;
						goto end;
					}
				}
				if (len2 == 1)
				{
					if (size2 == 1)
					{
						res = index + 1;
						goto end;
					}
				}
			}
		end:
			;
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums11 = { 1,1 };  //2
	cout << s->maxEqualFreq(nums11) << endl;

	vector<int> nums0 = { 1,2,3,4,5,6,7,8,9 };  //9
	cout << s->maxEqualFreq(nums0) << endl;

	vector<int> nums = { 2,2,1,1,5,3,3,5 };  //7
	cout << s->maxEqualFreq(nums) << endl;

	vector<int> nums2 = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 }; //13
	cout << s->maxEqualFreq(nums2) << endl;

	vector<int> nums3 = { 1,1,1,2,2,2 }; //5
	cout << s->maxEqualFreq(nums3) << endl;

	vector<int> nums4 = { 10,2,8,9,3,8,1,5,2,3,7,6 }; //8
	cout << s->maxEqualFreq(nums4) << endl;

	return 0;
}
*/
