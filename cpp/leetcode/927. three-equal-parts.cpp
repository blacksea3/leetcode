#include "public.h"

//76ms, 38.30%
//按照1的数量划分
//如果不是3的整数倍那么返回false, 否则看最后一个1后面的零决定前面的1后面的0个数, 必须要有这么多0, 而且各个1的相对位置一样, 则返回true, 否则也是false

class Solution {
public:
	vector<int> threeEqualParts(vector<int>& A) {
		int countone = 0;

		for (auto& a : A) if (a == 1) countone++;

		if (countone % 3) return {-1, -1};
		if (countone == 0) return { 0, 2 };   //全是0的情况

		vector<int> first;
		vector<int> second;
		vector<int> third;

		int preloc = 0;
		int how_many_zeros_before_first_block = 0;
		int how_many_zeros_after_first_block = 0;
		int how_many_zeros_after_second_block = 0;
		int precountone = 0;
		while (A[preloc] == 0)
		{
			how_many_zeros_before_first_block++;
			preloc++;
		}
		while (precountone < countone / 3)
		{
			if (A[preloc] == 1) precountone++;
			first.push_back(A[preloc]);
			preloc++;
		}
		while (A[preloc] == 0)
		{
			preloc++;
			how_many_zeros_after_first_block++;
		}

		while (precountone < countone / 3 * 2)
		{
			if (A[preloc] == 1) precountone++;
			second.push_back(A[preloc]);
			preloc++;
		}
		while (A[preloc] == 0)
		{
			preloc++;
			how_many_zeros_after_second_block++;
		}

		while (precountone < countone)
		{
			if (A[preloc] == 1) precountone++;
			third.push_back(A[preloc]);
			preloc++;
		}
		int how_many_zeros_after_third_block = A.size() - preloc;

		if (first == second && first == third && 
			how_many_zeros_after_first_block >= how_many_zeros_after_third_block && 
			how_many_zeros_after_second_block >= how_many_zeros_after_third_block)
		{
			return { (int)first.size() + how_many_zeros_before_first_block + how_many_zeros_after_third_block - 1,
			   ((int)first.size()*2) + how_many_zeros_before_first_block + 
				    how_many_zeros_after_first_block + how_many_zeros_after_third_block};
		}
		else return { -1, -1 };
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,0,1,0,1 };
	auto res = s->threeEqualParts(A);
	return 0;
}
*/
