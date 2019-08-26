#include "public.h"

//292ms, 6.12%
//�ҵ���һ�������½���λ��(����A[i] > A[i + 1])
//���û��, ��ô������
//�����, �ҳ������������б�A[i]�����С����, Ȼ�󽻻�����, �ٸ�i+1��ʼ��������������

class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& A) {
		bool isalldecrement_reverse = true;
		int targetloc = 0;
		for (int i = A.size() - 2; i >= 0; --i)
			if (A[i] > A[i + 1])
			{
				targetloc = i;
				isalldecrement_reverse = false;
				break;
			}

		if (isalldecrement_reverse) return A;
		else
		{
			//brute force
			bool isfind_loc = false;
			for (int j = targetloc + 2; j < A.size(); ++j)
				if (A[j] >= A[targetloc])
				{
					//swap: j-1 and targetloc
					int temp = A[targetloc];
					A[targetloc] = A[j - 1];
					A[j - 1] = temp;
					isfind_loc = true;
					break;
				}
			if (!isfind_loc)
			{
				//swap: last and targetloc
				int temp = A[targetloc];
				A[targetloc] = A[A.size() - 1];
				A[A.size() - 1] = temp;
			}
			return A;
		}
	}
};

