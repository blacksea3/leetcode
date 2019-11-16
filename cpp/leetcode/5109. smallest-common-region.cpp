#include "public.h"

//
//多叉树找两个节点的最近公共祖先

class Solution {
public:
	string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
		unordered_map<string, string> rela;
		for (auto& r : regions)
		{
			for (int i = 1; i < r.size(); ++i)
			{
				rela[r[i]] = r[0];
			}
		}

		//一起往上找

		unordered_set<string> us;
		us.insert(region1);
		us.insert(region2);
		string pre1 = region1;
		string pre2 = region2;

		while (true)
		{
			string par1 = "";
			if (rela.find(pre1) != rela.end())
			{
				par1 = rela[pre1];
			}
			string par2 = "";
			if (rela.find(pre2) != rela.end())
			{
				par2 = rela[pre2];
			}

			if (par1 != "" && us.find(par1) != us.end())
				return par1;
			else
			{
				us.insert(par1);
				pre1 = par1;
			}
				
			if (par2 != "" && us.find(par2) != us.end())
				return par2;
			else
			{
				us.insert(par2);
				pre2 = par2;
			}
				
		}
		return "duMP";
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<string>> regions = { {"Earth","North America","South America"},{"North America","United States","Canada"},{"United States","New York","Boston"},{"Canada","Ontario","Quebec"},{"South America","Brazil"} };
	cout << s->findSmallestRegion(regions, "Quebec", "New York");
	return 0;
}
*/
