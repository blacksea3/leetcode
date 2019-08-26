#include "public.h"

//8ms, 83.54%
//DP problem
//dp[i + 1]表示前i书的书架高度 (i从0开始), dp[0]是dump, 值为0

//当放第i+1本书时, 先单独一层放他, 记录当前高度,
// 然后试图抽第i本书过来, 只要宽度够则二者合起来, 记录当前高度并比较
// 然后抽第i-1本..... 直至宽度满了

//may be O(n^2)

class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		vector<int> dp(books.size() + 1, 0);
		for (int i = 0; i < books.size(); ++i)
		{
			int preheight = books[i][1] + dp[i];
			int currentheight = books[i][1];
			int curwidth = books[i][0];

			for (int j = i - 1; j >= 0; --j)
			{
				curwidth += books[j][0];
				currentheight = max(currentheight, books[j][1]);
				if (curwidth <= shelf_width)
					preheight = min(preheight, currentheight + dp[j]);
				else break;
			}

			dp[i + 1] = preheight;
		}
		return dp[books.size()];
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> books = { {1, 1},{2, 3},{2, 3},{1, 1},{1, 1},{1, 1},{1, 2} };
	auto res = s->minHeightShelves(books, 4);
	return 0;
}
