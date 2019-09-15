#include "public.h"

//
//特殊情况1: 全是负的, 结果为0
//特殊情况2: arr的和>0, 结果为k*arr mod MOD
//然后: arr的和<=0, 只能在一个arr中选取, 环状arr, 此处的arr需要扩展
//如果k是1, 单独arr, k是2, 允许一个环状, k是3, arr扩展成两倍, 然后允许一个环状

class Solution {
private:
	//最大环形子数组和
	int maxCircleSonArr(vector<int>& arr, int k)
	{
		if (k > 2)
		{
			//arr扩展
			arr.resize(arr.size() * 2);
			arr.insert(arr.begin() + arr.size(), arr.begin(), arr.end());
		}
		int Sum = 0;
		int temp = 0;
		int CurSum = 0;
		int MaxSum = 0;
		int MinSum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			//第二种情况，求得最大值为Sum-MinSum
			Sum += arr[i];
			if (temp > 0)
			{
				temp = arr[i];
			}
			else
			{
				temp = temp + arr[i];
			}
			if (temp < MinSum)
			{
				MinSum = temp;
			}
			//第一种情况，求得最大值为CurSum
			CurSum += arr[i];
			if (CurSum > MaxSum)
			{
				MaxSum = CurSum;
			}
			if (CurSum < 0)
			{
				CurSum = 0;
			}
		}
		if (k > 1)
		{
			int Max2Sum = Sum - MinSum;
			int result;
			if (MaxSum > Max2Sum)  //较大的为最大值
			{
				result = MaxSum;
			}
			else
			{
				result = Max2Sum;
			}
			return result;
		}
		else
		{
			return MaxSum;
		}
	}

	//最小子数组和, 那么求非环形数组最大子数组, 然后减一下
	int minSonArr(vector<int>& arr)
	{
		int Sum = 0;
		int temp = 0;
		int CurSum = 0;
		int MaxSum = 0;
		int MinSum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			//第二种情况，求得最大值为Sum-MinSum
			Sum += arr[i];
			if (temp > 0)
			{
				temp = arr[i];
			}
			else
			{
				temp = temp + arr[i];
			}
			//第一种情况，求得最大值为CurSum
			CurSum += arr[i];
			if (CurSum > MaxSum)
			{
				MaxSum = CurSum;
			}
			if (CurSum < 0)
			{
				CurSum = 0;
			}
		}
		return accumulate(arr.begin(), arr.end(), 0) - MaxSum;
	}

public:
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		int arrMax = *max_element(arr.begin(), arr.end());
		if (arrMax < 0) return 0;
		else
		{
			int MOD = 1000000007;
			int arrSum = accumulate(arr.begin(), arr.end(), 0);
			if (arrSum > 0)
			{
				long long mul1 = arrSum;
				int minSum = minSonArr(arr);
				mul1 = mul1 * (long long)k - minSum;
				mul1 %= MOD;

				int res1 = (int)mul1;
				int res2 = maxCircleSonArr(arr, k);
				return max(res1, res2);
			}
			else
			{
				return maxCircleSonArr(arr, k);
			}
		}
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> arr01 = { 1, 2 };
	cout << s->kConcatenationMaxSum(arr01, 3) << endl;
	vector<int> arr02 = { 1, -2, 1 };
	cout << s->kConcatenationMaxSum(arr02, 5) << endl;

	vector<int> arr1 = { 1, -1 };
	cout << s->kConcatenationMaxSum(arr1, 1) << endl;

	vector<int> arr2 = { -5,-2,0,0,3,9,-2,-5,4 };
	cout << s->kConcatenationMaxSum(arr2, 5) << endl;
	return 0;
}
