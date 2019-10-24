#include "public.h"
#include "estimateFuncTime.hpp"

using namespace std;

int recuBS(const vector<int>& arr, int left, int right, int tar)
{
	if (left > right) return left - 1;
	else
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == tar) return mid;
		else if (arr[mid] > tar) return recuBS(arr, left, mid - 1, tar);
		else return recuBS(arr, mid + 1, right, tar);
	}
}

void recuBSInterface(const vector<int>& arr, int tar)
{
	cout << "res:" << recuBS(arr, 0, arr.size() - 1, tar) << endl;
}

int iterBS(const vector<int>& arr, int tar)
{
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == tar) return mid;
		else if (arr[mid] > tar) right = mid - 1;
		else left = mid + 1;
	}
	return left - 1;
}

void iterBSInterface(const vector<int>& arr, int tar)
{
	cout << "res:" << iterBS(arr, tar) << endl;
}

void BinarySearchTest()
{
	vector<int> arr(100000);
	for (int i = 0; i < 100000; ++i) arr[i] = 2 * i;
	int count = 5;
	cout << "recu binary search " << count << " times" << endl;
	estimateFuncTimeLoop(count, recuBSInterface, arr, 5000);
	cout << "iter binary search " << count << " times" << endl;
	estimateFuncTimeLoop(count, iterBSInterface, arr, 5000);
}

