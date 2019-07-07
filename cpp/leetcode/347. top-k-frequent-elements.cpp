#include "public.h"

//24ms, 92.60%
//������
//�ȶ�nums�������ֵĳ���Ƶ�ʼ���, Ȼ��:
// ����multimap: �ڲ�ʵ���Ƕ�����, ���Զ�����, ʹ����������, ��������Ԫ�ظ���Ϊk
// ����ǰԪ��Ƶ�ʼ���>set��Ԫ��Ƶ�ʼ���, ��ɾ��set��Ԫ��, ����ӵ�ǰԪ��
//���帴�Ӷ�ΪO(nlongn)

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		for (const auto& num : nums) um[num]++;

		multimap<int, int> m_map;
		for (const auto& ium : um)
		{
			if (m_map.size() < k) m_map.insert(pair<int, int>{ium.second, ium.first});
			else
			{
				if (ium.second > m_map.begin()->first)
				{
					m_map.erase(m_map.begin());
					m_map.insert(pair<int, int>{ium.second, ium.first});
				}
			}
		}

		vector<int> res;
		for (const auto& imm : m_map) res.push_back(imm.second);
		reverse(res.begin(), res.end());
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> nums = { 1,1,1,2,2,3 };
	vector<int> nums = { 1,2 };
	auto res = s->topKFrequent(nums, 2);
	return 0;
}
*/
