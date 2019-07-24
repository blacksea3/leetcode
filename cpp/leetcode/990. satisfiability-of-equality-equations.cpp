#include "public.h"

//4ms, 98.92%
//���鼯
//��vector��ʾ
//��һ��vector, ������unordered_set��ĸ��
//���о���ͬ��ĸ: ����ͨ���鼯���� 
//���о���ͬ��ĸ, ����ĸ��ͬ, ������/һ����һ������/���ڶ����ڲ�ͬ��, ����; ���ڵ�������ͬ�����군�� :)

class Solution {
private:
	int findloc(const vector<unordered_set<int>>& vus, const int& val)
	{
		for (int i = 0; i < vus.size(); ++i)
		{
			if (vus[i].find(val) != vus[i].end()) return i;
		}
		return -1;
	}

public:
	bool equationsPossible(vector<string>& equations) {
		vector<unordered_set<int>> vus;

		//���ҵ��ں�
		for (auto& e : equations)
		{
			if (e[1] == '=')
			{
				int loc1 = findloc(vus, e[0]);
				int loc2 = findloc(vus, e[3]);
				if (loc1 == -1 && loc2 == -1)
				{
					vus.push_back(unordered_set<int>{e[0], e[3]});
				}
				else if (loc1 == -1)
				{
					vus[loc2].insert(e[0]);
				}
				else if (loc2 == -1)
				{
					vus[loc1].insert(e[3]);
				}
				else
				{
					if (loc1 == loc2) continue;
					else
					{
						//merge
						for (auto& val : vus[loc2])
						{
							vus[loc1].insert(val);
						}
						vus.erase(vus.begin() + loc2);
					}
				}
			}
		}
		//���Ҳ����ں�
		for (auto& e : equations)
		{
			if (e[1] == '!')
			{
				if (e[0] == e[3]) return false;

				int loc1 = findloc(vus, e[0]);
				int loc2 = findloc(vus, e[3]);
				if (!(loc1 == -1 || loc2 == -1 || loc1 != loc2))
				{
					return false;
				}
			}
		}
		return true;
	}
};
