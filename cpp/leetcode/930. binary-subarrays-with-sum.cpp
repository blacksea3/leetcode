#include "public.h"

//32ms, 83.61%
//用queue记录每个1之前的0的数量
//当记录大量的0之后, 下一个是1时/到末尾时, 将此0的数量放入队列, 如果在放之前队列size==S, 那么res += 队列首*当前0数量, 然后队列pop(), 再push当前0数量
//S=0单独考虑

class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		if (S > 0)
		{
			queue<int> q;
			int loc = 0;
			int prezeros = 0;
			int res = 0;
			while (true)
			{
				if (loc == A.size())
				{
					if (q.size() == S)
					{
						res += (q.front() + 1)*(prezeros + 1);
					}
					return res;
				}
				else if (A[loc] == 0) prezeros++;
				else
				{
					if (q.size() == S)
					{
						res += (q.front() + 1)*(prezeros + 1);
						q.pop();
						q.push(prezeros);
					}
					else
					{
						q.push(prezeros);
					}
					prezeros = 0;
				}
				loc++;
			}
			return -999;
		}
		else  //单独操作, 数0的个数就可以
		{
			vector<int> v;
			int prezeros = 0;
			int res = 0;
			for (int i = 0; i < A.size(); ++i)
			{
				if (A[i] == 1)
				{
					res += (prezeros + 1)*prezeros / 2;
					prezeros = 0;
				}
				else prezeros++;
			}
			res += (prezeros + 1)*prezeros / 2;
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 0,0,0,0,1 };
	cout << s->numSubarraysWithSum(A, 2);
	return 0;
}
*/
