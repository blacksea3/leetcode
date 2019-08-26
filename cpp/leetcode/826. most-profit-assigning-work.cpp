#include "public.h"

//236ms, 24.39%
//����ջ, ����һ��difficulty: profit��, Ȼ��worker�������ֲ���>=difficulty�����difficulty, ����profit��OK

class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		map<int, int, greater<int>> m;
		for (int i = 0; i < difficulty.size(); ++i)
		{
			if (m.find(difficulty[i]) == m.end()) m[difficulty[i]] = profit[i];
			else m[difficulty[i]] = max(profit[i], m[difficulty[i]]);
		}

		//����ջ
		vector<int> v_pro;
		vector<int> v_diff;

		for (auto& im : m)
		{
			while (!v_pro.empty() && v_pro[v_pro.size() - 1] < im.second)
			{
				v_pro.pop_back();
				v_diff.pop_back();
			}
			v_pro.push_back(im.second);
			v_diff.push_back(im.first);
		}
		//��תʹ��vp.first��������
		reverse(v_pro.begin(), v_pro.end());
		reverse(v_diff.begin(), v_diff.end());

		//��ζ��ֲ���
		int res = 0;
		for (int i = 0; i < worker.size(); ++i)
		{
			vector<int>::iterator iter = upper_bound(v_diff.begin(), v_diff.end(), worker[i]);
			if (iter == v_diff.begin()) continue;
			else
			{
				int absloc = iter - v_diff.begin() - 1;
				res += v_pro[absloc];
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> difficulty = { 68,35,52,47,86 };
	vector<int> profit = { 67,17,1,81,3 };
	vector<int> worker = { 92,10,85,84,82 };
	cout << s->maxProfitAssignment(difficulty, profit, worker);
	return 0;
}
*/
