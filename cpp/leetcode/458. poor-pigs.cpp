#include "public.h"

//0ms, 100%
//若minutesToTest>=minutesToDie, 则一只小猪可以判断(minutesToTest/minutesToDie)+1桶水
//问题 转变成求最小的x满足 ((minutesToTest/minutesToDie)+1)^x>=buckets
// x = ceil(log(buckets)/log((minutesToTest/minutesToDie)+1))

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		return (minutesToTest >= minutesToDie) ? ceil(log(buckets) / log((minutesToTest / minutesToDie) + 1)) : 0;
	}
};
