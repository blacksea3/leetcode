//
#include "public.h"

//�����Ͻǿ�ʼ, ѡ��ɾ���л�����

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int r = 0;
		if (array.size() == 0) return false;
		int c = array[0].size();
		if (c == 0) return false;
		c--;

		while (r >= 0 && c >= 0)
		{
			if (array[r][c] == target) return true;
			else if (array[r][c] > target) c--;
			else r++;
		}
		return false;
	}
};