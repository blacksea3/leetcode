#include "public.h"

//
//暴力
//位运算, arr求异或

class Solution {
public:
	int maxLength(vector<string>& arr) {
		int totalSize = (int)pow(2, arr.size());
		int res = 0;

		//去重
		for (auto& iterarr : arr)
		{
			unordered_set<char> us;
			bool Bad = false;
			for (auto& itera : iterarr)
			{
				if (us.find(itera) == us.end()) us.insert(itera);
				else
				{
					Bad = true;
				}
			}
			if (Bad) iterarr = "";
		}

		//转二进制
		vector<int> bits(arr.size());
		for (int i = 0; i < arr.size(); ++i)
		{
			for (auto& itera : arr[i]) bits[i] |= (int)pow(2, itera - 'a');
		}

		//查找
		for (int i = 0; i < totalSize; ++i)
		{
			int preAll = 0;

			int prePaiXu = i;
			int b = 1;
			int loc = 0;

			bool isGood = true;
			int tempi = i;
			while (tempi > 0)
			{
				if (tempi & b)
				{
					if ((preAll & bits[loc]) == 0)
					{
						preAll |= bits[loc];
					}
					else
					{
						isGood = false;
						break;
					}
					tempi -= b;
				}
				loc++;
				b <<= 1;
			}

			if (isGood) //计算1的个数
			{
				int preOne = 0;
				while (preAll > 0)
				{
					preAll -= (preAll&(-preAll));
					preOne++;
				}
				res = max(res, preOne);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> arr = { "un","iq","ue" };
	cout << s->maxLength(arr) << endl;
	vector<string> arr2 = { "cha","r","act","ers" };
	cout << s->maxLength(arr2) << endl;
	vector<string> arr3 = { "abcdefghijklmnopqrstuvwxyz" };
	cout << s->maxLength(arr3) << endl;
	return 0;
}
*/