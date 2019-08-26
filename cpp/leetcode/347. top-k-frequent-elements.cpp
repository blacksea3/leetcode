#include "public.h"

//24ms, 92.60%
//堆排序
//先对nums各个数字的出现频率计数, 然后:
// 利用multimap: 内部实现是二叉树, 可自动排序, 使用升序排序, 并限制其元素个数为k
// 若当前元素频率计数>set内元素频率计数, 则删除set顶元素, 并添加当前元素
//整体复杂度为O(nlongn)

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
