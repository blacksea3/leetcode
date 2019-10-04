#include "public.h"

//88ms, 93.39%
//̰���㷨, ����С�����˳���

class Solution {
private:
	//����: ����Ը߶�����, �������������
	/*std::sort�����ڱȽϵĹ����ж�ͬһ�����ݽ��ж�αȽϣ����뱣֤ͬһ�����ݶ�αȽϽ����һ�µġ����磺

��lhsΪItemDesc{ 0, "hello" },��rhsΪItemDesc{ 0, "hellx" },����true���ڶ��αȽϲ���˳�򽻻��󣬼�ItemDesc{ 0, "hellx" },��rhsΪItemDesc{ 0, "hello" },��Ӧ�÷���false��

���޷���֤��һ�㡣���c++ std::sort�������þ������ֵ�invalidate operator<����ԭ���Լ��������*/
	static bool msort(const vector<int>& p1, const vector<int>& p2)
	{
		if (p1[0] < p2[0]) return true;
		else if (p1[0] > p2[0]) return false;
		else return p1[1] > p2[1];
	}

public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int psize = people.size();
		
		/*
		vector<pair<int, int>> cpy;
		for (auto& p : people)
		{
			cpy.push_back(pair<int, int>{p[0], p[1]});
		}
		
		sort(cpy.begin(), cpy.end(), msort);*/

		sort(people.begin(), people.end(), msort);
		vector<vector<int>> res(psize);

		for (auto& p : people)
		{
			int count = p[1];
			for (int loc = 0; loc < psize; ++loc)
			{
				if (res[loc].empty())
				{
					if (count == 0)
					{
						res[loc] = { p[0], p[1]};
						break;
					}
					else count--;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> people = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	auto res = s->reconstructQueue(people);
	return 0;
}
*/
