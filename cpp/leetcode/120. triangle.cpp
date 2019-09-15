#include "public.h"

//4ms, 97.47%
//DP����, ����, �������ϰ���ɨ��

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//һ��һ��ɨ����,ɨ��ʱ��Ͱѵ�ǰ��С·�������!
		//����,��������ɨ

		int nline = triangle.size();
		if (nline == 0) return 0;
		else
		{
			for (int i = nline - 2; i >= 0; --i)   //i��ʾ��i+1��
			{
				for (int j = 0; j < i + 1; ++j)  //������i+1�е��±�Ϊj��Ԫ��
					triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];  //��Сֵ���Ƕ�Ԫ��
	}
};
