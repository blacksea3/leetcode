#include "public.h"

//两遍遍历,一轮正的一轮反的, 32ms, 88.65%

class Solution {
public:
	int candy(vector<int>& ratings) {
		//全部初始化成1
		//先正向遍历,对当前评分大于前一个,给当前赋比前一个+1
		//后反序遍历,对当前评分大于后一个,如果当前值比后一个小或等于,那么修改当前值至比后一个+1,这不会影响第一轮遍历设置的(当前评分大于前一个,给当前赋比前一个+1,因为顶多变成当前赋值比前一个大的多)

		vector<int> candies(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++)
			if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;

		for (int i = ratings.size() - 2; i >= 0; i--)
			if (ratings[i] > ratings[i + 1])
				if (candies[i] <= candies[i + 1])
					candies[i] = candies[i + 1] + 1;

		int sum = 0;
		for (auto icandy : candies)
			sum += icandy;
		return sum;
	}
};