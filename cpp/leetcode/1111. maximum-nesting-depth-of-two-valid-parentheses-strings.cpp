#include "public.h"

//28ms, 96.09%
//ע�⵽seq����Ч����
//��ôֻ��Ҫ��Ƕ�����'ƽ��'����
//��˼�¼��ǰ������������, 
//���Ŀǰ����������������1, ֮�������������������������0, ż���������Ÿ�1
//���Ŀǰ��������, �������һ��������, ��ʣ�����������������1, ż�������0  (����һ�������෴)

class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> res(seq.size());
		bool is_1 = true;
		for (int loc = 0; loc < seq.size(); ++loc)
		{
			if (seq[loc] == '(')
			{
				res[loc] = is_1;
				is_1 = !is_1;
				//if (is_1) res[loc] = 0;
				//else res[loc] = 1;
			}
			else
			{
				res[loc] = !is_1;
				is_1 = !is_1;
				//if (is_1) res[loc] = 1;
				//else res[loc] = 0;
			}
		}
		return res;
	}
};

