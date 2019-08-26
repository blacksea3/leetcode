#include "public.h"

//特别备注: 此方案需要改进, 一旦遇到较大的total规模, 且flip次数接近total, 那么用时将极速增长
//应当替换成题解中的黑白方案法
//56ms, 23.88%
//拒绝采样, 将所有行列转成一个数字, 从此数字中随机数
//如果此行/列是1, 那么重新随机
//

class Solution {
private:
	unordered_set<int> fliped;
	int total;
	int cols;

public:
	Solution(int n_rows, int n_cols) {
		total = n_rows * n_cols;
		cols = n_cols;
	}

	vector<int> flip() {
		//千万不要在矩阵中没有值为 0 时, 调用 flip 函数
		while (1)
		{
			int pre = rand() % total;
			if (fliped.count(pre) > 0)
			{
				continue;
			}
			else
			{
				fliped.insert(pre);
				return { pre / cols, pre%cols };
			}
		}
		return { -999,-999 }; //dump
	}

	void reset() {
		unordered_set<int> empty;
		fliped = empty;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
