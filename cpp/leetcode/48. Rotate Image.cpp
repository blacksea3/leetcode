#include "public.h"

//8ms, 95.37%

//From outside circle to the inside circle, use two level iteration
// at one time, operate on four points

//note: this is a n*n matrix

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int sidelength = matrix.size();

		for (int i = 0; i < sidelength / 2; i++)
		{
			for (int j = 0; j < (sidelength - 2 * i - 1); j++)
			{
				int lefty_downx = sidelength - 1 - i - j;
				int downy_rightx = sidelength - 1 - i;
				int righty_topx = i + j;
				//i: topy/leftx
				int temp = matrix[i][righty_topx];

				matrix[i][righty_topx] = matrix[lefty_downx][i];
				matrix[lefty_downx][i] = matrix[downy_rightx][lefty_downx];
				matrix[downy_rightx][lefty_downx] = matrix[righty_topx][downy_rightx];
				matrix[righty_topx][downy_rightx] = temp;
			}
		}
	}
};