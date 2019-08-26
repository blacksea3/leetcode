#include "public.h"

//68ms, 78.99%
//Ä£Äâ

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int loc1 = 0;
		int loc2 = 0;
		int left;
		int right;

		vector<vector<int>> res;

		while (loc1 < A.size() && loc2 < B.size())
		{
			if (A[loc1][0] <= B[loc2][0])
			{
				if (A[loc1][1] >= B[loc2][0])
				{
					left = B[loc2][0];
					if (A[loc1][1] < B[loc2][1])
					{
						right = A[loc1][1];
						res.push_back({ left, right });
						loc1++;
					}
					else
					{
						right = B[loc2][1];
						res.push_back({ left, right });
						loc2++;
					}
				}
				else
				{
					loc1++;
				}
			}
			else
			{
				if (A[loc1][0] <= B[loc2][1])
				{
					left = A[loc1][0];
					if (A[loc1][1] >= B[loc2][1])
					{
						right = B[loc2][1];
						res.push_back({ left, right });
						loc2++;
					}
					else
					{
						right = A[loc1][1];
						res.push_back({ left, right });
						loc1++;
					}
				}
				else
				{
					loc2++;
				}
			}
		}
		return res;
	}
};
