#include "public.h"

//
//���鼯, ��pairs����, Ȼ�󵥶�����

class Solution {
private:
	unordered_map<int, int> um;

	void init_2(int size)
	{
		for (int index = 0; index < size; ++index)
		{
			um[index] = index;
		}
	}


	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}

	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int pSize = s.size();
		string res(pSize, '!');
		init_2(pSize);

		for (auto& p : pairs)
		{
			Merge(p[0], p[1]);
		}

		//ͳ��������һ���ֵ
		vector<bool> issearched(pSize, false);
		unordered_map<int, set<int>> fathers;
		for (int index = 0; index < pSize; ++index)
		{
			fathers[GetFather(um[index])].insert(index);
		}

		//�޸��ַ���
		for (auto& allV : fathers)
		{

			set<int> targetindexs = allV.second;
			//ͳ��
			vector<int> v(26, 0);
			for (auto& iter_index : targetindexs) v[s[iter_index] - 'a']++;
			//���
			int prechar = 0;
			for (auto& iter_index : targetindexs)
			{
				//cout << iter_index << endl;
				while (v[prechar] == 0) prechar++;
				//cout << prechar << endl;
				res[iter_index] = prechar + 'a';
				v[prechar]--;
				//cout << res << endl;
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> pairs = { {0, 3}, {1,2} };
	auto res = s->smallestStringWithSwaps("dcab", pairs);
	vector<vector<int>> pairs2 = { {0, 3}, {1,2}, {0,2} };
	auto res2 = s->smallestStringWithSwaps("dcab", pairs2);
	return 0;
}
*/
