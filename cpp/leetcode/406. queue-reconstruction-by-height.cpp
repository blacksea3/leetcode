#include "public.h"

//196ms, 26.36%
//贪心算法, 按从小到大的顺序放

class Solution {
private:
	//排序: 主序对高度升序, 次序对人数降序
	/*std::sort可能在比较的过程中对同一对数据进行多次比较，必须保证同一对数据多次比较结果是一致的。例如：

当lhs为ItemDesc{ 0, "hello" },而rhs为ItemDesc{ 0, "hellx" },返回true，第二次比较并且顺序交换后，即ItemDesc{ 0, "hellx" },而rhs为ItemDesc{ 0, "hello" },它应该返回false。

若无法保证这一点。则会c++ std::sort函数调用经常出现的invalidate operator<错误原因以及解决方法*/
	static bool msort(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.first < p2.first) return true;
		else if (p1.first > p2.first) return false;
		else return p1.second > p2.second;
	}

public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int psize = people.size();

		vector<pair<int, int>> cpy;
		for (auto& p : people)
		{
			cpy.push_back(pair<int, int>{p[0], p[1]});
		}

		sort(cpy.begin(), cpy.end(), msort);
		vector<vector<int>> res(psize);

		for (auto& p : cpy)
		{
			int count = p.second;
			for (int loc = 0; loc < psize; ++loc)
			{
				if (res[loc].empty())
				{
					if (count == 0)
					{
						res[loc] = { p.first, p.second };
						break;
					}
					else count--;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> people = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	auto res = s->reconstructQueue(people);
	return 0;
}
