#include "public.h"

//264ms, 47.95%
//暴力,
//计算两个人的糖果总量, 得出应该交换的糖果大小差, 然后遍历爱丽丝的糖果棒, 查找鲍勃有没有

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int asum = accumulate(A.begin(), A.end(), 0);
		int bsum = accumulate(B.begin(), B.end(), 0);

		int abs = asum - bsum;  //for a in A, B 应该找出一个 a - abs/2的糖果
		int should = -1 * abs / 2;

		set<int> as;
		set<int> bs;
		for (auto& a : A) as.insert(a);
		for (auto& b : B) bs.insert(b);

		for (auto& ias : as)
		{
			if (bs.find(ias + should) != bs.end()) return { ias, ias + should };
		}
		return { -999,-999 }; //dump
	}
};
