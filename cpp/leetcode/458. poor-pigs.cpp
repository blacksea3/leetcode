#include "public.h"

//0ms, 100%
//��minutesToTest>=minutesToDie, ��һֻС������ж�(minutesToTest/minutesToDie)+1Ͱˮ
//���� ת�������С��x���� ((minutesToTest/minutesToDie)+1)^x>=buckets
// x = ceil(log(buckets)/log((minutesToTest/minutesToDie)+1))

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		return (minutesToTest >= minutesToDie) ? ceil(log(buckets) / log((minutesToTest / minutesToDie) + 1)) : 0;
	}
};
