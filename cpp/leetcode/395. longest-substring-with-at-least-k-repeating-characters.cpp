#include "public.h"

//4ms, 97.32%
//����:
//���������ĵݹ麯��: ͳ�Ƶ�ǰ��Χ�ڵ��ַ�Ƶ��, Ȼ��������ҽض϶���ĳ���Ƶ��С��k���ַ�, ���ض����ַ�����С��k��ֱ�ӷ���0
//   ����: ���м�����λ�ý����ж�, ����м�ĳ���ַ�����Ƶ��С��k, ��ض���, return �����Ӵ��Ľ�����ֵ
//   ����м��ַ�Ƶ�������ڵ���k, �򷵻ص�ǰ�ַ�������

class Solution {
private:
	int recu(const string& s, int start, int end, int k)
	{
		if (end - start + 1 < k) return 0;
		//ͳ��Ƶ��
		vector<int> nums(26, 0);
		for (int i = start; i <= end; ++i)
		{
			nums[s[i] - 'a']++;
		}

		//�ض�
		while ((end - start + 1 >= k) && (nums[s[start] - 'a'] < k)) start++;
		while ((end - start + 1 >= k) && (nums[s[end] - 'a'] < k)) end--;
		if (end - start + 1 < k) return 0;

		//�м��ж�
		for (int i = start + 1; i < end; ++i)
		{
			if (nums[s[i] - 'a'] < k) return max(recu(s, start, i - 1, k), recu(s, i + 1, end, k));
		}
		return end - start + 1;
	}

public:
	int longestSubstring(string s, int k) {
		if ((k == 0) || (s.size() < k)) return 0;
		else return recu(s, 0, s.size() - 1, k);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->longestSubstring("aaabb", 3);
	return 0;
}*/
