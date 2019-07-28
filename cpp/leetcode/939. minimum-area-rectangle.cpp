#include "public.h"

//844ms, 34.61%
//ͳ������, Ȼ��Ѱ�ҿ��ܵľ���

class Solution {
private:
	int get_minabsrow(vector<int>& c1, vector<int>& c2, int r)
	{
		int res = INT_MAX;

		for (auto& ic1 : c1)
		{
			if (find(c2.begin(), c2.end(), ic1) != c2.end())
			{
				if (ic1 != r) res = min(res, abs(r - ic1));
			}
		}
		return res;
	}

public:
	int minAreaRect(vector<vector<int>>& points) {
		vector<vector<int>> r(40001, vector<int>{});
		vector<vector<int>> c(40001, vector<int>{});

		for (auto& p : points)
		{
			r[p[0]].push_back(p[1]);
			c[p[1]].push_back(p[0]);
		}

		int res = INT_MAX;
		//������, �ҵ���ͬ�е�, ����������û�б��ͬ�е�, ��ô��OJBK��
		for (int ir = 0; ir < 40001; ++ir)
		{
			if (r[ir].size() >= 2)
			{
				//����ϲ�ѯ
				for (int left = 0; left < r[ir].size() - 1; ++left)
				{
					for (int right = left + 1; right < r[ir].size(); ++right)
					{
						int temp = get_minabsrow(c[r[ir][left]], c[r[ir][right]], ir);
						if (temp != INT_MAX) res = min(res, temp*abs(r[ir][left] - r[ir][right]));
					}
				}
			}
		}
		return (res == INT_MAX) ? 0 : res;
	}
};
