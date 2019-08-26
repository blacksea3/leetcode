#include "public.h"

//8ms, 87.02%
//ͳ�Ƹ�����ĸ�����һ�γ���λ��, Ȼ��ɨ��S, ͨ����ǰ��ĸ�����һ�γ���λ�õó���ǰ����̵ĳ���, ����Ѿ����ֵ���ĸ�����һ�γ���λ��<=��ǰλ��, ��ôOK, res++;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		//vector<int> first(26, -1);
		vector<int> end(26, 999);

		/*
		for (int i = 0; i < S.size(); ++i)
		{
			if (first[S[i]-'a'] == -1) first[S[i]-'a'] = i;
		}
		*/
		//����ɨһ��
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (end[S[i] - 'a'] == 999) end[S[i] - 'a'] = i;
		}

		vector<int> res;
		int lastright = -1;
		int prelast = -1;

		for (int i = 0; i < S.size(); ++i)
		{
			prelast = max(prelast, end[S[i] - 'a']);
			if (prelast == i)
			{
				res.push_back(i - lastright);
				lastright = i;
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->partitionLabels("ababcbacadefegdehijhklij");
	return 0;
}
*/
