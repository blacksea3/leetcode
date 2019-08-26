#include "public.h"

/*40ms, 37.50%
//第一思路
//建立一个absval = A得值 - 对应索引, 然后复制一份, 排序处理
//首先大家与0比找到第一个>0得数, 那么比它小的数字个数就是当前得分
//接下来对最后一个数+A.size(), 更改排序vector, 然后与1比...
//O(nlogn) TLE

//因此优化: 用vector统计各种absval出现个数, 初始化K=0得答案, 然后每次调整vector内计算的值(一次调整一个), 并同时减去不再<=当前-1*K的数字个数
//此为O(n)
*/

class Solution {
public:
	int bestRotation(vector<int>& A) {
		int as = A.size();
		vector<int> cpAabs(as);

		for (int i = 0; i < as; ++i)
		{
			cpAabs[i] = A[i] - i;
		}

		vector<int> absval(3 * as);  //范围-2*as - as, 大小: 3*as, 下标等于真实值+2*as

		for (int i = 0; i < as; ++i)
		{
			absval[A[i] - i + 2 * as]++;
		}

		//初始化第一个res, <=0得个数
		int maxres;
		int preres = 0;
		int resK = 0;
		for (int i = 0; i <= 2 * as; ++i)
		{
			preres += absval[i];
		}
		maxres = preres;

		//循环操作起来
		int preK = 0;
		while (preK < as - 1)
		{
			//操作倒数第(preK+1)个数, 加上A.size(), 然后调整absval, 与预计res
			if (cpAabs[preK] > -1 * (preK)) preres++;//减掉as之后查看原来的是否符合, 是则res首先加一
			absval[cpAabs[preK] + 2 * as]--;
			absval[cpAabs[preK] - as + 2 * as]++;
			preK++; //preK加一, 修改需要比较的数字
			//然后所有-1*(preK-1)值现在不满足了, 现在都应该<=-1*preK才行
			preres -= absval[-1 * (preK - 1) + 2 * as];
			//更新结果
			if (preres > maxres)
			{
				maxres = preres;
				resK = preK;
			}
		}
		return resK;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 2,3,1,4,0 };
	//cout << s->bestRotation(A);
	vector<int> A = { 0,3,1,3,1 };
	cout << s->bestRotation(A);
	return 0;
}