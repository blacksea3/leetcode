#include "public.h"

//20ms, 81.62%
//摩尔投票法
//注意:首先最多只有两个数量超过1/3的数
//其次:每次选两个侯选数,一旦出现其他数,就和他们合并(侯选数数量减一)
//如果侯选数数量是0,以下一个数作为侯选数
//那么假如存在数量超过1/3的数,它必然在每一轮的合并状态中抵消掉,并且还存在!
//则众数一定留在最后,属于侯选数
//最后再判断一次侯选数是否确实是众数

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int p;
		int q;  //p/q侯选数
		int pnums = 0;
		int qnums = 0;

		//第一轮
		for (auto& n : nums)
		{
			if ((!pnums) && (!qnums))
			{
				p = n;
				pnums++;
			}
			else if (!pnums)
			{
				if (n != q)
				{
					p = n;
					pnums++;
				}
				else
					qnums++;
			}
			else if (!qnums)
			{
				if (n != p)
				{
					q = n;
					qnums++;
				}
				else
					pnums++;
			}
			else if (n == q) qnums++;
			else if (n == p) pnums++;
			else
			{
				qnums--;
				pnums--;
			}
		}

		//第二轮
		pnums = 0;
		qnums = 0;
		for (auto& n : nums)
		{
			if (n == p) pnums++;
			else if (n == q) qnums++;
		}
		vector<int> res;
		if (pnums > nums.size() / 3) res.push_back(p);
		if (qnums > nums.size() / 3) res.push_back(q);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 3,0,3,4 };
	vector<int> res = s->majorityElement(nums);
	return 0;
}
