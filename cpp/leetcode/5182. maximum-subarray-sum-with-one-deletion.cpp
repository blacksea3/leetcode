#include "public.h"

//
//查看负数的位置, 决定是否删去
//考虑滑动窗口

class Solution {
private:
	int inner(vector<int>& arr)
	{
		int preSum = 0;
		int preIndex = 0;
		bool isNeglected = false; //是否决定已经忽略一个负数
		int neglectIndex = -1;    //忽略的负数索引
		int res = -1;
		int oldSum = 0;

		///int oldS

		while (preIndex < arr.size())
		{
			if (arr[preIndex] < 0)
			{
				if (!isNeglected)  //还没有删除过, 现在删除这个呆逼
				{
					neglectIndex = preIndex;
					isNeglected = true;
					oldSum = preSum;
				}
				else //已经删除过, 判断
				{
					if ((oldSum + arr[neglectIndex]) <= 0) //把前面的呆逼删掉, 连带更早的正数
					{
						preSum -= oldSum;
						neglectIndex = preIndex;
						oldSum = preSum;
					}
					else
					{
						if (arr[neglectIndex] >= arr[preIndex]) //删除现在的呆逼, 返回以前的呆逼
						{
							preSum += arr[neglectIndex];
							neglectIndex = preIndex;
							oldSum = preSum;
						}
						else  //吃掉现在的呆逼
						{
							preSum += arr[preIndex];
							oldSum = preSum;
						}
					}
				}
			}
			else
			{
				preSum += arr[preIndex];
			}
			res = max(res, preSum);
			preIndex++;
		}
		res = max(res, preSum);
		return res;
	}


public:
	int maximumSum(vector<int>& arr) {
		//特殊情况, 全是负的
		int maxEle = *max_element(arr.begin(), arr.end());
		if (maxEle < 0) return maxEle;
		else
		{
			int res1 = inner(arr);
			reverse(arr.begin(), arr.end());
			int res2 = inner(arr);
			return max(res1, res2);
		}

	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> arrFuck1 = { 8,-1,6,-7,-4,5,-4,7,-6 };
	cout << s->maximumSum(arrFuck1) << endl;

	vector<int> arrF = { 0,-5,-6,5,0,-5 };
	cout << s->maximumSum(arrF) << endl;

	vector<int> arr0 = { 1,-4,-5,-2,5,0,-1,2 };
	cout << s->maximumSum(arr0) << endl;
	vector<int> arr1 = { 2,1,-2,-5,-2 };
	cout << s->maximumSum(arr1) << endl;
	vector<int> arr2 = { 1,-2,0,3  };
	cout << s->maximumSum(arr2) << endl;
	vector<int> arr3 = { 1,-2,-2,3 };
	cout << s->maximumSum(arr3) << endl;
	return 0;
}
*/
