#include "public.h"

//����+���ֲ���
//����ָ����midrow, midcol
//���С, ��ô����row:[startrow, midrow-1], column:[startcol, midcol]�Լ�
//  row:[midrow,midrow], column:[startcol, midcol-1]
//�����, ��ô����row:[midrow+1, endrow], column:[startcol, endcol]�Լ�
//  row:[startrow, midrow], column:[midcol+1, endcol]
//������,�������true,Ȼ��ݹ�ȫ���˳�

class Solution {
	
private:
	bool res = false;
	void search(vector<vector<int>>& matrix, int target, int startrow, int endrow,
		int startcol, int endcol)
	{
		if ((res) || (startrow > endrow) || (startcol > endcol)) return;
		int midrow = (startrow + endrow) / 2;
		int midcol = (startcol + endcol) / 2;
		if (matrix[midrow][midcol] < target)
		{
			search(matrix, target, midrow + 1, endrow, startcol, endcol);
			search(matrix, target, startrow, midrow, midcol + 1, endcol);
		}
		else if (matrix[midrow][midcol] > target)
		{
			search(matrix, target, startrow, midrow - 1, startcol, midcol);
			search(matrix, target, midrow, midrow, startcol, midcol - 1);
		}
		else
		{
			res = true;
		}
	}

public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> matrix = { {1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30} };
	//cout << s->searchMatrix(matrix, 5);
	vector<vector<int>> matrix = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
	cout << s->searchMatrix(matrix, 5);
	return 0;
}
