#include "public.h"

//8ms, 83.54%
//DP problem
//dp[i + 1]��ʾǰi�����ܸ߶� (i��0��ʼ), dp[0]��dump, ֵΪ0

//���ŵ�i+1����ʱ, �ȵ���һ�����, ��¼��ǰ�߶�,
// Ȼ����ͼ���i�������, ֻҪ��ȹ�����ߺ�����, ��¼��ǰ�߶Ȳ��Ƚ�
// Ȼ����i-1��..... ֱ���������

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
