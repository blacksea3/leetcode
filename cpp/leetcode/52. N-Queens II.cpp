#include "public.h"

//4ms, 93.27%
//����ͬǰ, �������ڲ����ַ����洢, �����ö�����λ�洢����ռ�����

class Solution {
private:
	int res = 0;
	int fullcolumns; //������n��1

	//p_diagolal:���Խ���ռ�����, ������1Ϊռ��, ������0Ϊռ��, б��+45��
	//n_diagonal:�ζԽ���ռ�����, б��-45��
	//cols:��ռ�����
	void DFS(int r, int p_diagonal, int n_diagonal, int cols, int n)
	{
		if (r == n) res++;
		//������1Ϊ������, 0Ϊ������, �˺ʹ������01�����෴
		int emptyCols = fullcolumns & ~(p_diagonal | n_diagonal | cols);

		while (emptyCols > 0)
		{
			int preCol = emptyCols & (-emptyCols); //ȡ���������һ��1λ
			emptyCols ^= preCol;                   //ɾ��������õ�1λ
			DFS(r + 1, (p_diagonal | preCol) << 1, (n_diagonal | preCol) >> 1, cols | preCol, n);
		}
	}

public:
	int totalNQueens(int n)
	{
		DFS(0, 0, 0, 0, n);
		fullcolumns = (1 << n) - 1;
		return res;
	}
};
