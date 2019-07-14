#include "public.h"

//28ms, 96.09%
//注意到seq是有效括号
//那么只需要把嵌套情况'平均'分配
//因此记录当前的左括号数量, 
//如果目前是左括号则数量加1, 之后若现在有奇数个左括号则给0, 偶数个左括号给1
//如果目前是右括号, 则抵消掉一个左括号, 若剩余奇数个左括号则给1, 偶数个则给0  (和上一行描述相反)

class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> res(seq.size());
		bool is_1 = true;
		for (int loc = 0; loc < seq.size(); ++loc)
		{
			if (seq[loc] == '(')
			{
				res[loc] = is_1;
				is_1 = !is_1;
				//if (is_1) res[loc] = 0;
				//else res[loc] = 1;
			}
			else
			{
				res[loc] = !is_1;
				is_1 = !is_1;
				//if (is_1) res[loc] = 1;
				//else res[loc] = 0;
			}
		}
		return res;
	}
};

