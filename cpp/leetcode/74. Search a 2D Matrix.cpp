#include "public.h"

/*
//12ms, 78.15%
//˫���ֲ���

class Solution {
private:
	static bool line_search(const vector<int> &a, const int &tar) {
		return a[0] <= tar;
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;

		//�в���, �Ȳ��ҵ�һ��������line_search��, ����һ��line_search����false�ĵط�
		//Ȼ��λ��Ŀ����(�������������-1)
		int rowIndex = lower_bound(matrix.begin(), matrix.end(), target, line_search) - matrix.begin() - 1;
		if (rowIndex == -1) return false;
		else
		{
			//�в���
			return binary_search(matrix[rowIndex].begin(), matrix[rowIndex].end(), target);
		}
	}
};
*/

//8ms, 96.15%
//�����ֲ���
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;

		int rows = matrix.size();
		int cols = matrix[0].size();
		int l = 0;
		int r = rows * cols - 1;

		while (l < r) {
			int mid = (l + r) / 2;
			if (matrix[mid / cols][mid%cols] >= target) r = mid;
			else l = mid + 1;
		}

		return matrix[r / cols][r%cols] == target;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> m = { {},{}, {} };
	cout << s->searchMatrix(m,3);
	return 0;
}
*/
