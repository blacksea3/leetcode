#include "public.h"

//
//��sort, Ȼ���¼��/��ǰ׺
//��������Ϸ�

class Solution {
private:
	static bool msort(string const& s1, string const& s2)
	{
		int sliceCount1 = 0;
		int sliceCount2 = 0;
		for (auto& iters1 : s1)
		{
			if (iters1 == '/') sliceCount1++;
		}
		for (auto& iters2 : s2)
		{
			if (iters2 == '/') sliceCount2++;
		}
		return sliceCount1 < sliceCount2;
	}

public:
	vector<string> removeSubfolders(vector<string>& folder) {
		unordered_set<string> parent;   //��ź�/��ǰ׺
		vector<string> res;

		//�ȼ�б����ĩβ
		for (auto& f : folder) f.push_back('/');

		sort(folder.begin(), folder.end(), msort);

		for (auto& f : folder)
		{
			//���folder
			int pIndex = 0;
			int fSize = f.size();
			bool isSon = false;
			while (pIndex < fSize)
			{
				if (f[pIndex] == '/')
				{
					string temp = f.substr(0, pIndex + 1);
					if (parent.find(temp) != parent.end())
					{
						isSon = true;
						break;
					}
				}
				pIndex++;
			}
			if (!isSon)
			{
				parent.insert(f);
				f.pop_back();
				res.emplace_back(f);
			}
		}
		return res;
	}
};
