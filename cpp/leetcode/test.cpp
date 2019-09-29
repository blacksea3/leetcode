#include "BinaryTree.h"
#include "listnode.h"

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> um;
		for (auto& a : arr) um[a]++;

		unordered_set<int> ocr;

		for (auto& iterum : um)
		{
			if (ocr.find(iterum.second) == ocr.end())
			{
				ocr.insert(iterum.second);
			}
			else return false;
		}
		return true;
	}
};

/*
int main()
{
	Solution*s = new Solution();
	return 0;
}
*/
