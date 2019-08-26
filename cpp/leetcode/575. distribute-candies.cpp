#include "public.h"

//312ms, 83.48%
//统计数字种类数, 如果种类数>=总糖果数/2 那么就是总糖果数/2, 否则是种类数

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> us_candies(candies.begin(), candies.end());

		return (us_candies.size() >= candies.size() / 2) ? candies.size() / 2 : us_candies.size();
	}
};
