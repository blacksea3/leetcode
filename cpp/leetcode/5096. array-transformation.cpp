#include "public.h"

//
//±©Á¦ÑÝ±ä

class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		while (true)
		{
			vector<int> temp = arr;
			temp[0] = arr[0];
			for (int i = 1; i < arr.size() - 1; ++i)
			{
				if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
				{
					temp[i] = arr[i] - 1;
				}
				else if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
				{
					temp[i] = arr[i] + 1;
				}
				else temp[i] = arr[i];
			}
			temp[arr.size() - 1] = arr[arr.size() - 1];
			if (temp == arr) break;
			else arr = temp;
		}
		return arr; //dump
	}
};
