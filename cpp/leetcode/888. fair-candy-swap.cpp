#include "public.h"

//264ms, 47.95%
//����,
//���������˵��ǹ�����, �ó�Ӧ�ý������ǹ���С��, Ȼ���������˿���ǹ���, ���ұ�����û��

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int asum = accumulate(A.begin(), A.end(), 0);
		int bsum = accumulate(B.begin(), B.end(), 0);

		int abs = asum - bsum;  //for a in A, B Ӧ���ҳ�һ�� a - abs/2���ǹ�
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
