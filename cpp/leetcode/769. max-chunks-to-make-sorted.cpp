#include "public.h"

//8ms, 25.98%
//寻找每个数字: 左边比它小与等于的的, 而且最靠近它
//再寻找左边第一个比它大的, 而且最远离它, 若没有就是自己
//先单调栈

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		stack<pair<int, int>> st; //value:loc in arr
		vector<int> leftminloc(arr.size());
		vector<int> leftmaxloc(arr.size());
		int preloc = 0;

		while (preloc < arr.size())
		{
			while (!st.empty() && arr[preloc] < st.top().first)
			{
				st.pop();
			}
			if (st.empty()) leftminloc[preloc] = -1;
			else leftminloc[preloc] = st.top().second;
			st.push({ arr[preloc], preloc });
			preloc++;
		}

		for (int i = 0; i < arr.size(); ++i)
		{
			bool isfind = false;
			for (int j = 0; j < i; ++j)
			{
				if (arr[j] > arr[i])
				{
					leftmaxloc[i] = j;
					isfind = true;
					break;
				}
			}
			if (!isfind)
			{
				leftmaxloc[i] = i;
			}
		}

		//
		int res = 0;
		preloc = arr.size() - 1;
		int preleftminloc = 999;
		int preleftmaxloc = 999;
		while (preloc >= 0)
		{
			preleftminloc = min(preleftminloc, leftminloc[preloc]);
			preleftmaxloc = min(preleftmaxloc, leftmaxloc[preloc]);
			if (preleftminloc == preloc - 1 && preleftmaxloc == preloc) 
				res++;
			preloc--;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> arr = { 1, 4, 3, 6, 0, 7, 8, 2, 5 };
	cout << s->maxChunksToSorted(arr) << endl;
	vector<int> arr1 = { 1,0,2,3,4 };
	cout << s->maxChunksToSorted(arr1) << endl;
	vector<int> arr2 = { 2,0,1 };
	cout << s->maxChunksToSorted(arr2) << endl;
	return 0;
}
*/
