#include "public.h"

//312ms, 83.48%
//ͳ������������, ���������>=���ǹ���/2 ��ô�������ǹ���/2, ������������

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> us_candies(candies.begin(), candies.end());

		return (us_candies.size() >= candies.size() / 2) ? candies.size() / 2 : us_candies.size();
	}
};
