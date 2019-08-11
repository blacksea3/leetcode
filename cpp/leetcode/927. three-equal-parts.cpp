#include "public.h"

//76ms, 38.30%
//����1����������
//�������3����������ô����false, �������һ��1����������ǰ���1�����0����, ����Ҫ����ô��0, ���Ҹ���1�����λ��һ��, �򷵻�true, ����Ҳ��false

class Solution {
public:
	vector<int> threeEqualParts(vector<int>& A) {
		int countone = 0;

		for (auto& a : A) if (a == 1) countone++;

		if (countone % 3) return {-1, -1};
		if (countone == 0) return { 0, 2 };   //ȫ��0�����

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
