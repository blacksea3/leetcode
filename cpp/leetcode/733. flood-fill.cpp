#include "public.h"

//64ms, 11.95%
//DFS

class Solution {
private:
	void DFS(vector<vector<int>>& image,
		vector<vector<bool>>& searched,
		int r, int c, int newColor)
	{
		searched[r][c] = true;
		int currentColor = image[r][c];
		if (r > 0 && !searched[r - 1][c] && currentColor == image[r - 1][c])
			DFS(image, searched, r - 1, c, newColor);
		if (c > 0 && !searched[r][c - 1] && currentColor == image[r][c - 1])
			DFS(image, searched, r, c - 1, newColor);
		if (r < image.size() - 1 && !searched[r + 1][c] && currentColor == image[r + 1][c])
			DFS(image, searched, r + 1, c, newColor);
		if (c < image[0].size() - 1 && !searched[r][c + 1] && currentColor == image[r][c + 1])
			DFS(image, searched, r, c + 1, newColor);
		image[r][c] = newColor;
	}

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<bool>> searched(image.size(), vector<bool>(image[0].size(), false));
		DFS(image, searched, sr, sc, newColor);
	}
};
